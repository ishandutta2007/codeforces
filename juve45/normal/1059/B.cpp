#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 1010;
int n, k, w[N][N], m;
string s;

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
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> s;
		for(int j = 1; j <= m; j++)
			if(s[j - 1] == '#') w[i][j] = 1;
	}

	for(int i = 1; i <= n - 2; i++)
		for(int j = 1; j <= m - 2; j++) {
			int tmp = 0;

			for(int k = 0; k < 3; k++)
				for(int l = 0; l < 3; l++)
					if(k != 1 || l != 1)
						tmp += (w[i + k][j + l] != 0);

			if(tmp == 8)
				for(int k = 0; k < 3; k++)
					for(int l = 0; l < 3; l++)
						if(k != 1 || l != 1)
							w[i + k][j + l]++;
		}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(w[i][j] == 1)
				return cout << "NO\n", 0;
	return cout << "YES\n", 0;
}