#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
int cnt(int a){
    int ans=0;
    while(a){
        ans+=a%10;
        a/=10;
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    int lb=max((int)0,n-1000);
    queue<int>ans;
    for(int i=lb;i<=n;i++){
        if(i+cnt(i)==n)ans.push(i);
    }
    cout<<ans.size()<<endl;
    while(!ans.empty()){
        cout<<ans.front()<<endl;
        ans.pop();
    }
    return;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;

    //cin>>t;
    t=1;

    while(t--)solve();
    return 0;
}