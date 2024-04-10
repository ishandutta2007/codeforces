#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mn=1e5+10;
const ll mod=1e9+7;
int c[mn];
bool vis[mn];
int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<=n;i++)vis[i]=c[i]=0;
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            c[a]=b;
        }
        int ans=m;
        for(int i=1;i<=n;i++)if(!vis[i]){
            if(c[i]==i){ans--;continue;}
            //cerr<<c[i]<<" "<<ans<<endl;
            vis[i]=1;
            for(int j=c[i];1;j=c[j]){
                vis[j]=1;
                if(j==0)break;
                else if(j==i){
                    ans++;
                    break;
                }
            }
        }
        printf("%d\n",ans);
    }
}