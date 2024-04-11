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
set<int> okok[1001][1001];
set<int> rev[1001][1001];
int fin[1001][1001];
int cost[1001][1001];
string S[1001];

int dfs(int y,int x) {
    int r=0;
    if(cost[y][x]>=1<<30) {
        _P("Poor Inna!\n");
        exit(0);
    }
    if(cost[y][x]>0) return cost[y][x];
    
    if(okok[y][x].empty()) {
        cost[y][x]=fin[y][x];
    }
    else {
        cost[y][x]=1<<30;
        ITR(it,okok[y][x]) r=max(r,dfs(*it/1000,*it%1000));
        cost[y][x]=1+r;
    }
    
    return cost[y][x];
}

void solve() {
    int f,i,j,k,l,x,y,r,rr=0;
    int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1},ty,tx;
    cin>>N>>M;
    FOR(y,N) cin>>S[y];
    l=0;
    FOR(y,N) FOR(x,M) if(S[y][x]=='D') {
        FOR(i,4) FOR(j,4) FOR(k,4) {
            int x1=x+dx[i],y1=y+dy[i];
            int x2=x1+dx[j],y2=y1+dy[j];
            int x3=x2+dx[k],y3=y2+dy[k];
            if(x1<0 || x1>=M || y1<0 || y1>=N) continue;
            if(x2<0 || x2>=M || y2<0 || y2>=N) continue;
            if(x3<0 || x3>=M || y3<0 || y3>=N) continue;
            if(S[y1][x1]!='I') continue;
            if(S[y2][x2]!='M') continue;
            if(S[y3][x3]!='A') continue;
            l=fin[y][x]=1;
            FOR(r,4) {
                int x4=x3+dx[r],y4=y3+dy[r];
                if(x4<0 || x4>=M || y4<0 || y4>=N) continue;
                if(S[y4][x4]!='D') continue;
                if(y4==y && x4==x) return _P("Poor Inna!\n");
                okok[y][x].insert(y4*1000+x4);
                rev[y4][x4].insert(y*1000+x);
            }
            
        }
    }
    if(l==0) return _P("Poor Dima!\n");
    FOR(y,N) FOR(x,M) if(S[y][x]=='D') {
        if(cost[y][x]) continue;
        l=max(l,dfs(y,x));
        if(l>=1<<30) return _P("Poor Inna!\n");
    }
    
    _P("%d\n",l);

}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}