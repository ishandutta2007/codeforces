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
const ll mod=998244353;

int a[mn];
ll w[mn],sub[mn];
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
        int n;
        cin>>n;
        ll ans=0;
        for(int i=0;i<=n;i++)a[i]=w[i]=sub[i]=0;
        for(int i=1;i<=n;i++)cin>>w[i],ans+=w[i];
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            a[x]++,a[y]++;
        }
        vector<ll>v;
        for(int i=1;i<=n;i++)for(int j=0;j<a[i]-1;j++)v.push_back(w[i]);
        sort(v.begin(),v.end(),greater<ll>());
        printf("%lld ",ans);
        for(ll x:v)printf("%lld ",ans+=x);
        printf("\n");
    }
}