#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define dump(x) cerr<<#x<<" = "<<x<<endl
#define prl cerr<<"LINE:"<<__LINE__<<" is called"<<endl
using namespace std;
const int INF=5e8;
typedef pair<int,int> pi;
int n;
vector<pi> g[200005];

int begin[200005],end[200005];
int cnt;
int depth[200005];
void dfs(int v,int p,int dep=0){
    begin[v]=cnt++;
    depth[v]=dep;
    REP(i,g[v].size()){
        pi& e=g[v][i];
        if(e.fr==p) continue;
        dfs(e.fr,v,dep+1);
    }
    end[v]=cnt;
}
int sum[200005];
int all=0;
int cost[200005];
int main(){
    scanf("%d",&n);
    REP(i,n-1){
        int a,b;scanf("%d%d",&a,&b);--a;--b;
        g[a].pb(mp(b,1));
        g[b].pb(mp(a,-1));
    }
    cnt=0;
    dfs(0,-1);
    REP(i,n) REP(j,g[i].size()){
        pi& e=g[i][j];
        if(depth[i]<depth[e.fr]){
            if(e.sc==1){
                ++sum[begin[e.fr]];
                --sum[end[e.fr]];
            }else{
                --sum[begin[e.fr]];
                ++sum[end[e.fr]];
                ++all;
            }
        }
    }
    REP(i,n) sum[i+1]+=sum[i];
    REP(i,n) cost[i]=all+sum[begin[i]];
    int mini=INF;
    mini=*min_element(cost,cost+n);
    printf("%d\n",mini);
    int first=1;
    REP(i,n) if(cost[i]==mini){
        if(first==0) putchar(' ');
        first=0;
        printf("%d",i+1);
    }
    putchar('\n');
    return 0;
}