#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100000;

int a[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    ll res = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if(a[i] == a[i-1]) continue;
        else if(a[i] > a[i-1]) res += 1LL*(a[i] - a[i-1])*(n - a[i] + 1);
        else res += 1LL*a[i]*(a[i-1] - a[i]);
    }
    cout << res << "\n";
    return 0;
}