#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++){
        int now=0;
        while(pow(2,now+1)<=arr[i])now++;
        arr[i]=now;
    }
    int pre[35];
    for(int i=0;i<=30;i++)pre[i]=0;
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=pre[arr[i]];
        pre[arr[i]]++;
    }
    cout<<ans<<endl;
    return;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
 
    cin>>t;
    
    while(t--)solve();
    return 0;
}