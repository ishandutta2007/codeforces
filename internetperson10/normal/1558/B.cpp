#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll ans[4000001];

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    ll n, p;
    cin >> n >> p;
    ans[1] = 1;
    ll sum = 1;
    ll a = 1;
    for(int i = 2; i <= n; i++) {
        a *= 2;
        if(i > 2) a++;
        ans[i] += a;
        ans[i] %= p;
        sum += ans[i];
        sum %= p;
        a = ans[i];
        for(int j = 2*i; j <= n; j+=i) ans[j] += (ans[i] - ans[i-1] + p);
        //cout << ans[i] << '\n';
    }
    cout << a << '\n';
}