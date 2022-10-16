#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 44;
int n, k, a[N], m, ans;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> m >> n;
	for(int i = 1; i <= n; i++) {
		cout << 1 << endl;
		cin >> a[i];
		if(a[i] == 0)
			return 0;
		a[i] = -a[i];
	}

	int l = 1;
	int r = m;

	int cnt = 1;
	while(l != r) {
		dbg(l);
		dbg(r);
		int mid = (l + r) / 2;
		cout << mid << endl;
		cin >> ans;
		if(ans == 0)
			return 0; 
		ans *= a[cnt++];
		if(cnt == n + 1) cnt = 1;
		if(ans == -2)
			return 0;
		if(ans > 0)
			r = mid - 1;
		else 
			l = mid + 1;
	}
	cout << l << endl;
	cin >> ans;
	if(ans != 0) {
		while(1);
	}
	return 0;
}