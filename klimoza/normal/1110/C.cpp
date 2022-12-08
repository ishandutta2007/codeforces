#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")												
#pragma GCC optimize("rename-registers")									
#pragma GCC optimize("move-loop-invariants")								
#pragma GCC optimize("unswitch-loops")											
#pragma GCC optimize("function-sections")										
#pragma GCC optimize("data-sections")										
#pragma GCC optimize("branch-target-load-optimize")							
#pragma GCC optimize("branch-target-load-optimize2") 						
#pragma GCC optimize("btr-bb-exclusive")
#pragma comment(linker, "/stack:200000000")


#include <iostream>
#include <vector>	
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 1e18;
ll mod = 998244353;
double eps = 1e-7;

int gcd(int a, int b) {
	//cout << a << " " << b << endl;
	if (!b) return a;
	return gcd(b, a % b);
}

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int q;
	cin >> q;
	ll n;
	vector<int> y = { 1, 1, 1, 73, 89, 1, 4681, 1, 1, 299593, 178481, 1082401 };
	for (int k = 0; k < q; k++) {
		ll l;
		cin >> n;
		l = n;
		ll b = 0;
		bool fl = false;
		int h = -1;
		for (int i = 25; i >= 0; i--) {
			if (n < (1 << i)) {
				if (!fl) continue;
				else b += (1 << i);
			}
			else {
				if (!fl) h = i;
				fl = true;
				n -= (1 << i);
			}
		}
		//cout << h << " " << n << " " << b << " " << "wa\n";
		if (b) {
			cout << (l ^ b) << endl;
		}
		else {
			if (h % 2 == 0) {
				cout << y[h / 2 - 1] << endl;
			}
			else {
				
				ll g = 0;
				for (int i = h; i >= 0; i -= 2) {
					g += (1 << i);
				}
				cout << g / 2 << endl;
			}
		}
	}
	
	//system("pause");
	/*
	
	*/
	return 0;
}