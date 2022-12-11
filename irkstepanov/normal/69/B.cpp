#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;

struct datum {
    int l, r, t, c, i;
    bool operator<(const datum& other) const {
        if (t != other.t) {
            return t < other.t;
        }
        return i < other.i;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n, m;
    cin >> n >> m;

    vector<datum> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i].l >> a[i].r >> a[i].t >> a[i].c;
        a[i].i = i;
    }
    sort(all(a));

    vector<bool> used(n + 1, false);
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        int l = a[i].l, r = a[i].r;
        for (int j = l; j <= r; ++j) {
            if (!used[j]) {
                used[j] = true;
                sum += a[i].c;
            }
        }
    }
    cout << sum << "\n";

}