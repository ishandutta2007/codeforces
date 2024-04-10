#include <bits/stdc++.h>

#define dbg(x) //cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 1000100
#define LG 22
#define MMAX 1

using namespace std;

int n, k, x, y, a, b, sz;
int s[DMAX], use[DMAX], t[DMAX], mark[DMAX];

vector <int> v[DMAX], lift[DMAX];


template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

void dfs(int k, int d) {
	use[k] = 1;
	for(int i = 0; i <= 20; i++)
		if((1 << i) > sz) break; 
		else lift[k].push_back(s[sz - (1 << i)]);
	
	s[sz++] = k;
	use[k] = d;

	for(auto i : v[k])
		if(!use[i])
				t[i] = k,
				dfs(i, d + 1);
	sz--;
}


int getDist(int k) {
	if(mark[k] == 1) return 0;
	int ans = 1;
	for(int i = 20; i >= 0; i--) {
		if(lift[k].size() <= i) continue;
		if(!mark[lift[k][i]]) 
			k = lift[k][i], 
			ans += (1 << i);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(n, 1);

	k = n - k;
	k--;
	dbg(k);
	dbg(lift[n - 1]);
	mark[n] = 1;
	for(int i = n - 1; i >= 1; i--) {
		dbg(i);
		dbg(getDist(i));
		if(getDist(i) <= k) {
			int x = i;
			while(mark[x] == 0) mark[x] = 1, k--, x = t[x];
		}
	}

	for(int i = 1; i < n; i++)
		if(!mark[i])
			cout << i << ' ';
}