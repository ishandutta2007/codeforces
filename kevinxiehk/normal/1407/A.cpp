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
    for(int i=0;i<n;i++)cin>>arr[i];
    queue<int>ans;
    for(int i=0;i<n;i++){
        if(arr[i]==0)ans.push(0);
        else if(i<n-1&&arr[i+1]==1){ans.push(1);ans.push(1);i++;}
    }
    cout<<ans.size()<<endl;
    while(!ans.empty()){cout<<ans.front()<<" ";ans.pop();}
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