#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

int main() {
    
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int k;
    cin >> n >> m >> k;

    bool ok = false;
    while (k--) {
    	int x, y;
    	cin >> x >> y;
    	if (x - 1 <= 4 || n - x <= 4 || y - 1 <= 4 || m - y <= 4) {
    		ok = true;
    	}
    }

    cout << (ok ? "YES\n" : "NO\n");

    
}