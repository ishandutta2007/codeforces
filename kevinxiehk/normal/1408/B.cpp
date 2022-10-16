#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    int cnt=1;
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[i-1])cnt++;
    }
    if(k==1){
        if(cnt==1)cout<<"1"<<endl;
        else cout<<"-1"<<endl;
        return;
    }
    int ans=1;
    if(cnt<=k){
        cout<<"1"<<endl;
        return;
    }
    cnt-=k;
    ans+=((cnt)/(k-1));
    ans+=((cnt)%(k-1)!=0);
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