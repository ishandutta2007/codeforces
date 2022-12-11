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

mt19937 rr(998244353);
const int inf = 5e5 - 10;

int main() {

    //ifstream cin("input.txt");
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, x;
    cin >> n >> x;
    if (n == 2 && x == 0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

    while (true) {
        vector<int> a(n);
        set<int> s;
        for (int i = 0; i < n - 1; ++i) {
            int val = rr() % inf;
            if (s.count(val)) {
                --i;
                continue;
            }
            a[i] = val;
            s.insert(val);
        }
        int curr = 0;
        for (int i = 0; i < n - 1; ++i) {
            curr ^= a[i];
        }
        if (s.count(curr ^ x)) {
            continue;
        }
        a[n - 1] = (curr ^ x);
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum ^= a[i];
        }
        assert(sum == x);
        cout << "\n";
        return 0;
    }

}