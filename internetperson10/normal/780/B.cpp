#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<ll> x, v;

long double try_pos(long double d) {
    long double ans = 0;
    for(int i = 0; i < x.size(); i++) {
        ans = max(ans, abs(d - x[i]) / (long double)v[i]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    x.resize(n); v.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    long double l = 0, r = 1e9 + 1;
    while(r - l > 0.0000001) {
        long double a = (l + l + r) / 3.0;
        long double b = (l + r + r) / 3.0;
        long double try_a = try_pos(a);
        long double try_b = try_pos(b);
        if(try_a < try_b) {
            r = b;
        }
        else {
            l = a;
        }
    }
    cout << fixed << setprecision(10) << try_pos(l) << '\n';
}