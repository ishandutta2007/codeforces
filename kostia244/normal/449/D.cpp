#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<20, mod = 1e9 + 7;
int a[maxn], p[maxn], n;
void add(int &a, int b) {
	a += b;
	if(a >= mod) a -= mod;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	p[0] = 1;
	for(int i = 1; i < maxn; i++) p[i] = 2ll*p[i-1]%mod;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		a[t]++;
	}
	for(int j = 1; j < maxn; j<<=1)
		for(int i = 0; i < maxn; i++)
			if(j&~i) add(a[i], a[i^j]);
	for(int i = 0; i < maxn; i++) a[i] = p[a[i]];
	for(int j = 1; j < maxn; j<<=1)
		for(int i = 0; i < maxn; i++)
			if(j&~i)add(a[i], mod-a[i^j]);
	cout << a[0];
	return 0;
}