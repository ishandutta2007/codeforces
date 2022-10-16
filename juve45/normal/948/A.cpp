#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 555
#define NMAX 
#define MMAX 

using namespace std;

int n, k, w[555][555], m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};


template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

string s[DMAX];

void doo() {
	for(int i = 1; i <= n; i++)
		for(int j = 1; j<= m; j++)
			if(w[i][j] == 2)
				for(int k = 0 ; k < 4; k++) 
					if(w[i + dx[k]][j + dy[k]] == 1) {
						cout << "No\n";
						return;
					}
	
	cout << "Yes\n";
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			if(s[i][j] == '.') s[i][j] = 'D';
		cout << s[i] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		for(int j = 0; j < m; j++) {
			if(s[i][j] == 'S') w[i + 1][j + 1] = 1;
			if(s[i][j] == 'W') w[i + 1][j + 1] = 2;
		}
	}
	doo();
}