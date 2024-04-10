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
const int mn=3e5+10;
const ll mod=1e9+7;

int k[mn];
ll c[mn];

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
        for(int i=0;i<n;i++)cin>>k[i];
        for(int i=1;i<=m;i++)cin>>c[i];
        sort(k,k+n);
        ll ans=0;
        for(int i=0;i<n;i++)ans+=c[k[i]];
        //cerr<<ans;
        priority_queue<int>pq;
        for(int i=m,j=n-1;i;i--){
            while(j>=0&&k[j]>i)pq.push(k[j--]);
            if(!pq.size())continue;
            int x=pq.top();
            pq.pop();
            ans+=c[i]-c[x];
            pq.push(i);
        }
        printf("%lld\n",ans);
    }
}