#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 4200;
int n, k, f[N], m, q, w[N], val;
int ans[N][120];
char s[44];

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

int main() {
	// ios_base::sync_with_stdio(false);
	// cin >> n >> m >> q;
	scanf("%d %d %d", &n, &m, &q);

	for(int i = n - 1; i >= 0; i--)
		scanf("%d", w + i);

	for(int i = 1; i <= m; i++) {
		scanf("%s", s);
		int k = 0;
		for(int j = 0; j < n; j++)
			k = k * 2 + (s[j] - '0');
		f[k]++;
	}

	for(int i = 0; i < (1 << n); i++)
		for(int j = 0; j < (1 << n); j++) {
			int msk = i ^ j, sum = 0;
			for(int k = 0; k < n; k++) 
				if((msk & (1 << k)) == 0)
					sum += w[k];
			if(sum <= 100)
				ans[i][sum] += f[j];
		}

	for(int i = 0; i < (1 << n); i++) 
		for(int j = 1; j <= 100; j++)
			ans[i][j] += ans[i][j - 1];

	for(int i = 1; i <=q ; i++) {

		scanf("%s %d", s, &val);
		int k = 0;
		for(int j = 0; j < n; j++)
			k = k * 2 + (s[j] - '0');

		cout << ans[k][val] << '\n';
		
	}

}