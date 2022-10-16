#include <bits/stdc++.h>

#define dbg(x) //cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 22;
long long n, k, ft[N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}


long long get(vector<int> v) {

	long long ans = 0;
	long long cif[10];
	unordered_set<int> use;
	memset(cif, 0, sizeof cif);
	for(auto i : v) cif[i] = 1;

	for(int ii = 0; ii < (1 << v.size()); ii++) {
		int f[10];
		memset(f, 0, sizeof f);
		for(int j = 0; j < v.size(); j++) {
			if((1<<j) & ii)
				f[v[j]]++;
		}

		int ok = 1;
		for(int i = 0; i < 10; i++)
			if(cif[i] && !f[i])
				ok = 0;

		if(!ok) continue;

		long long mask = 0;
		for(int i = 0; i < 10; i++){
			mask = mask * 20 + f[i];
		}
		if(use.count(mask))
			continue;

		use.insert(mask);

		long long tmp = ft[__builtin_popcount(ii)];

		for(int i = 0; i < 10; i++)
			tmp /= ft[f[i]];
		dbg(ii);
		dbg(tmp);
		ans += tmp;
	}
	return ans;

}


long long get2(vector<int> v) {

	long long ans = 0;
	long long cif[10];
	unordered_set<int> use;
	memset(cif, 0, sizeof cif);
	for(auto i : v) cif[i] = 1;

	for(int ii = 0; ii < (1 << v.size()); ii++) {
		int f[10];
		memset(f, 0, sizeof f);
		for(int j = 0; j < v.size(); j++) {
			if((1<<j) & ii)
				f[v[j]]++;
		}

		int ok = 1;
		for(int i = 1; i < 10; i++)
			if(cif[i] && !f[i])
				ok = 0;

		if(!ok) continue;

		long long mask = 0;
		for(int i = 0; i < 10; i++){
			mask = mask * 20 + f[i];
		}
		if(use.count(mask))
			continue;

		use.insert(mask);

		long long tmp = ft[__builtin_popcount(ii)];

		for(int i = 0; i < 10; i++)
			tmp /= ft[f[i]];
		dbg(ii);
		dbg(tmp);
		ans += tmp;
	}
	return ans;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	
	ft[0] = 1;
	for(int i = 1; i < 20; i++)
		ft[i] = ft[i - 1] * i;

	vector <int> v;
	while(n) {
		v.push_back(n % 10);
		n /= 10;
	}

	sort(v.begin(), v.end());

	long long ans = get(v);

	if(v[0] == 0) {
		swap(v[0], v[v.size() - 1]);
		v.pop_back();	
		sort(v.begin(), v.end());
		long long scad = get2(v);
		dbg(scad);
		ans -= scad;
	}

	cout << ans << '\n';

}