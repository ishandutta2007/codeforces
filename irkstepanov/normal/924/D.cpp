#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

struct Fraction {
    ll num, den;
    Fraction() {}
    Fraction(ll a, ll b) {
        if (b < 0) {
            a *= (-1);
            b *= (-1);
        }
        num = a, den = b;
    }
    bool operator<(const Fraction& other) const {
        return num * other.den < den * other.num;
    }
    bool operator==(const Fraction& other) const {
        return num * other.den == den * other.num;
    }
};

vector<int> t;
int N;

void add(int pos) {
    for (pos += N; pos; pos >>= 1) {
        ++t[pos];
    }
}

int get(int l, int r) {
    int ans = 0;
    for (l += N, r += N; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
        if (l & 1) {
            ans += t[l];
        }
        if (!(r & 1)) {
            ans += t[r];
        }
    }
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    ll w;
    cin >> n >> w;

    vector<ll> x(n), v(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> v[i];
    }

    vector<pair<Fraction, Fraction> > vct(n);
    for (int i = 0; i < n; ++i) {
        vct[i].first = Fraction(v[i] - w, x[i]);
        vct[i].second = Fraction(v[i] + w, x[i]);
    }

    sort(all(vct));

    ll ans = 0;
    vector<Fraction> f;
    for (int i = 0; i < n; ++i) {
        f.pb(vct[i].second);
    }
    sort(all(f));
    f.resize(unique(all(f)) - f.begin());
    N = sz(f);
    t.resize(2 * N);

    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(all(f), vct[i].second) - f.begin();
        ans += get(pos + 1, N - 1);
        if (i + 1 < n && vct[i].first == vct[i + 1].first) {
            continue;
        }
        int cnt = 0;
        for (int j = i; j >= 0 && vct[j].first == vct[i].first; --j) {
            pos = lower_bound(all(f), vct[j].second) - f.begin();
            add(pos);
            ++cnt;
        }
        ans += ll(cnt) * (cnt - 1) / 2;
    }

    for (int i = 0; i < n; ++i) {
        swap(vct[i].first, vct[i].second);
    }
    sort(all(vct));

    if (w) {
        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && vct[i].first == vct[i + 1].first) {
                continue;
            }
            int cnt = 0;
            for (int j = i; j >= 0 && vct[j].first == vct[i].first; --j) {
                ++cnt;
            }
            ans += ll(cnt) * (cnt - 1) / 2;
        }
    }

    cout << ans << "\n";

}