#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct query {
    ld alpha;
    int id;
    bool operator<(const query& other) const {
        return alpha < other.alpha;
    }
};

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    ld v;
    cin >> q >> v;    
    vector<query> vct(q);
    for (int i = 0; i < q; ++i) {
        ld alpha;
        cin >> alpha;
        vct[i] = {alpha, i};
    }
    sort(all(vct));

    vector<ld> ansx(q, -1);
    vector<ld> ansy(q, -1);

    int n;
    cin >> n;

    vector<pld> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(all(a));
    int ptr = 0;

    ld g = 9.8;

    for (int i = 0; i < n; ++i) {
        ld x = a[i].first;
        while (ptr < q) {
            ld len = v * v / g * sin(vct[ptr].alpha * 2);
            if (len < x) {
                ansx[vct[ptr].id] = len;
                ansy[vct[ptr].id] = 0;
                ++ptr;
                continue;
            }
            ld alpha = vct[ptr].alpha;
            ld must = x * tan(alpha) - g / 2 * x * x / v / v / cos(alpha) / cos(alpha);
            // cout << must << " " << vct[ptr].id << " " << a[i].second << endl;
            if (must <= a[i].second) {
                ansx[vct[ptr].id] = x;
                ansy[vct[ptr].id] = must;
                ++ptr;
                continue;
            }
            break;
        }
    }

    cout << fixed;
    cout.precision(20);

    for (int i = 0; i < q; ++i) {
        ld len = v * v / g * sin(vct[i].alpha * 2);
        if (ansx[vct[i].id] < 0) {
            ansx[vct[i].id] = len;
            ansy[vct[i].id] = 0;
        }
    }

    for (int i = 0; i < q; ++i) {
        cout << ansx[i] << " " << ansy[i] << "\n";
    }

}