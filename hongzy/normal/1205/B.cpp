#include <bits/stdc++.h>
using namespace std;
 
#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define ucin() ios :: sync_with_stdio(0)
 
typedef map<int, int> mii;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
 
const int N = 1e5 + 10;
const int M = 255;
 
int n, cnt[65], ans, dis[M][M];
vector<int> arr[65];
bool G[M][M];
ll a[N];
 
int main() {
	ucin(); cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		if(!a[i]) i --, n --;
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j <= 62; j ++) {
			if(a[i] & (1ll << j)) {
				cnt[j] ++;
				if(cnt[j] <= 2) arr[j].push_back(i);
			}
		}
	}
	bool tag = 0;
	for(int i = 0; i <= 62; i ++)
		if(cnt[i] >= 3) tag = 1;
	if(tag) {
		cout << 3 << endl;
		return 0;
	}
	ans = 2e9 + 10;
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j <= 62; j ++) {
			if(a[i] & (1ll << j)) {
				for(int v : arr[j]) if(v != i) {
					G[v][i] = G[i][v] = 1;
				}
			}
		}
	}
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			dis[i][j] = i == j ? 0 : (G[i][j] ? 1 : 1000000010);
	for(int k = 1; k <= n; k ++) {
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++) 
				if(i != j && i != k && j != k && G[i][k] && G[k][j] && dis[i][j] != 1000000010)
					ans = min(ans, dis[i][j] + 2);
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++) 
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	}
	if(ans == 2e9 + 10) ans = -1;
	cout << ans << endl;
	return 0;
}