#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n,k,t;
vector<pi> g[25];
int used[25];
int lim,cnt;
bool dfs(int v,int sum){
    ++cnt;
    if(cnt==t) return true;
    if(v==n) return false;
    REP(i,g[v].size()){
        pi& e=g[v][i];
        if(used[e.fr] || sum+e.sc>=lim) continue;
        used[e.fr]=1;
        if(dfs(v+1,sum+e.sc)) return true;
        used[e.fr]=0;
    }
    --cnt;
    if(dfs(v+1,sum)) return true;
    return false;
}

int main(){
    scanf("%d%d%d",&n,&k,&t);
    REP(i,k){
        int a,b,r;scanf("%d%d%d",&a,&b,&r);--a;--b;
        g[a].pb(mp(b,r));
    }
    int lb=0,ub=1000*20+5;
    while(ub-lb>1){
        int md=(ub+lb)>>1;
        lim=md;cnt=0;
        memset(used,0,sizeof(used));
        if(dfs(0,0)) ub=md;
        else lb=md;
    }
    printf("%d\n",lb);
    return 0;
}