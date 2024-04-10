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


int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> d(n - 1);
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) cin >> b[i];
	if (a[0] != b[0]) {
		cout << "No\n";
	}
	else {
		vector<int> d1(n - 1);
		vector<int> d2(n - 1);
		for (int i = 0; i < n - 1; i++) {
			d1[i] = a[i + 1] - a[i];
			d2[i] = b[i + 1] - b[i];
		}
		sort(d1.begin(), d1.end());
		sort(d2.begin(), d2.end());
		for (int i = 0; i < n - 1; i++) {
			if (d1[i] != d2[i]) {
				cout << "No\n";
				return 0;
			}
		}
		cout << "Yes\n";
	}
	//system("pause");
	return 0;
}