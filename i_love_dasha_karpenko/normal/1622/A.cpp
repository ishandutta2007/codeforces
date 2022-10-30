#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define int ll
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'0')

void solve() {
    int l1,l2,l3;
    cin>>l1>>l2>>l3;
    if (l1==l2+l3 || l2==l1+l3 || l3==l1+l2 || (l1==l2 && l3%2==0) || (l2==l3 && l1%2==0) || (l1==l3 && l2%2==0))
        cout<<"YES\n";
    else cout<<"NO\n";

}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;

    while(t--)
        solve();
}