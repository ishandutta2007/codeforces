#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi pref, pref1, b;
vector<string> a;
int n, m;

int get_sum(int x1, int y1, int x2, int y2) {
	return pref[x2 + 1][y2 + 1] + pref[x1][y1] - pref[x2 + 1][y1] - pref[x1][y2 + 1];
}
int get_sum1(int x1, int y1, int x2, int y2) {
	return pref1[x2 + 1][y2 + 1] + pref1[x1][y1] - pref1[x2 + 1][y1] - pref1[x1][y2 + 1];
}

bool do_for(int mid) {
	//cout << 1 << endl;
	for(int i = 0; i <= n; i++) {
		pref1[i][0] = 0;
	}
	for(int i = 0; i <= m; i++) {
		pref1[0][i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int here = b[i - 1][j - 1] > mid;
			here += pref1[i - 1][j] + pref1[i][j - 1] - pref1[i - 1][j - 1];
			pref1[i][j] = here;
		}
	}
	//cout << 2 << endl;
	bool ok = true;
	for(int i = -1; i <= n; i++) {
		for(int j = -1; j <= m; j++) {
			int x1 = max(i - mid, 0);
			int y1 = max(j - mid, 0);
			int x2 = min(i + mid, n - 1);
			int y2 = min(j + mid, m - 1);
			int here = get_sum1(x1, y1, x2, y2);
			if(i == -1 || j == -1 || i == n || j == m || a[i][j] == '.') {
				if(here != 0) {
					ok = false;
					break;
				}
				continue;
			}
			if(here == 0) {
				ok = false;
				break;
			}
		}
		if(!ok) break;
	}
	return ok;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    pref.assign(n + 1, vi(m + 1, 0));
    for(int i = 1; i <= n; i++) {
    	for(int j = 1; j <= m; j++) {
    		int here = a[i - 1][j - 1] == 'X';
    		here += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
    		pref[i][j] = here;
    	}
    }
    vvi mx(n, vi(m));
    b.assign(n, vi(m));
    pref1.assign(n + 1, vi(m + 1, 0));
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < m; j++) {
    		int l = 0;
    		int r = n + m;
    		while(r - l > 1) {
    			int mid = (l + r) / 2;
    			int st = 2 * mid - 1;
    			ll need = (ll)st * st;
    			int x1 = i - mid + 1;
    			int y1 = j - mid + 1;
    			int x2 = i + mid - 1;
    			int y2 = j + mid - 1;
    			if(x1 < 0 || y1 < 0 || x2 >= n || y2 >= m) {
    				r = mid;
    				continue;
    			}
    			if(need == get_sum(x1, y1, x2, y2)) {
    				l = mid;
    			} else {
    				r = mid;
    			}
    		}
    		b[i][j] = l;
    	}
    }
    int l = 0;
    int r = n + m;
    while(r - l > 1) {
    	int mid = (l + r) / 2;
    	if(do_for(mid)) {
    		l = mid;
    	} else {
    		r = mid;
    	}
    }
    cout << l << '\n';
    //do_for(l);
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < m; j++) {
    		if(b[i][j] > l) {
    			cout << 'X';
    		} else {
    			cout << '.';
    		}
    	}
    	cout << '\n';
    }
}