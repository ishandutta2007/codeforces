#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

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

const int N = 300100;
int n, k, m, a[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) 
		cin >> a[i];

	int nr0 = 0, j = 0, ans = -1000, ii, jj;
	for(int i = 1; i <= n; i++) {
		nr0 += 1 - a[i];

		while(nr0 > k) {
			j++;
			nr0 -= 1 - a[j];
		}

		if(i - j > ans) {
			ans = i - j;
			ii = i; 
			jj = j;
		}

	}
	cout << ii - jj << '\n';
	// dbg(ii);
	// dbg(jj);
	for(int i = jj + 1; i <= ii; i++)
		a[i] = 1;

	for(int i = 1; i <= n; i++)
		cout << a[i] << ' ';

}