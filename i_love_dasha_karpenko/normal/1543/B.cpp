#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int DIM = 2E5+7;
int solve(){
    int n;
    cin>>n;
    ll sum = 0;
    for(int i = 1;i<=n;++i){
        int x;
        cin>>x;
        sum+=x;
    }
    ll base = sum/n;
    ll add = sum%n;
    ll res = add*(n-add);
    cout<<res<<endl;
    return 1;
}
int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}