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
    bool can=true;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n-1;i++){
        if(arr[i+1]>=arr[i])can=false;
    }
    if(can)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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