#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

int n, k, a[5][55], px, py, nr;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

struct mov {
	int car, i, j;
};

vector <mov> ans;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for(int i = 0; i < 4; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if(i == 0 || i == 3) {
				if(a[i][j] == 0) a[i][j] = -1;
			}
			else {
				if(a[i][j] == 0) {
					px = i;
					py = j;
				}
			}
		}
	}

	
	if(px == py && px == 0){

		for(int i = 1; i <= n; i++) {
			if(a[1][i] == a[0][i])
				px = 1, py = i;
			if(a[2][i] == a[3][i])
				px = 2, py = i;
		}
	}

	if(px == py && px == 0) {
		return cout << "-1\n", 0;
	}
	if(a[px][py] != 0) {

		int glen = 0;
		if(px == 2) glen = 3;
		ans.push_back({a[px][py], glen, py});
		a[px][py] = 0;
		nr++;
	}

	while(nr < k) {
		// dbg_v(a[0], n + 1);
		// dbg_v(a[1], n + 1);
		// dbg_v(a[2], n + 1);
		// dbg_v(a[3], n + 1);
		// dbg(nr);
		int tox = px;
		int toy = py;
		if(tox == 1) {
			if(toy == 1) tox = 2;
			else toy--;
		} else if(px == 2) {
			if(toy == n) tox = 1;
			else toy++;
		} else return -1;

		int glen = 0;
		if(tox == 2) glen = 3;

		if(a[tox][toy] != 0) {

			if(a[tox][toy] == a[glen][toy] && a[tox][toy]) {
				ans.push_back({a[tox][toy], glen, toy});
				a[tox][toy] = 0;
				// dbg(tox);
				// dbg(toy);
				nr++;
			}
			else {
				ans.push_back({a[tox][toy], px, py});
				swap(a[tox][toy], a[px][py]);
			}	
		}
		px = tox;
		py = toy;
	}
	if(ans.size() > 20000) return -1;
	cout << ans.size() << '\n';
	for(auto e : ans) {
		cout << e.car << ' ' << e.i + 1 << ' ' << e.j << '\n';
	}

}