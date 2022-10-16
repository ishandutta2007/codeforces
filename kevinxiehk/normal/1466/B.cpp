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
    sort(arr,arr+n);
    set<int>x;
    x.insert(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]&&(i==n-1||arr[i]!=arr[i+1]))arr[i]++;
        x.insert(arr[i]);
    }
    cout<<x.size()<<endl;
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}