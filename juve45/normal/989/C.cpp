#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 55;
int n, k, a, b, c, d, m, cnt;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

char mat[55][55];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> a >> b >> c >> d;


	n = 50;
	m = 50;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			mat[i][j] = 'A';

	for(int i = 11; i <= n; i++)
		for(int j = 1; j <= m; j++)
			mat[i][j] = 'D';

	for(int i = 1; i <= 10; i += 2) {
		for(int j = 1; j <= m; j+=2) {
			if(cnt < d - 1) {
				mat[i][j] = 'D';
				cnt++;
			}
		}
	}

	a--;
	for(int i = 12; i <= n; i+=2) {
		for(int j = 1; j + 3 <= m; j+=3) {
			if(a)
			mat[i][j] = 'A', a--;
			if(b)
			mat[i][j + 1] = 'B', b--;
			if(c)
			mat[i][j + 2] = 'C', c--;
		}
	}

	cout << n << ' ' << m << '\n';

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++)
			cout << mat[i][j];
		cout << '\n';
	}
}