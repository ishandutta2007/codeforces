#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 
#define NMAX 
#define MMAX 

using namespace std;

int n, k, x, v[25], m, a, b, ANS = 100, conf, sz = 0, bt[25], bt2[25], sz2 = 0, use[35];
string s;
int vec[4200100], c[4200100];

template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

void dfs(int node, int conf) {
	use[node] = 1;
	for(int i = 0; i < n; i++)
		if(!use[i] && ((1 << i) & conf) && ((1 << i) & v[node])) 
			dfs(i, conf);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
		v[i] |= (1 << i);

	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		a--; b--;
		v[a] |= (1 << b);
		v[b] |= (1 << a);
	}

	for(int i = 1; i < (1 << n); i++) {
		int nr = __builtin_popcount(i);
		if(nr > n - 2) continue;
		
		if(nr == 1) {
			c[i] = 1;
			for(int j = 0; j < n; j++) 
				if((1 << j) & i) 
					vec[i] |= v[j];
			continue;
		}

		for(int j = 0; j < n; j++) 
			if((1 << j) & i) 
				vec[i] |= v[j];

		for(int j = 0; j < n; j++) 
			if(((1 << j) & i) != 0 && (vec[i - (1 << j)] & (1 << j)) != 0) 
				c[i] = max (c[i - (1 << j)], c[i]);
	}

	if(m == (n - 1) * n / 2) {
		cout << "0\n";
		return 0;
	}

	for(int i = 1; i < (1 << n); i++) {
		int nr = __builtin_popcount(i), ans = 0;
		if(nr > n - 2 || !c[i]) continue;
		
		for(int j = 0; j < n; j++) 
			if((1 << j) & i) 
				ans |= v[j];
		
		if(ans == ((1 << n) - 1) && ANS > nr) 
			ANS = nr, conf = i; 
	}

	cout << ANS << '\n';
	for(int i = 0; i < n; i++) {
		if((1 << i) & conf)
			cout << i + 1 << ' ';
	}
}