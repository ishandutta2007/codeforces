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

int N,M,K,W;
string S[1001];
int cost[1001][1001];
int mcost[1001],tar[1001];
int vis[2001];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M>>K>>W;
    FOR(i,K) {
        FOR(y,N) {
            string s;
            cin>>s;
            S[i]+=s;
        }
    }
    N=N*M;
    FOR(x,K) for(y=x+1;y<K;y++) {
        l=0;
        FOR(i,N) l+=S[x][i]!=S[y][i];
        cost[x][y]=cost[y][x]=l*W;
    }
    
    FOR(x,K) mcost[x]=N;
    
    pair<int,int> R[2001];
    x=0;
    ll ret=0;
    while(1) {
        int id=-1;
        FOR(i,K) if(vis[i]==0 && (id==-1 || mcost[i]<mcost[id])) id=i;
        if(id==-1) break;
        R[x].first=id+1;
        R[x].second=tar[id];
        x++;
        ret+=mcost[id];
        vis[id]=1;
        FOR(i,K) if(vis[i]==0 && mcost[i]>cost[id][i]) mcost[i]=cost[id][i],tar[i]=id+1;
    }
    
    _P("%lld\n",ret);
    FOR(i,K) _P("%d %d\n",R[i].first,R[i].second);
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}