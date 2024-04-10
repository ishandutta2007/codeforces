#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 2010
#define NMAX 
#define MMAX 

using namespace std;

int n, k, from[DMAX], to[DMAX], v[1000], mp[5 * DMAX], sz = 0;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}


class state {
public:
	int a[4];

	state(int v[4]) {
		for(int i = 0; i < 4; i++) a[i] = v[i];
		sort(a, a + 4);
	}

	state(int x1, int x2, int x3, int x4) {
		a[0] = x1, a[1] = x2, a[2] = x3, a[3] = x4;
		sort(a, a + 4);
	}

	inline int get_nr() {
		return mp[a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3]];
	}

	int transform(int level) {
		int ans = 0;
		for(int i = 0; i < 4; i++)
			if(a[i] == level) 
				a[i] = 0, ans++;
		sort(a, a + 4);
		return ans;
	}

	static state from_nr(int i) {
		int o = v[i];
		int g[] = {o/1000, o/100%10, o/10%10, o%10};
		return state(g);
	}
};


int get(int x1, int x2, int x3, int x4) {
	vector<int> v({x1, x2, x3, x4});
	sort(v.begin(), v.end());
	int nr = v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
}

int dp[2010][777][11];

void gen() {
	for(int i1 = 0; i1 <= 9; i1++)
		for(int i2 = i1; i2 <= 9; i2++)
			for(int i3 = i2; i3 <= 9; i3++)
				for(int i4 = i3; i4 <= 9; i4++) {
					int nr = i1 * 1000 + i2 * 100 + i3 * 10 + i4;
					// dbg(nr);
					mp[nr] = sz;
					v[sz++] = (nr);
				}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> from[i] >> to[i];

	state init(0, 0, 0, 0);
	memset(dp, 0x3f, sizeof dp);

	gen();
	// cerr << v;
	dp[0][init.get_nr()][1] = 0;

	for(int i = 0; i <= n; i++) {
		for(int j = sz - 1; j >= 0; j--) {
			for(int k = 1; k <= 9; k++) {
				if(dp[i][j][k] >= 50 * n) continue;
				state fr = state::from_nr(j);

				// incerc sa las unul din oamenii din lift
				for(int r = 0; r < 4; r++) {
					if(fr.a[r]) {
						state to = fr;
						int nr = to.transform(fr.a[r]);
						dp[i][to.get_nr()][fr.a[r]] = min(dp[i][to.get_nr()][fr.a[r]], dp[i][j][k] + nr + abs(k - fr.a[r]));
					}
				}

				// incerc sa iau urmatorul om -> (i + 1)
				if(!fr.a[0] && i < n) {
					fr.a[0] = to[i + 1];
					sort(fr.a, fr.a+4);
					int dist = abs(k - from[i + 1]);
					dp[i + 1][fr.get_nr()][from[i + 1]] = min(dp[i + 1][fr.get_nr()][from[i + 1]], dp[i][j][k] + dist + 1);
				}
			}
		}
	}

	int ans = 50 * n;
	for(int k = 1; k <= 10; k++)
		ans = min(ans, dp[n][0][k]);
	cout << ans << '\n';

}