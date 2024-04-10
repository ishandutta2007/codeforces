
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps=1e-12;
const int N=210;
const ll mod=998244353;
#define ADD(a,b) a+=b;if (a>=mod) a-=mod
#define endl '\n'
void solve(){
    int n;cin>>n;
    n--;
    int bt=0;
    for (int i=29;i>=0;i--){
        if (n&(1<<i)){
            bt=i;
            break;
        }
    }
    for (int i=n;i>=(1<<bt);i--) cout<<i<<" ";
    for (int i=0;i<(1<<bt);i++) cout<<i<<" ";
    cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/**
5 1 1
1 4 5 2 3
2 1 3
**/