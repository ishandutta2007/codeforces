#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 1010
#define NMAX 
#define MMAX 

using namespace std;

int n, k, x;
string s;
bool ok = true;
vector <int> v[DMAX];

template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v)
		out << e << '\n';
	return out;
}


int dfs(int node) {
	//dbg(v[node].size());
	if(v[node].size() == 0)
		return 1;
	int nr = 0;
	for(auto x : v[node]) {
		nr += dfs(x);
	}
	if(nr < 3) ok = 0; 
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 2; i <= n; i++) {
		cin >> k;
		v[k].push_back(i);
	}	
	dfs(1);
	if(ok) cout << "Yes\n";
	else cout << "No";
	return 0;
}