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
ll mod = 1e9 + 7;
double eps = 1e-7;


int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> a(n);
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		maxi = max(maxi, a[i]);
	}
	vector<int> h(maxi + 1);
	h[0] = 1;
	for (int i = 0; i < n; i++) {
		vector<int> _h;
		for (int j = 1; j <= sqrt(a[i]); j++) {
			if (a[i] % j == 0) {
				_h.push_back(j);
				if (j * j != a[i]) _h.push_back(a[i] / j);
			}
		}
		sort(_h.begin(), _h.end());
		for (int j = _h.size() - 1; j >= 0; j--) {
			h[_h[j]] += h[_h[j] - 1];
			h[_h[j]] %= mod;
		}
	}
	ll sum = 0;
	bool fl = false;
	for (int i : h) {
		if (!fl) {
			fl = true;
			continue;
		}
		sum += i;
		sum %= mod;
	}
	cout << sum << endl;
	//system("pause");
	return 0;
}