#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=5e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
struct edge{int a,b,c;};
vector<int>g[mn];
ll num[10][10];
int v[11];
int ap[mn];
ll h[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n,m,k;
    cin>>n>>m>>k;
    vector<edge>e;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e.push_back({a,b,c});
    }
    for(int i=1;i<=n;i++)h[i]=rngll();
    sort(e.begin(),e.end(),[](auto a,auto b){return a.c<b.c;});
    for(edge ee:e)g[ee.a].push_back(ee.b);
    for(int i=1;i<=k;i++){
        for(int j=0;j<i;j++){
            memset(ap,0,sizeof(ap));
            for(int l=1;l<=n;l++)if(g[l].size()==i){
                    ap[l]--;
                    ap[g[l][j]]++;
                }
            for(int l=1;l<=n;l++){
                if(ap[l]>=2){num[i][j]=-1;break;}
                if(ap[l])num[i][j]^=h[l];
            }
        }
    }
    int ans=0;
    for(;!v[k+1];){
        ll sum=0;
        bool ded=0;
        for(int i=1;i<=k;i++)if(num[i][v[i]]==-1)ded=1;
        if(!ded){
            for(int i=1;i<=k;i++)sum^=num[i][v[i]];
            if(sum==0)ans++;
        }
        v[1]++;
        for(int i=1;v[i]>=i;i++)v[i]-=i,v[i+1]++;
    }
    printf("%d",ans);
}