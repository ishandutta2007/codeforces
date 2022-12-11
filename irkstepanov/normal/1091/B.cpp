#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

pii operator+(pii a, pii b) {
    return {a.first + b.first, a.second + b.second};
}

pii operator-(pii a, pii b) {
    return {a.first - b.first, a.second - b.second};
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pii> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    vector<pii> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i].first >> b[i].second;
    }

    for (int i = 0; i < n; ++i) {
        pii res = a[0] + b[i];
        map<pii, int> mapa;
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            ++mapa[b[j]];
        }
        bool ok = true;
        for (int j = 1; j < n; ++j) {
            pii x = res - a[j];
            if (!mapa.count(x)) {
                ok = false;
                break;
            }
            --mapa[x];
            if (mapa[x] == 0) {
                mapa.erase(x);
            }
        }
        if (ok) {
            cout << res.first << " " << res.second << "\n";
        }
    }

}