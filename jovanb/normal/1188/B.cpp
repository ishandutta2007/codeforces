#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int MOD;

ll res;

map <ll, ll> cnt;

int mul(int a, int b){
    return (1LL*a*b)%MOD;
}

int add(ll a, ll b){
    return (a+b+MOD)%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, k;
    cin >> n >> MOD >> k;
    int x;
    for(int i=1; i<=n; i++){
        cin >> x;
        int r = mul(x, k);
        x = mul(x, x);
        x = mul(x, x);
        r = add(x, MOD-r);
        res += cnt[r];
        cnt[r]++;
    }
    cout << res;
    return 0;
}