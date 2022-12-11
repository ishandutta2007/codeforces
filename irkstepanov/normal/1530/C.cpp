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

    int tt;
    cin >> tt;

    while (tt--) {
    	int n;
    	cin >> n;
    	vector<int> a(n);
    	vector<int> b(n);
    	for (int i = 0; i < n; ++i) {
    		cin >> a[i];
    	}
    	for (int i = 0; i < n; ++i) {
    		cin >> b[i];
    	}
    	sort(all(a));
    	sort(all(b));
    	int lf = n - 1, rg = n + 400500;
    	//lf = 1 + n, rg = 3 + n;
    	while (rg - lf > 1) {
    		int md = (lf + rg) >> 1;
    		int take = md - (md / 4);
    		int rem = max(0, take - md + n);
    		int x = 100 * (md - n), y = 0;
    		for (int i = n - 1; i >= n - rem; --i) {
    			x += a[i];
    		}
    		for (int i = n - 1; i >= 0 && i >= n - take; --i) {
    			y += b[i];
    		}
    		//cout << rem << " " << x << " " << y << endl;
    		if (x >= y) {
    			//cout << "OK\n";
    			rg = md;
    		} else {
    			lf = md;
    		}
    	}
    	cout << rg - n << "\n";
    }

}