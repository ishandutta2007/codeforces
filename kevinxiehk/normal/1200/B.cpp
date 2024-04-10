#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    int arr[n+5];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        if(m<arr[i+1]-arr[i]-k){cout<<"NO"<<endl;return;}
        m-=max(arr[i+1]-arr[i]-k,-1*arr[i]);
    }
    cout<<"YES"<<endl;
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}