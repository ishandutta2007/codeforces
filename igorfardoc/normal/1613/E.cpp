#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vector<string> a;
int n, m;

bool check(int i, int j) {
	if(i < 0 || j < 0 || i >= n || j >= m) {
		return false;
	}
	if(a[i][j] == 'L' || a[i][j] == '#') {
		return false;
	}
	int amnot = 0;
	int amcan = 0;
	for(int dx = -1; dx <= 1; dx++) {
		for(int dy = -1; dy <= 1; dy++) {
			if(abs(dx) + abs(dy) != 1) {
				continue;
			}
			int x = i + dx;
			int y = j + dy;
			if(x < 0 || y < 0 || x >= n || y >= m || a[x][y] == '#') {
				continue;
			}
			if(a[x][y] == 'L' || a[x][y] == '+') {
				++amcan;
			} else {
				++amnot;
			}
		}
	}
	return amcan > 0 && amnot <= 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--) {
    	cin >> n >> m;
    	a.resize(n);
    	int x = 0;
    	int y = 0;
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    		for(int j = 0; j < m; j++) {
    			if(a[i][j] == 'L') {
    				x = i;
    				y = j;
    			}
    		}
    	}
    	vector<vector<bool>> used(n, vector<bool>(m, false));
    	queue<pair<int, int>> q;
    	for(int dx = -1; dx <= 1; dx++) {
    		for(int dy = -1; dy <= 1; dy++) {
    			if(abs(dx) + abs(dy) != 1) {
    				continue;
    			}
    			int x1 = x + dx;
    			int y1 = y + dy;
    			if(check(x1, y1)) {
    				q.push({x1, y1});
    				used[x1][y1] = true;
    				a[x1][y1] = '+';
    			}
    		}
    	}
    	while(!q.empty()) {
    		int x = q.front().first;
    		int y = q.front().second;
    		q.pop();
    		for(int dx = -1; dx <= 1; dx++) {
	    		for(int dy = -1; dy <= 1; dy++) {
	    			if(abs(dx) + abs(dy) != 1) {
	    				continue;
	    			}
	    			int x1 = x + dx;
	    			int y1 = y + dy;
	    			if(check(x1, y1) && !used[x1][y1]) {
	    				q.push({x1, y1});
	    				used[x1][y1] = true;
	    				a[x1][y1] = '+';
	    			}
	    		}
	    	}
    	}
    	for(int i = 0; i < n; i++) {
    		cout << a[i] << '\n';
    	}
    }
}