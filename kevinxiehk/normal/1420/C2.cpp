#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
void solve(){
    int n,q;
    cin>>n>>q;
    int arr[n+5];
    for(int i=1;i<=n;i++)cin>>arr[i];
    arr[0]=0;arr[n+1]=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(arr[i]>arr[i-1]&&arr[i]>arr[i+1])ans+=arr[i];
        else if(arr[i]<arr[i-1]&&arr[i]<arr[i+1])ans-=arr[i];
    }
    cout<<ans<<endl;
    int a,b;
    while(q--){
        cin>>a>>b;
        if(a>b)swap(a,b);
        if(b-a>=3){
            for(int i=max(a-1,1LL);i<=min(a+1,n);i++){
                if(arr[i]>arr[i-1]&&arr[i]>arr[i+1])ans-=arr[i];
                else if(arr[i]<arr[i-1]&&arr[i]<arr[i+1])ans+=arr[i];
            }
            for(int i=max(b-1,1LL);i<=min(b+1,n);i++){
                if(arr[i]>arr[i-1]&&arr[i]>arr[i+1])ans-=arr[i];
                else if(arr[i]<arr[i-1]&&arr[i]<arr[i+1])ans+=arr[i];
            }
            swap(arr[a],arr[b]);
            for(int i=max(a-1,1LL);i<=min(a+1,n);i++){
                if(arr[i]>arr[i-1]&&arr[i]>arr[i+1])ans+=arr[i];
                else if(arr[i]<arr[i-1]&&arr[i]<arr[i+1])ans-=arr[i];
            }
            for(int i=max(b-1,1LL);i<=min(b+1,n);i++){
                if(arr[i]>arr[i-1]&&arr[i]>arr[i+1])ans+=arr[i];
                else if(arr[i]<arr[i-1]&&arr[i]<arr[i+1])ans-=arr[i];
            }
        }
        else{
            for(int i=max(a-1,1LL);i<=min(b+1,n);i++){
                if(arr[i]>arr[i-1]&&arr[i]>arr[i+1])ans-=arr[i];
                else if(arr[i]<arr[i-1]&&arr[i]<arr[i+1])ans+=arr[i];
            }
            swap(arr[a],arr[b]);
            for(int i=max(a-1,1LL);i<=min(b+1,n);i++){
                if(arr[i]>arr[i-1]&&arr[i]>arr[i+1])ans+=arr[i];
                else if(arr[i]<arr[i-1]&&arr[i]<arr[i+1])ans-=arr[i];
            }
        }
        cout<<ans<<endl;
    }
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