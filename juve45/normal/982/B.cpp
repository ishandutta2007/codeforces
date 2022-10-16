#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 
#define NMAX 
#define MMAX 

using namespace std;

int n, k, w;
string s;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;

	set<pair<int, int> > free, occ;

	for(int i = 1; i <= n; i++) {
		cin >> w;
		free.insert({w, i});
	}

	cin >> s;
	for(auto i : s) {
		if(i == '0') {
			auto x = *free.begin();
			cout << x.second << ' ';
			occ.insert(x);
			free.erase(x);
		}
		else{
		  auto x = *occ.rbegin();
		  occ.erase(x);
		  cout << x.second << ' ';
		}
	}
}