#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

long long n, k;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

long long optim(long long k) {
	long long nr = k / 50;
	k %= 50;
	nr += k / 10;
	k %= 10;
	nr += k / 5;
	k %= 5;
	return nr + k;
}
long long optim2(long long k) {
	long long nr = k / 50;
	k %= 50;
	nr += k / 5;
	k %= 5;
	return nr + k;
}

bitset<100000>b;
long long get(int n) {
	for(int i = 0; i <= n; i++)
	for(int j = 0; j <= n; j++)
	for(int k = 0; k <= n; k++) {
		if(i + j + k <= n) {
			b[i * 50 + j * 5 + k * 10 + n - i - j - k] = 1;
		}
	}
	return b.count();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	if(n <= 13) cout << get(n) << '\n';
	else cout << 1LL *get(13) + 1LL * (n - 13) * 49LL << '\n';
}