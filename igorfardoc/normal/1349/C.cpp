#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n, m, t;
    cin >> n >> m >> t;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vector<vector<int>> dst(n, vector<int>(m, INF));
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < m; j++) {
    		bool ok = true;
    		for(int dx = -1; dx <= 1; dx++) {
    			for(int dy = -1; dy <= 1; dy++) {
    				if(abs(dx) + abs(dy) != 1) {
    					continue;
    				}
    				int x = i + dx;
    				int y = j + dy;
    				if(x < 0 || y < 0 || x >= n || y >= m) {
    					continue;
    				}
    				if(a[i][j] == a[x][y]) {
    					ok = false;
    					break;
    				}
    			}
    			if(!ok) {
    				break;
    			}
    		}
    		if(!ok) {
    			q.push({i, j});
    			dst[i][j] = 1;
    		}
    	}
    }
    while(!q.empty()) {
    	int i = q.front().first;
    	int j = q.front().second;
    	q.pop();
    	for(int dx = -1; dx <= 1; dx++) {
			for(int dy = -1; dy <= 1; dy++) {
				if(abs(dx) + abs(dy) != 1) {
					continue;
				}
				int x = i + dx;
				int y = j + dy;
				if(x < 0 || y < 0 || x >= n || y >= m) {
					continue;
				}
				if(dst[x][y] == INF) {
					dst[x][y] = dst[i][j] + 1;
					q.push({x, y});
				}
			}
		}
	}
	while(t--) {
		int i, j;
		ll p;
		cin >> i >> j >> p;
		--i;
		--j;
		if(dst[i][j] == INF || dst[i][j] > p) {
			cout << a[i][j] << '\n';
			continue;
		}
		if((p - dst[i][j]) % 2 == 1) {
			cout << a[i][j] << '\n';
		} else {
			cout << (char)('1' + '0' - a[i][j]) << '\n';
		}
	}
}