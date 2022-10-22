#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mn=1<<16;
const ll mod = 998244353;

ll bit[mn];
void upd(int a,ll b){for(;a<mn;a+=a&-a)bit[a]=min(bit[a],b);}
ll bs(ll b){
    ll cur=0;
    for(int i=1<<15;i;i>>=1){
        if(bit[cur+i]>=b)cur+=i;
    }
    return cur;
}
ll a[mn],r[mn];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],a[i]+=a[i-1];
    memset(bit,0x3f,sizeof(bit));
    ll x;
    cin>>x;
    for(int i=1;i<=n;i++)a[i]-=x*i;
    for(int i=n-1;i>=1;i--){
        upd(i+1,a[i+1]);
        r[i]=bs(a[i-1])+1;
    }
    r[n]=n+1;
    int ans=0;
    int lv=n+1;
    //for(int i=1;i<=n;i++)cerr<<r[i]<<endl;
    for(int i=n;i>=1;i--){
        if(lv>r[i]){
            lv=i;
            ans++;
        }
    }
    printf("%d\n",n-ans);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int tc;
    cin>>tc;
    while(tc--){
        solve();
    }
}