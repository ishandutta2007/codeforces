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

	int n, m;
	cin >> n >> m;
	vector<int> p(2 * n);
	for (int i = 0; i < 2 * n; i++) {
		cin >> p[i];
	}
	vector<int> f(2 * n, -1);
	vector<pair<int, int>> pa(m);
	for (int i = 0; i < m; i++) {
		cin >> pa[i].first >> pa[i].second; pa[i].first--; pa[i].second--;
		f[pa[i].first] = pa[i].second;
		f[pa[i].second] = pa[i].first;
	}
	int t;
	cin >> t;
	int cnt = 0;
	int last = -1;
	vector<bool> used(2 * n);
	while (cnt < 2 * n) {
		if (t == 1) {
			if (last != -1 && f[last] != -1 && !used[f[last]]) {
				cout << f[last] + 1 << endl;
				cnt++;
				used[f[last]] = true;
				t = 2;
			}
			else {
				bool fl = false;
				for (int i = 0; i < m; i++) {
					//cout << i << " " << pa[i].first << endl;
					if (!used[pa[i].first]) {
						fl = true;
						if (p[pa[i].first] > p[pa[i].second]) {
							cout << pa[i].first + 1 << endl;
							used[pa[i].first] = true;
							cnt++;
						}
						else {
							cout << pa[i].second + 1 << endl;
							used[pa[i].second] = true;
							cnt++;
						}
						break;
					}
				}
				//cout << cnt << endl;
				if (fl) {
					t = 2;
					continue;
				}
				int ind = -1;
				for (int i = 0; i < 2 * n; i++) {
					if (!used[i] && (ind == -1 || p[i] > p[ind])) {
						ind = i;
					}
				}
				used[ind] = true;
				cnt++;
				cout << ind + 1 << endl;
				t = 2;
			}
		}
		else {
			cin >> last; last--;
			used[last] = true;
			cnt++;
			t = 1;
		}
	}
	//system("pause");
	return 0;
}