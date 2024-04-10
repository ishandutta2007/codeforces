#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int DIM = 2E5+7;
int solve(){
    ll a,b;
    cin>>a>>b;
    if (a==b){
        cout<<"0 0\n";
        return 1;
    }
    ll num = abs(a-b);
    ll dist = max(min(a%num,num-a%num),min(b%num,num-b%num));
    cout<<num<<' '<<dist<<endl;
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