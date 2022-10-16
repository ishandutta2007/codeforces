#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 100100;
int n, k, a[4], b[4], c, nrd[N], g[4][4];

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

int get_gcd(int * use) {
	if(use[1] && !use[2] && !use[3])
		return a[1];
	if(!use[1] && use[2] && !use[3])
		return a[2];
	if(!use[1] && !use[2] && use[3])
		return a[3];

	if(use[1] && use[2] && !use[3])
		return g[1][2];
	if(use[1] && !use[2] && use[3])
		return g[1][3];
	if(!use[1] && use[2] && use[3])
		return g[2][3];

	return g[0][0];
}

int nr_div(int k) {
	int ret = 0;
	for(int i = 1; i * i <= k; i++) {
		if(k % i) continue;
		ret++;
		if(i * i != k)
			ret++;
	}
	return ret;
}


int main() {
	scanf("%d", &n);
	for(int i = 1; i < N; i++)
		nrd[i] = nr_div(i);

	vector <vector <int> > perm;
	perm.push_back({1, 2, 3});
	perm.push_back({1, 3, 2});
	perm.push_back({2, 1, 3});
	perm.push_back({2, 3, 1});
	perm.push_back({3, 1, 2});
	perm.push_back({3, 2, 1});

	for(int i = 1; i <= n; i++) {
		scanf("%d %d %d", a + 1, a + 2, a + 3);
	
		int ans = 0;

		g[1][2] = __gcd(a[1], a[2]);
		g[1][3] = __gcd(a[1], a[3]);
		g[2][3] = __gcd(a[2], a[3]);
		g[0][0] = __gcd(a[1], g[2][3]);

		for(int msk = 1; msk < (1 << 6); msk++) {
			int sgn = 1;
			if(__builtin_popcount(msk) % 2 == 0)
				sgn = -1;
			int use[4][4];
			memset(use, 0, sizeof use);
			for(int j = 0; j < 6; j++) {
				if(msk & (1 << j))
					for(int k = 1; k <= 3; k++)
						use[k][perm[j][k - 1]] = 1;
			}
			int b[4];
			
			b[1] = get_gcd(use[1]);
			b[2] = get_gcd(use[2]);
			b[3] = get_gcd(use[3]);

			ans += sgn * (nrd[b[1]] * nrd[b[2]] * nrd[b[3]]);
		}

		for(int msk = 1; msk < (1 << 6); msk++) {
			int sgn = 1;
			if(__builtin_popcount(msk) % 2 == 0)
				sgn = -1;
			int use[4][4];
			memset(use, 0, sizeof use);
			for(int j = 0; j < 6; j++) {
				if(msk & (1 << j))
					for(int k = 0; k < 3; k++)
						use[k / 2][perm[j][k]] = 1;
			}
			int b[4];
			
			b[0] = get_gcd(use[0]);
			b[1] = get_gcd(use[1]);

			ans += 3 * sgn * (nrd[b[0]] * nrd[b[1]]);// * nrd[b[3]]);
		}

		// dbg(ans);
		ans += 2 * nrd[__gcd(a[1], __gcd(a[2], a[3]))];
		printf("%d\n", ans / 6);
	}
}