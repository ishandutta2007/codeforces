#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
using namespace std;
void solve(){
    int n;cin>>n;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    set<int>s;
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)s.insert(arr[j]-arr[i]);
    cout<<s.size()<<endl;
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}