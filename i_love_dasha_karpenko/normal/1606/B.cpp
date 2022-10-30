#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 1e3+7;
void solve(){
    ll n,k;
    cin>>n>>k;
    ll cur = 1,left = n-1;
    ll step = 0;
    while(left){
        if (cur==k){
            step+=left/cur+(left%cur!=0);
            break;
        }
        left = max(0ll,left-cur);
        cur = min(cur<<1,k);
        ++step;
    }
    cout<<step<<endl;
}
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}