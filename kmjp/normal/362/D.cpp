#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
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
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int N,M,P,Q;
int X[100001],Y[100001];
ll L[100001];

const int ufmax=1000001;
int ufpar[ufmax],ufrank[ufmax];
void UF_init(){int i; FOR(i,ufmax) { ufpar[i]=i; ufrank[i]=0; } }
int UF_find(int x) {    return (ufpar[x]==x)?(x):(ufpar[x] = UF_find(ufpar[x]));}
void UF_unite(int x,int y) {
    x = UF_find(x); y = UF_find(y);
    if(x==y) return;
    if(ufrank[x]<ufrank[y]) ufpar[x]=y;
    else {ufpar[y]=x; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
}

map<int,ll> MM;
set<pair<ll,int> > S;
int rep=-1;

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M>>P>>Q;
    UF_init();
    FOR(i,M) {
        cin>>X[i]>>Y[i]>>L[i];
        UF_unite(X[i],Y[i]);
    }
    FOR(i,N) MM[UF_find(i+1)]=0;
    FOR(i,N) if(i+1!=UF_find(i+1)) rep=i+1;
    FOR(i,M) MM[UF_find(X[i])]+=L[i];
    
    if((int)MM.size()-P>Q) return _P("NO\n");
    if(MM.size()<Q) return _P("NO\n");
    if(MM.size()==N && P>0 && N==Q) return _P("NO\n");
    ITR(it,MM) S.insert(make_pair(it->second,it->first));
    
    _P("YES\n");
    FOR(i,P) {
        if(S.size()==Q) {
            _P("%d %d\n",rep,UF_find(rep));
        }
        else {
            set<pair<ll,int> >::iterator itr=S.begin();
            pair<ll,int> p1=*itr++;
            pair<ll,int> p2=*itr;
            S.erase(p1);
            S.erase(p2);
            S.insert(make_pair(p1.first+p2.first+min(1000000000LL,p1.first+p2.first+1),p1.second));
            _P("%d %d\n",p1.second,p2.second);
            UF_unite(p1.second,p2.second);
            if(p1.second!=UF_find(p1.second)) rep=p1.second;
            if(p2.second!=UF_find(p2.second)) rep=p2.second;
        }
        
    }
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}