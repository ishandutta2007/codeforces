#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 111;
int n, k, p[N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	n /= 2;
	for(int i = 1; i <= n; i++) cin >> p[i];

	int ans1 = 0, ans2 = 0;
	sort(p + 1, p + n + 1);
	for(int i = 1; i <= n; i++)
	{
		ans1 += abs(p[i] - (2 * i - 1));
		ans2 += abs(p[i] - 2 * i);
	}
	cout << min(ans1, ans2);
}