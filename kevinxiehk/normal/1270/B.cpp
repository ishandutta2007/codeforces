#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
void solve(){
    int n;
    cin>>n;
    int arr[n+5];
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=2;i<=n;i++){
        if(abs(arr[i-1]-arr[i])<=1)continue;
        else {cout<<"YES"<<endl<<i-1<<" "<<i<<endl;return;}
    }
    cout<<"NO"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
}