#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    vector<int> neg;
    vector<int> pos;
    int cnt0 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) {
            neg.pb(a[i]);
        } else if (a[i] == 0) {
            ++cnt0;
        } else {
            pos.pb(a[i]);
        }
    }

    if (sz(neg) + cnt0 == n) {
        if (sz(neg) >= 2) {
            sort(all(neg));
            for (int i = 0; i + 1 < sz(neg); i += 2) {
                cout << neg[i] << " " << neg[i + 1] << " ";
            }
            cout << endl;
            return 0;
        }
        cout << "0\n";
        return 0;
    }

    for (int x : pos) {
        cout << x << " ";
    }
    sort(all(neg));
    for (int i = 0; i + 1 < sz(neg); i += 2)  {
        cout << neg[i] << " " << neg[i + 1] << " ";
    }
    cout << endl;

}