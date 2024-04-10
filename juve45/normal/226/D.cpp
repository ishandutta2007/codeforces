#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << ' '; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 101;
int n, swr[N], swc[N], sumr[N], sumc[N], a[N][N], m;

void swapR(int row) {
	swr[row] ^= 1;

	for(int i = 1; i <= m; i++) {
		sumc[i] -= 2 * a[row][i];
		a[row][i] *= -1;
	}
	sumr[row] *= -1;
}

void swapC(int col) {
	swc[col] ^= 1;

	for(int i = 1; i <= n; i++) {
		sumr[i] -= 2 * a[i][col];
		a[i][col] *= -1;
	}
	sumc[col] *= -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
			sumc[j] += a[i][j];
			sumr[i] += a[i][j];
		}

	for(int i = 1; i <= 253; i++) {
		int ok = 0;
		for(int i = 1; i <= n && !ok; i++)
			if(sumr[i] < 0)
				swapR(i), ok = 1;

		for(int j = 1; j <= m && !ok; j++)
			if(sumc[j] < 0)
				swapC(j), ok = 1;

		if(!ok) {
			vector <int> ans;
			for(int i = 1; i <= n; i++)
				if(swr[i])
					ans.push_back(i);
			cout << ans << '\n';

			ans.clear();
			for(int i = 1; i <= m; i++)
				if(swc[i])
					ans.push_back(i);
			cout << ans << '\n';
			return 0;
		}
	}
	cout << "NOPE\n";
}