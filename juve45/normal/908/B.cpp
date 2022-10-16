#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 55
#define NMAX 
#define MMAX 

using namespace std;

int n, k, x, m, mp[DMAX][DMAX], ans;
string s[DMAX], str;

pair<int, int> ex, st;

template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v)
		out << e << ' ';
	out << '\n';
	return out;
}

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

bool valid(int x, int y) {
	if(x <= 0 || y <= 0) return 0;
	if(x > n || y > m) return 0;
	if(mp[x][y] == 1) return 0;
	return 1;
}

bool check(vector<int>p){

	pair<int, int> pos = st;
	for(int i = 0; i < str.size(); i++) {
		int cmd = str[i] - '0';

		if(valid(pos.first + dx[p[cmd]], pos.second + dy[p[cmd]]))
			pos.first += dx[p[cmd]], pos.second += dy[p[cmd]];
		else 
			return 0;
		if(pos == ex) return 1;
	}
	return 0;

}

int main()
{
	ios_base::sync_with_stdio(false);
	
	char val[255];
	
	val['.'] = val['S'] = val['E'] = 0;
	val['#'] = 1;

	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		for(int j = 0; j < s[i].size(); j++)
		{
			if(s[i][j] == 'E') ex = {i, j + 1};
			if(s[i][j] == 'S') st = {i, j + 1};
			mp[i][j + 1] = val[s[i][j]];
		}
	}

	cin >> str;

	//int perm[] = {0, 1, 2, 3};
	vector <int> perm;
	perm.push_back(0);
	perm.push_back(1);
	perm.push_back(2);
	perm.push_back(3);
	do{
		if(check(perm))
		{
			ans++;
			//cerr << perm;
		}

	}
	while(next_permutation(perm.begin(), perm.end()));
	cout << ans << '\n';
}