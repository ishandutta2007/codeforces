#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    int ans=0;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1])ans-=(arr[i]-arr[i-1]);
    }
    cout<<ans<<endl;
}
main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}