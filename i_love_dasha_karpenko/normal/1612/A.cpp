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
    int x,y;
    cin>>x>>y;
    if ((x+y)&1)
        cout<<"-1 -1\n";
    else{
        int ds = (x+y)>>1;
        if (x>y)
            cout<<ds<<' '<<0<<endl;
        else cout<<0<<' '<<ds<<endl;
    }
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