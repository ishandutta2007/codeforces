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

    k = min(k, n);
    if (k == 1) {
        cout << "1\n";
        return 0;
    }

    ll ans = 1;
    ans += ll(n) * ll(n - 1) / 2;

    if (k == 2) {
        cout << ans << "\n";
        return 0;
    }

    ans += ll(n) * ll(n - 1) * ll(n - 2) / 3;

    if (k == 3) {
        cout << ans << "\n";
        return 0;
    }

    ans += ll(n) * ll(n - 1) * ll(n - 2) * ll(n - 3) / 8;
    ans += ll(n) * ll(n - 1) * ll(n - 2) * ll(n - 3) / 4;
    cout << ans << "\n";

}