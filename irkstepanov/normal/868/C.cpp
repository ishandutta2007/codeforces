// MIPT Shock Content (place 19)

#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double ld;

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int main() {

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> cnt(1 << k);

    for (int i = 0; i < n; ++i) {
        int mask = 0;
        for (int j = 0; j < k; ++j) {
            int b;
            cin >> b;
            mask <<= 1;
            mask += b;
        }
        ++cnt[mask];
    }

    if (cnt[0] > 0) {
        cout << "YES\n";
        return 0;
    }

    for (int mask = 0; mask < (1 << k); ++mask) {
        int opp = (1 << k) - 1 - mask;
        if (cnt[mask] && cnt[opp]) {
            cout << "YES\n";
            return 0;
        }
    }

    set<int> alive;
    for (int mask = 1; mask < (1 << k); mask <<= 1) {
        if (cnt[mask]) {
            alive.insert(mask);
        }
    }

    if (sz(alive) > 1) {
        cout << "YES\n";
        return 0;
    }

    if (alive.empty()) {
        cout << "NO\n";
        return 0;
    }

    int pos;
    if (*alive.begin() == 1) {
        pos = 0;
    } else if (*alive.begin() == 2) {
        pos = 1;
    } else if (*alive.begin() == 4) {
        pos = 2;
    } else {
        pos = 3;
    }

    for (int mask = 0; mask < (1 << k); ++mask) {
        if (cnt[mask] && !bit(mask, pos)) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

}