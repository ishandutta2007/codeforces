#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

class UF {
    public:
    static const int ufmax=100002;
    int ufpar[ufmax],ufrank[ufmax];
    UF() { init();}
    void init(){int i; FOR(i,ufmax) { ufpar[i]=i; ufrank[i]=0; } }
    int find(int x) {   return (ufpar[x]==x)?(x):(ufpar[x] = find(ufpar[x]));}
    int operator[](int x) {return find(x);}
    void unite(int x,int y) {
        x = find(x); y = find(y);
        if(x==y) return;
        if(ufrank[x]<ufrank[y]) ufpar[x]=y;
        else {ufpar[y]=x; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
    }
};

int N,M;
int A[100001],rev[100001];
pair<int,int> P[100001];
vector<int> E[100001];
int num[100001];
double ret=0;
UF uf;
void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M;
    
    uf.init();
    FOR(i,N) {
        cin>>x;
        P[i]=make_pair(x,i);
        num[i]=0;
    }
    sort(P,P+N);
    reverse(P,P+N);
    FOR(i,N) rev[P[i].second]=i;
    
    FOR(i,M) {
        cin>>x>>y;
        E[x-1].push_back(y-1);
        E[y-1].push_back(x-1);
    }
    FOR(i,N) {
        int id=P[i].second;
        set<int> S;
        int nt=0;
        FOR(j,E[id].size()) if(rev[E[id][j]]<i) S.insert(uf[E[id][j]]);
        ITR(it,S) ret += P[i].first*1LL*num[*it]*nt, nt+=num[*it];
        ret += nt*(ll)P[i].first;
        ITR(it,S) uf.unite(id,*it);
        num[uf[id]]=nt+1;
    }
    
    
    _P("%.12lf\n",2*ret/(N*(N-1.0)));
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}