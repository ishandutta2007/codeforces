#include <bits/stdc++.h>
//#define endl '\n'
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
int ask(int r, int x, int y) {
    if(r == x || r == y) return r;
    if(x == y) return x;
    cout << "? " << x << " " << y << " " << r << endl;
    cin >> x;
    return x;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
int rd() {
    return rng()%n+1;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin >> n;n = (1<<n)-1;
    vector<int> f(n+1);
    int r = rd();
    for(int i = 0; i < 400; i++) {
        f[ask(rd(), rd(), rd())]++;
    }
    vector<int> a(n);iota(all(a), 1);
    sort(all(a), [&](int x, int y) { return f[x] > f[y]; });
    for(int i = 1; i <= n; i++) if(i != a[0] && i != a[1]) {
        if(ask(i, a[0], a[1]) == i) {
            cout << "! " << i <<endl;
            exit(0);
        }
    }
    cout << "! " << a[0] << endl;
    return 0;
}