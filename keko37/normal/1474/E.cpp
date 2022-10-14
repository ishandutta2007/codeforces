#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

llint t, n, sol;
int p[MAXN];
vector <pi> v;

void f (int a, int b) {
    v.push_back({a, b});
    swap(p[a], p[b]);
    sol += (llint) (a - b) * (a - b);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        v.clear(); sol = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) p[i] = i;
        f(1, n);
        for (int i = 2; i <= n / 2; i++) {
            f(i, n); f(n + 1 - i, 1);
        }
        if (n % 2 == 1) f((n + 1) / 2, 1);
        cout << sol << '\n';
        for (int i = 1; i <= n; i++) cout << p[i] << " "; cout << '\n';
        cout << v.size() << '\n';
        reverse(v.begin(), v.end());
        for (auto pp : v) cout << pp.first << " " << pp.second << '\n';
    }
    return 0;
}