#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, h, m;
vector <int> v;

int f (int d) {
    if (d == 0) return 0;
    if (d == 1) return 1;
    if (d == 2) return 5;
    if (d == 5) return 2;
    if (d == 8) return 8;
    return -1;
}

void precompute () {
    v.clear();
    for (int hh = 0; hh < h; hh++) {
        for (int mm = 0; mm < m; mm++) {
            int a = hh / 10, b = hh % 10, c = mm / 10, d = mm % 10;
            a = f(a), b = f(b), c = f(c), d = f(d);
            if (a == -1 || b == -1 || c == -1 || d == -1) continue;
            if (d * 10 + c < h && b * 10 + a < m) {
                v.push_back(hh * m + mm);
                v.push_back(hh * m + mm + h * m);
            }
        }
    }
    sort(v.begin(), v.end());
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> h >> m;
        precompute();
        int hh, mm; char c;
        cin >> hh >> c >> mm;
        int val = *lower_bound(v.begin(), v.end(), hh * m + mm) % (h * m);
        cout << (val / m) / 10 << (val / m) % 10 << ":" << (val % m) / 10 << (val % m) % 10 << '\n';
    }
    return 0;
}