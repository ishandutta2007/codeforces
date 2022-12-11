#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pb push_back
#define fs first
#define sc second
const int N = 2000 + 10;
const int mo = 1e9 + 7;
int ans[N][N], n;
int q(int x, int y) {
	int cnt = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			if(ans[x][i] > ans[y][j]) 
				cnt ++;
	return cnt;
}
int main() {
	ios :: sync_with_stdio(false);
	cin >> n; int cur = 0;
	for(int j = 1; j <= n; j ++) {
		if(j & 1) {
			for(int i = n; i >= 1; i --)
				ans[i][j] = ++ cur;
		} else {
			for(int i = 1; i <= n; i ++)
				ans[i][j] = ++ cur;
		}
	}

	for(int i = 1; i <= n; i ++, cout << endl)
		for(int j = 1; j <= n; j ++) cout << ans[i][j] << ' ';
	return 0;
}