#include <bits/stdc++.h>
using namespace std;

int main(){
    long n, d, e;
    cin >> n >> d >> e;
    long ans = n;
    for (long i = 0; i * d <= n; i++) {
        ans = min(ans, (n - i * d) % (5 * e));
    }
    cout << ans;
}