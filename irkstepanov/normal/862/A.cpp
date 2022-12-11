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

    int n, x;
    cin >> n >> x;

    set<int> s;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        s.insert(val);
    }

    int ans = 0;
    for (int i = 0; i < x; ++i) {
        if (!s.count(i)) {
            ++ans;
        }
    }
    if (s.count(x)) {
        ++ans;
    }

    cout << ans << "\n";

}