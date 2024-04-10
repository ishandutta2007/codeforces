#include <bits/stdc++.h>
using namespace std;

struct S
{
    long long w, h, c;
};

long long divisor(long long x) {
    long long result = 1;
    for (long long d = 2; d * d <= x; d++) {
        int cnt = 0;
        while (x % d == 0) {
            cnt++;
            x /= d;
        }
        result *= cnt + 1;
    }
    if (x > 1)
        result *= 2;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<S> v(n);
    
    for (int i = 0; i < n; i++) {
        auto& x = v[i];
        cin >> x.w >> x.h >> x.c;
    }

    map<long long, vector<S>> hs, ws;
    for (auto& x : v) {
        hs[x.h].push_back(x);
        // ws[x.w].push_back(x):
    }

    bool first = true;
    vector<pair<long long, long long>> res;
    long long G = 0;

    for (auto& p : hs) {
        auto& vec = p.second;
        long long g = 0;
        for (auto& x : vec)
            g = gcd(g, x.c);
        
        vector<pair<long long, long long>> w;
        for (auto& x : vec)
            w.emplace_back(x.w, x.c / g);
        sort(w.begin(), w.end());
        if (first) {
            res = w;
            first = false;
            G = g;
        } else {
            if (res != w) {
                cout << 0 << '\n';
                return 0;
            }
            G = gcd(G, g);
        }
    }

    cout << divisor(G) << endl;
}