#include <bits/stdc++.h>

#define ld long double
#define fs first
#define sc second
#define vc vector
#define pr pair
#define mp make_pair
#define pb push_back
#define len(v) (int)v.size()
#define all(v) v.begin(), v.end()

#pragma GCC optimize("Ofast")

using namespace std;

const int INF = 2e9;
const int MAXN = 5e5+10;
int x[MAXN];
int counts[MAXN];

signed main(){
	#ifdef __linux__
		freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m, k, n, s;
	cin >> m >> k >> n >> s;
	vc<int> a(m);
	for (auto &v : a){
		cin >> v;
	}
	int needtomake = 0;
	for (int i = 0; i < s; i++){
		int v;
		cin >> v;
		if (x[v] == 0){
			needtomake++;
		}
		x[v]++;
	}
	int last = 0;
	for (int i = 0; i < m; i++){
		while(last < m && needtomake > 0){
			counts[a[last]]++;
			if (counts[a[last]] == x[a[last]]){
				needtomake--;
			}
			last++;
		}
		if (needtomake > 0){
			cout << "-1";
			return 0;
		}
		int ans = i % k + max(0, last - i - k);
		if (m - i >= k){
			if (ans <= m - k * n){
				cout << ans << "\n";
				for (int ii = 0; ii < i % k; ii++){
					cout << ii + 1 << ' ';
				}
				for (int j = i, erased = 0; j < last && erased < last - i - k; j++){
					if (counts[a[j]] > x[a[j]]){
						counts[a[j]]--;
						cout << j + 1 << ' ';
						erased++;
					}
				}
				return 0;
			}
		}
		x[a[i]]++;
		if (counts[a[i]] < x[a[i]]){
			needtomake++;
		}
	}
}