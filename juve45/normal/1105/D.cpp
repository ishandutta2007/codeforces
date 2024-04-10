#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

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

const int N = 1010;
int n, k, m, p, c[N], f[55];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

string s[N];
queue <pair<int, int> > q[N];

bool ok(int x, int y) {
	if( x < 0 || y < 0)
		return false;
	if( x >= n || y >= m)
		return false;
	return (s[x][y] == '.');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> p;

	for(int i = 1; i <= p; i++)
		cin >> c[i];

	for(int i = 0; i < n; i++) {
		cin >> s[i];
		for(int j = 0; j < m; j++)
			if(s[i][j] != '.' && s[i][j] != '#')
				q[s[i][j] - '0'].push({i, j});
	}

	int okk = 1;
	for(int ii = 1; ii <= N * N && okk;ii++) {

		okk = 0;
		for(int i = 1; i <= p; i++) {
			for(int j = 0; j < c[i] && !q[i].empty(); j++) {
				queue <pair<int, int> > qt;
				while(!q[i].empty()) {
					okk = 1;
					auto pp = q[i].front();
					q[i].pop();

					for(int d = 0; d < 4; d++)
						if(ok(pp.st + dx[d], pp.nd + dy[d])) {
							s[pp.st + dx[d]][pp.nd + dy[d]] = i + '0';
							qt.push({pp.st + dx[d], pp.nd + dy[d]});
						}
				}
				q[i] = qt;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		dbg(s[i]);
		for(auto j : s[i])
			if('0' <= j && j <= '9')
				f[j - '0']++;
	}

	for(int i = 1; i <= p; i++)
		cout << f[i] << ' ';

	cout << '\n';
}