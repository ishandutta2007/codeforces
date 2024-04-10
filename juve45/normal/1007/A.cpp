#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 100100;
int n, k, v[N], ans;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}


map <int, int> small;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> v[i], small[v[i]]++;

	sort(v + 1, v + n + 1);

	for(int i = n; i >= 1; i--) {
		auto it = small.lower_bound(v[i]);
		if(it != small.begin())
			it--;
		else 
			continue;
		small[it->first]--;
		if(small[it->first] == 0)
			small.erase(it->first);
		ans++;
	}

	cout << ans << '\n';
}