#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define int long long
main(){
    int n,m;
    cin>>n>>m;
    int arr[n+5];
    int modplus[m+5];
    for(int i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+1+n);
    long long ans[n+5];
    for(int i=0;i<=m;i++){modplus[i]=0;}
    ans[0]=0;
    for(int i=1;i<=n;i++){
        modplus[i%m]+=arr[i];
        ans[i]=ans[i-1]+modplus[i%m];
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}