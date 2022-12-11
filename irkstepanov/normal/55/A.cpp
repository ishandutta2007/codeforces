#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

   	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<bool> used(n, false);
    for (int x = 0; x < n; ++x) {
    	used[((x * (x + 1)) / 2) % n] = true;
    }

    for (int i = 0; i < n; ++i) {
    	if (!used[i]) {
    		cout << "NO\n";
    		return 0;
    	}
    }

    cout << "YES\n";

}