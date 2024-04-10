#include<bits/stdc++.h>
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<vector<ll>>> d(n, vector<vector<ll>>(m, vector<ll>(2)));
    vector<vector<bool>> a(n, vector<bool>(m, true));
    ll sum = 0;
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < m; j++) {
    		d[i][j][0] = 1;
    		d[i][j][1] = 1;
    		if(i != 0) {
    			d[i][j][0] += d[i - 1][j][1];
    		}
    		if(j != 0) {
    			d[i][j][1] += d[i][j - 1][0];
    		}
    		sum += d[i][j][0] + d[i][j][1];
    	}
    }
    int am = n * m;
    for(int o = 0; o < q; o++) {
    	int x, y;
    	cin >> x >> y;
    	--x;
    	--y;
    	if(a[x][y]) {
    		--am;
    		sum -= d[x][y][0];
    		sum -= d[x][y][1];
    	} else {
    		++am;
    		sum += d[x][y][0];
    		sum += d[x][y][1];
    	}
    	ll dt = d[x][y][0];
    	if(a[x][y]) {
    		dt *= -1;
    	}
    	for(int i = y + 1; i < m; i++) {
    		int p1 = x + i - y - 1;
    		int p2 = p1 + 1;
    		if(p1 >= n) {
    			break;
    		}
    		d[p1][i][1] += dt;
    		if(a[p1][i]) {
    			sum += dt;
    		} else {
    			break;
    		}
    		if(p2 >= n) {
    			break;
    		}
    		d[p2][i][0] += dt;
    		if(a[p2][i]) {
    			sum += dt;
    		} else {
    			break;
    		}
    	}
    	dt = d[x][y][1];
    	if(a[x][y]) {
    		dt *= -1;
    	}
    	for(int i = x + 1; i < n; i++) {
    		int p1 = y + i - x - 1;
    		int p2 = p1 + 1;
    		if(p1 >= m) {
    			break;
    		}
    		d[i][p1][0] += dt;
    		if(a[i][p1]) {
    			sum += dt;
    		} else {
    			break;
    		}
    		if(p2 >= m) {
    			break;
    		}
    		d[i][p2][1] += dt;
    		if(a[i][p2]) {
    			sum += dt;
    		} else {
    			break;
    		}
    	}
    	a[x][y] = !a[x][y];
    	cout << sum - am << '\n';
    }
}