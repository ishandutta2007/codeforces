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
    int arr[40];
    arr[1]=1;
    for(int i=2;i<=31;i++)arr[i]=arr[i-1]*2+1;
    int sum[40];
    for(int i=1;i<=31;i++){
        sum[i]=(arr[i]*(arr[i]+1))/2;
    }
    //for(int i=1;i<=30;i++)cout<<arr[i]<<" "<<sum[i]<<endl;
    sum[0]=0;
    int ans=0;
    while(sum[ans+1]<=n-sum[ans]){
        n-=sum[ans];
        ans++;
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