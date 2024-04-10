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
    int arr[5][n+5];
    for(int i=0;i<=2;i++){
        for(int j=0;j<n;j++)cin>>arr[i][j];
    }
    int ans[n+5];
    ans[0]=arr[0][0];
    ans[2]=ans[0];
    ans[n]=ans[0];
    for(int i=1;i<n;i++){
        int now=0;
        //cout<<ans[i-1]<<" "<<ans[i+1]<<endl;
        while(arr[now][i]==ans[i-1]||arr[now][i]==ans[i+1])now++;
        ans[i]=arr[now][i];
        if(i!=n-2)ans[i+2]=arr[now][i];
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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