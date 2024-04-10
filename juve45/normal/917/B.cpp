#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 110
#define VALMAX 55
#define MMAX 

using namespace std;

int n, k, x, state[DMAX][DMAX][VALMAX], depthmax = 0, d[DMAX][VALMAX], m, b, a;
char c;
string s;

vector <pair<int, int> > v[DMAX];

int dfs(int node, int val) {
	// dbg(node);
	// dbg(val);
	if(d[node][val] != DMAX)
		return d[node][val];

	d[node][val] = 1;
	
	for(auto i : v[node])
		if(val <= i.second)
			d[node][val] = max(dfs(i.first, i.second) + 1, d[node][val]);
	return d[node][val];
}


template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v)
		out << e << ' ';
	return out;
}

int get_s(int i, int j, int val) {
	if(state[i][j][val] != -1)
		return state[i][j][val];
	
	state[i][j][val] = 0;

	for(auto it : v[i])
		if(it.second >= val)
			if(get_s(j, it.first, it.second) == 0) 
				state[i][j][val] = 1;

	return state[i][j][val];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({b, c - 'a'});
	}

/*
for(int i = 1; i <= n; i++) 
		for(int j = 'a'; j <= 'z'; j++)
			d[i][j - 'a'] = DMAX;

	for(int i = 1; i <= n; i++) {
		for(int j = 'a'; j <= 'z'; j++)
			dfs(i, j - 'a');
	}
	*/

	memset(state, -1, sizeof state);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int ok = get_s(i, j, 0);
			char c = ok ? 'A' : 'B';
			cout << c;
		}
		cout << '\n';
	}
/*
	for(int i = 1; i <= n; i++)  {

		for(int j = 1; j <= n; j++) {
			int ok = 0;
			for(auto it : v[i])
				if(d[it.first][it.second] >= d[j][it.second]) {
					cout << 'A';
					ok = 1;
					break;
				}
			if(!ok)
			cout << 'B';
			// if(d[i][0] <= d[j][0])
			// 	cout << 'B';
			// else cout << 'A';
		}
		cout << '\n';
	}
*/
	// dbg_v(d[1], 10);
}