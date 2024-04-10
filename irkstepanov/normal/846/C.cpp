#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const ll inf = 1e18;

vector<ll> a;
vector<ll> pref;
int n;

ll getMin(int l, int r) {
    ll ans = 0;
    ll maxx = 0;
    ll curr = 0;
    for (int i = l; i <= r; ++i) {
        curr += a[i];
        ans = min(ans, curr - maxx);
        maxx = max(maxx, curr);
    }
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

	cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    pref.resize(n);
    pref[0] = a[0];
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + a[i];
    }

    ll minn = inf;
    int bestSuff;
    for (int suff = 0; suff <= n; ++suff) {
        ll sum = pref[n - 1];
        if (suff != n) {
            sum -= pref[n - 1 - suff];
            sum += getMin(0, n - 1 - suff);
        }
        if (sum < minn) {
            minn = sum;
            bestSuff = suff;
        }
    }

    if (bestSuff == n) {
        cout << "0 0 0\n";
        return 0;
    }

    int x, y;
    ll want = getMin(0, n - 1 - bestSuff);
    for (int i = 0; i <= n - 1 - bestSuff; ++i) {
        ll curr = 0;
        if (curr == want) {
            x = i + 1;
            y = i + 1;
        }
        for (int j = i; j >= 0; --j) {
            curr += a[j];
            if (curr == want) {
                x = j;
                y = i + 1;
            }
        }
    }

    cout << x << " " << y << " " << n - bestSuff << "\n";

}