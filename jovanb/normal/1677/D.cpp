#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1000000;
const int MOD = 998244353;

int add(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a; }
int mul(int a, int b){ return (1LL*a*b)%MOD; }

int a[N+5];

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    int res = 1;
    for(int i=1; i<=k; i++){
        if(a[n-i+1] != -1 && a[n-i+1] != 0){
            cout << "0\n";
            return;
        }
        res = mul(res, i);
    }
    for(int i=k+1; i<=n; i++){
        if(a[i-k] == 0){
            res = mul(res, k + 1);
        }
        else if(a[i-k] == -1){
            res = mul(res, i);
        }
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

/*
1
5 2
0 1 1 0 0
*/