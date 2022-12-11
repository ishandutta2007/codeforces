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

int ans;
int u;

void solve(int x, int y) {
	if (x >= y) {
		return;
	}
	ans += (y - x) / u;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n >> u;
    int k;
    cin >> k;

    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
    	cin >> a[i];
    }

    ans = k;

    if (k) {
    	solve(1, a[0]);
	    for (int i = 0; i + 1 < k; ++i) {
	    	solve(a[i] + 1, a[i + 1]);
	    }
	    solve(a.back() + 1, n + 1);
    } else {
    	solve(1, n  + 1);
    }

    

    cout << ans << "\n";

}