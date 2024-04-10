#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 
#define NMAX 
#define MMAX 

using namespace std;

long long n, k, x;

vector <long long> v1, v2, v[66];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	// out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int msb(long long k) {
	for(long long i = 60; i >= 0; i--)
		if((1LL << i) & k)
			return i;
}

void put(long long k) {
	v[msb(k)].push_back(k);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(long long i = 1; i <= n; i++) cin >> x, put(x);

	for(long long i = 60; i >= 0; i--) {
		if(v[i].size() == 0) continue;
		// dbg(i);
		// dbg(v[i]);
		// dbg(v1);
		long long off = v[i][0], j = 1, k = 0;
		v2.push_back(v[i][0]);
		while(j < v[i].size() && k < v1.size()) {
			// dbg(off);
			if((off & (1LL << i)) == 0) {
				v2.push_back(v[i][j]);
				off ^= v[i][j];
				j++;
				continue;
			}
			v2.push_back(v1[k]);
			off ^= v1[k];
			k++;
		}
		if((off & (1LL << i)) == 0) {
				v2.push_back(v[i][j]);
				off ^= v[i][j];
				j++;
		}
		// dbg(v2);
		if(j < v[i].size()) 
			return cout << "No\n", 0;
		while(k < v1.size()) v2.push_back(v1[k]), k++;
		v1 = v2;
		v2.clear();
	}
	cout << "Yes\n" << v1 << '\n';
}