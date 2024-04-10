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

int n, k, s, h, m;
std::vector<int> v;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> s;
	for(int i = 1; i <= n; i++) {
		cin >> h >> m;
		v.push_back(h * 60 + m);
	}

	sort(v.begin(), v.end());

	int lastok = 0;
	for(int i = 0; i < v.size(); i++) {
		if(v[i] - lastok > s) {
			cout << lastok / 60 << ' ' << lastok % 60 << '\n';
			return 0;
		}
		lastok = v[i] + s + 1;
	}		cout << lastok / 60 << ' ' << lastok % 60 << '\n';
	
}