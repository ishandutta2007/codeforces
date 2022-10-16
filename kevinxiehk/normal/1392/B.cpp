#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    k%=2;
    if(k==0)k=2;
    int arr[n+5];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<k;i++){
        int ma=-9999999999;
        for(int j=0;j<n;j++)ma=max(ma,arr[j]);
        for(int j=0;j<n;j++)arr[j]=ma-arr[j];
    }
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
    return;
}
main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}