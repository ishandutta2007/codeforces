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

int N,M;
pair<int, pair<int,int> > D[4001];
map<int,int> mat[1001];

int dpdp() {
    int mx[1001];
    int i,x;
    FOR(i,N) mx[i]=1<<29;
    mx[0]=0;
    
    set<pair<int,int> > S;
    S.insert(make_pair(0,0));
    while(!S.empty()) {
        pair<int,int> p=*S.begin();
        S.erase(p);
        if(p.first>mx[p.second]) continue;
        ITR(it,mat[p.second]) {
            x=max(p.first,it->second);
            if(x<mx[it->first]) {
                mx[it->first]=x;
                S.insert(make_pair(x,it->first));
            }
        }
    }
    return mx[N-1];
}

void solve() {
    int f,i,j,k,l,x,y,r;
    
    cin>>N>>M;
    FOR(i,M) {
        cin>>x>>y>>l>>r;
        x--;
        y--;
        D[i].first=r;
        D[i].second.first=l;
        D[i].second.second=x*10000+y;
    }
    
    sort(D,D+M);
    int res=0;
    for(i=M-1;i>=0;i--) {
        x=D[i].second.second/10000;
        y=D[i].second.second%10000;
        if(mat[x].find(y)==mat[x].end() || mat[x][y]>D[i].second.first)
            mat[x][y]=mat[y][x]=D[i].second.first;
        res=max(res,D[i].first-dpdp()+1);
    }
    
    
    if(res) return _P("%d\n",res);
    _P("Nice work, Dima!\n");
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}