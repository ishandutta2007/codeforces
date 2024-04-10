#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 200100;
int n, k, a[N];
map <int, int> m;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(int i =1 ; i<= n; i++) {
		cin >> a[i]; 
		m[a[i]]++;
	}
	sort(a + 1, a + n + 1);
	

	int ans = 0;
	for(int i = 2; i <= n; i++)
		if(a[i] - a[i - 1] > k && a[i] > a[i - 1])
			ans += m[a[i - 1]];

	ans+= m[a[n]];

	cout << ans << '\n';
}