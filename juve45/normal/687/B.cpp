#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

int n, k, c;
map<int, int> d;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int cnt(int nr, int div) {
	int ret = 0;
	while(nr % div == 0)
		nr /= div, ret++;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;

	for(int i = 2; i * i <= k; i++)
		while(k % i == 0)
			d[i]++, k /= i;
	if(k > 1)
		d[k]++;

	for(int i = 1; i <= n; i++) {
		cin >> c;
		vector <pair<int, int> > v;
		for(auto p : d) 
			if(cnt(c, p.st) >= p.nd)
				v.push_back(p);

		for(auto p : v)
			d.erase(p.st);
	}

	if(d.size() == 0) 
		cout << "Yes\n";
	else
		cout << "No\n";
}