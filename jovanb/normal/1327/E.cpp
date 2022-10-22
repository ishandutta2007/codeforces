#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 998244353;

ll add(ll a, ll b){
    return (a+b)%MOD;
}

ll mul(ll a, ll b){
    a %= MOD;
    b %= MOD;
    return (a*b)%MOD;
}

ll a[200005];

ll pw(ll a, ll b){
    if(b == 0) return 1;
    ll res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

ll p10[200005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    p10[0] = 1;
    for(int i=1; i<=n; i++) p10[i] = mul(10, p10[i-1]);
	for(int i=1; i<=n; i++){
        for(int j=0; j<=9; j++){
            /// gde se j pojavljuje i puta
            /// 1. srednjih i cifara nekog broja
            if(n-i-2 >= 0) a[i] = add(a[i], mul(n-i-1, mul(81, p10[n-i-2])));
            /// prvih i
            if(n-i-1 >= 0) a[i] = add(a[i], mul(9, p10[n-i-1]));
            /// poslednjih i
            if(n-i-1 >= 0) a[i] = add(a[i], mul(9, p10[n-i-1]));
        }
	}
	a[n] += 10;
	for(int i=1; i<=n; i++) cout << a[i] << " ";
    return 0;
}