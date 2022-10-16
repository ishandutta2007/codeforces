#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 26;
int n, k, a[5][N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

long long gans = -1e9;
pair<int, int> mans;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> a[0][i] >> a[1][i] >> a[2][i];

	int half = n / 2;
	int p3 = 1;
	
	//0 = 01
	//1 = 12
	//2 = 20

	for(int i = 1; i <= half; i++) p3 *= 3;

	map<pair<int, int>, pair<int, int> > m;

	for(int msk = 0; msk < p3; msk++) {
		int cm = msk;
		int ans[] = {0, 0, 0};
		for(int j = 1; j <= half; j++) {
			int r1 = cm % 3;
			cm /= 3;
			int r2 = (r1 + 1) % 3;
			ans[r1] += a[r1][j];
			ans[r2] += a[r2][j];
		}
		// dbg_v(ans, 3);
		pair<int, int> pp = {ans[0] - ans[1], ans[0] - ans[2]};
		// dbg(pp);
		if(m.count(pp) == 0)
			m[pp] = {ans[0], msk};
		else 
			m[pp] = max(m[pp], {ans[0], msk});
	}

	dbg_ok;
	p3 = 1;
	for(int i = half + 1; i <= n; i++) p3 *= 3;
	int h2 = n - half;

	for(int msk = 0; msk < p3; msk++) {
		int cm = msk;
		int ans[] = {0, 0, 0};
		for(int j = 0; j < h2; j++) {
			int r1 = cm % 3;
			cm /= 3;
			int r2 = (r1 + 1) % 3;
			ans[r1] += a[r1][j + half + 1];
			ans[r2] += a[r2][j + half + 1];
		}
		// dbg_v(ans, 3);
		pair<int, int> pp = {-ans[0] + ans[1], -ans[0] + ans[2]};
		// dbg(pp);
		if(m.count(pp)) {
			pair<int, int> p2 = m[pp];
			if(p2.st + ans[0] > gans) {
				gans = p2.st + ans[0];
				mans = {p2.nd, msk};
			}
		}	
	}

	string ss[3];
	ss[0] = "LM\n";
	ss[1] = "MW\n";
	ss[2] = "WL\n";

	if(gans == -1e9) {
		cout << "Impossible\n";
	} else {
		for(int i = 1; i <= n / 2; i++) {
			cout << ss[mans.st % 3];
			mans.st /= 3;
		}
		for(int i = n/2 + 1; i <= n; i++) {
			cout << ss[mans.nd % 3];
			mans.nd /= 3;
		}

	}

}