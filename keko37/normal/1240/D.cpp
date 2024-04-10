#include<bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

typedef long long llint;

int q, n;
vector <int> v;
llint m[2], b[2], pot[2][MAXN], h[2];
map <llint, int> mp;

void precompute () {
    m[0] = 1000000007; m[1] = 1000000009;
    b[0] = MAXN + rand() % 10000;
    b[1] = MAXN + rand() % 10000;
    pot[0][0] = pot[1][0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pot[0][i] = pot[0][i - 1] * b[0] % m[0];
        pot[1][i] = pot[1][i - 1] * b[1] % m[1];
    }
}

void ubaci (int x) {
    int br = v.size();
    if (!v.empty() && v.back() == x) {
        h[0] = ((h[0] - x * pot[0][br - 1]) % m[0] + m[0]) % m[0];
        h[1] = ((h[1] - x * pot[1][br - 1]) % m[1] + m[1]) % m[1];
        v.pop_back();
    } else {
        h[0] = (h[0] + x * pot[0][br]) % m[0];
        h[1] = (h[1] + x * pot[1][br]) % m[1];
        v.push_back(x);
    }
    mp[h[0] * m[1] + h[1]]++;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    precompute();
    cin >> q;
    while (q--) {
        mp.clear(); v.clear();
        cin >> n;
        mp[0]++;
        h[0] = h[1] = 0;
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            ubaci(x);
        }
        llint sol = 0;
        for (auto par : mp) {
            llint cnt = par.second;
            sol += cnt * (cnt - 1) / 2;
        }
        cout << sol << '\n'; // bok
    }
    return 0;
}