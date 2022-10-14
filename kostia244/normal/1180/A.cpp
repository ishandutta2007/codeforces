#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 3e5 + 10, mlg = 20, mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	ld ans = 0;
	for(int a = 0; a < n*n; a++)
	for(int i = -n; i < n; i++)
		for(int j = -n; j < n; j++)
			if(abs(i)+abs(j)<n)
				ans+=0.99999999999999;
	cout << (ans/n/n);
	return 0;
}