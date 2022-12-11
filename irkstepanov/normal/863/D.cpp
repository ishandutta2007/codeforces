#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

int main() {

    //ifstream cin("input.txt");
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, q, m;
    cin >> n >> q >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> type(q), l(q), r(q);
    for (int i = 0; i < q; ++i) {
        cin >> type[i] >> l[i] >> r[i];
        --l[i], --r[i];
    }

    while (m--) {
        int pos;
        cin >> pos;
        --pos;
        for (int i = q - 1; i >= 0; --i) {
            if (l[i] > pos || r[i] < pos) {
                continue;
            }
            if (type[i] == 2) {
                pos = r[i] - pos + l[i];
            } else {
                if (pos == l[i]) {
                    pos = r[i];
                } else {
                    --pos;
                }
            }
        }
        cout << a[pos] << " ";
    }
    cout << "\n";

}