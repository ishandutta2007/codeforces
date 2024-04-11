#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,sse,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 2e5 + 55, mlg = 18, mod =1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, loc = 0, A[] = {0, 1, 2, 1, 2,
						  3, 4, 3, 2};
int a(int i) {
	if(i>n) i-=n;
	if(loc) {
		return A[i];
	}
	cout << "? " << i << endl;
	int t;
	cin >> t;
	return t;
}
int b(int i) {
	return a(i)-a(i+n/2);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int l = 1, r = 1+(n/2);
	if(n%4) return (cout << "! -1", cout.flush()), 0;
	int L = b(l), R = b(r);
	if(L==0) return (cout << "! " << l, cout.flush()), 0;
	if(R==0) return (cout << "! " << r, cout.flush()), 0;
	while(l<r) {
		int m = (l+r)/2;
		int t = b(m);
		if(t==0) return (cout << "! " << m, cout.flush()), 0;
		if((t<0)==(L<0))
			l = m+1;
		else
			r = m-1;
	}
	if(b(l)==0) return (cout << "! " << l, cout.flush()), 0;
	return (cout << "! -1", cout.flush()), 0;
	return 0;
}