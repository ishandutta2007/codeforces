//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gdb cout<<"dolboeb"<<endl;

void solve(){
    int n,m;
    cin>>n>>m;
    if (n==1 && m==1){
        cout<<"0\n";
        return;
    }
    if (n==1 || m==1)
        cout<<"1\n";
    else cout<<"2\n";

}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}