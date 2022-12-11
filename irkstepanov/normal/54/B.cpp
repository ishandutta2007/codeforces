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

void rot(vector<string>& a) {
	int n = sz(a);
	int m = sz(a[0]);
	vector<string> b(m);
	for (int j = 0; j < m; ++j) {
		b[j] = "";
		for (int i = n - 1; i >= 0; --i) {
			b[j] += a[i][j];
		}
	}
	a.swap(b);
}

int main() {
    
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;

    vector<string> q(a);
    for (int i = 0; i < a; ++i) {
    	cin >> q[i];
    }

    int cnt = 0;
    int optx = -1, opty;

    for (int x = 1; x <= a; ++x) {
    	for (int y = 1; y <= b; ++y) {
    		if (a % x || b % y) {
    			continue;
    		}
    		set<vector<string> > setik;
    		bool valid = true;
    		for (int i = 0; i < a / x; ++i) {
    			for (int j = 0; j < b / y; ++j) {
    				vector<string> vct;
    				for (int u = i * x; u < (i + 1) * x; ++u) {
    					string s = "";
    					for (int v = j * y; v < (j + 1) * y; ++v) {
    						s += q[u][v];
    					}
    					vct.pb(s);
    				}
    				if (setik.count(vct)) {
						valid = false;
					}
    				for (int t = 0; t < 3; ++t) {
    					rot(vct);
    					if (setik.count(vct)) {
    						valid = false;
    					}
    				}
    				for (int t = 0; t < 4; ++t) {
    					rot(vct);
    					setik.insert(vct);
    				}
    			}
    		}
    		if (valid) {
    			++cnt;
    			if (optx == -1 || optx * opty > x * y || (optx * opty == x * y && optx > x)) {
    				optx = x, opty = y;
    			}
    		}
    	}
    }

    cout << cnt << "\n";
    cout << optx << " " << opty << "\n";

}