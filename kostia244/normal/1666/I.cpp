// Problem: I. Interactive Treasure Hunt
// Contest: Codeforces - 2021-2022 ICPC, NERC, Northern Eurasia Onsite (Unrated, Online Mirror, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/contest/1666/problem/I
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
int A = 2, B = 1, C = 1, D = 3;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n, m;
		cin >> n >> m;
		auto dig = [&](int x, int y) {
			x++,y++;
			cout << "DIG " << x << " " << y << endl;
			if(local) {
				x = (A == x && B == y) || (C == x && D == y);
				cout << ">D " << x << endl;
			} else cin >> x;
			return x;
		};
		auto scan = [&](int x, int y) {
			x++,y++;
			cout << "SCAN " << x << " " << y << endl;
			if(local) {
				x = abs(x-A)+abs(x-C)+abs(y-B)+abs(y-D);
				cout << ">S " << x << endl;
			} else cin >> x;
			return x;
		};
		int s1 = scan(0, 0);
		int s2 = scan(0, m-1) - 2*(m-1);
		int apc = (s1+s2)/2;
		int bpd = (s1-s2)/2;
		int s3 = scan(apc/2, 0);
		int s4 = scan(0, bpd/2);
		int amc = s3 - bpd;
		int bmd = s4 - apc;
		int x1 = (apc+amc)/2;
		int x2 = apc - x1;
		int y1 = (bpd+bmd)/2;
		int y2 = bpd - y1;
		if(dig(x1, y1)) {
			dig(x2, y2);
		} else {
			dig(x1, y2);
			dig(x2, y1);
		}
	});
	
}