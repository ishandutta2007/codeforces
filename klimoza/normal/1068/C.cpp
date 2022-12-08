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

	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> a(n);
	for (int i = 0; i < n; i++) {
		a[i].push_back({ i, i });
	}
	int t1, t2;
	int cnt = n;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2; t1--; t2--;
		a[t1].push_back({ cnt, t1 });
		a[t2].push_back({ cnt, t2 });
		cnt++;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i].size() << endl;
		for (auto f : a[i]) {
			cout << f.first + 1 << " " << f.second + 1 << endl;
		}
	}
	//system("pause");
	return 0;
}