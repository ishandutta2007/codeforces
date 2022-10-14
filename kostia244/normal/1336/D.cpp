// Problem: D. Yui and Mahjong Set
// Contest: Codeforces - Codeforces Round #635 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1336/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const int local = 0;
vector<int> OA,A = {0, 1, 1, 0, 0, 1};
int n, x, y;
vector<int> inc,a;
array<int, 2> add(int v) {
	inc[v]++;
	cout << "+ " << v << endl;
	int a, b;
	if(!local) {
		cin >> a >> b;
	} else{
		a = 0, b = 0;
		A[v]++;
		for(int i = 1; i <= n; i++)
			a += A[i]*(A[i]-1)*(A[i]-2)/6;
		for(int i = 3; i <= n; i++)
			b += A[i]*A[i-1]*A[i-2];
		cout << "[" << a << ", " << b << "]\n";
	}
	x = a-x;swap(x, a);
	y = b-y;swap(y, b);
	return {a, b};
}
int get(int p) {
	assert(a[p] != -1);
	return a[p] + inc[p];
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	if(!local) cin >> n >> x >> y;
	else {
		OA = A;
		n = A.size()-1;x=y=0;
		for(int i = 1; i <= n; i++)
			x += A[i]*(A[i]-1)*(A[i]-2)/6;
		for(int i = 3; i <= n; i++)
			y += A[i]*A[i-1]*A[i-2];
	}
	inc.resize(n+1);
	a.resize(n+1, -3);
	vector<int> b(n+1, -3);
	auto deduce = [](ll x) {
		if(x == 0) return 2;
		int n = 3;
		while(n*(n-1)*(n-2)/6 - (n-1)*(n-2)*(n-3)/6 < x) n++;
		return n;
	};
	auto [_, S] = add(1);
	if(S != 0) {
		auto [u, v] = add(2);
		b[2] = v;
		a[2] = !u ? 1 : deduce(u)-1;
		auto [x, y] = add(3);
		b[3] = y;
		a[3] = !x ? 1 : deduce(x)-1;
		a[1] = deduce(add(1)[0])-2;
		b[3] -= (a[1]+1)*(a[2]+1);
	} else {
		auto [u, v] = add(2);
		if(v == 0) {
			a[3] = 0;
			auto [x, y] = add(3);
			auto [_, B] = add(1);
			a[2] = B-1;
			a[1] = deduce(_) - 2;
			b[3] = y - (a[1]+1)*(a[2]+1);
		} else {
			a[2] = 0;
			auto [x, y] = add(1);
			a[1] = deduce(x)-2;
			a[3] = y;
			b[3] = add(3)[1] - (a[1]+2)*(a[2]+1);
		}
	}
	//very sad
	for(int i = 4; i < n; i++) {
		auto [x, y] = add(i);
		a[i] = b[i-1] == 0 ? 0 : deduce(x)-1;
		b[i] = y - get(i-1)*get(i-2);
	}
	
	for(int i = 3; i < n; i++)
		y -= get(i-2)*get(i-1)*get(i);
	a[n] = y/(get(n-1)*get(n-2));
	cout << "! ";
	for(int i = 1; i <= n; i++) 
		cout << a[i] << " ";
	cout << endl;
	// for(int i = 1; i <= n; i++)
		// assert(OA[i] == a[i]);
}