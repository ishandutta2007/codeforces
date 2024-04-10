#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define mid ((l+r)/2)
#define int long long
using namespace std;
void solve(){
    int n,m;cin>>n>>m;
    int arr[n+5],price[m+5],ans=0,fen[m+5];
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=m;i++)cin>>price[i];
    sort(arr+1,arr+1+n);
    int l=1,r=n;
    while(l<=arr[r]&&l<=m&&r>=1){
        ans+=price[l];
        l++;r--;
    }
    while(r>=1)ans+=price[arr[r--]];
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}