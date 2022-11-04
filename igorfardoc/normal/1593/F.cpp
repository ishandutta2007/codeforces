#include<bits/stdc++.h>
#define N 40
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
bool dp[N + 1][N][N][2 * N + 1];
int r[N + 1][N][N][2 * N + 1];
int from[N + 1][N][N][2 * N + 1];

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
    	int n, a, b;
    	cin >> n >> a >> b;
    	string s;
    	cin >> s;
    	vi mass(n);
    	for(int i = 0; i < n; i++) {
    		mass[i] = s[i] - '0';
    	}
    	for(int i = 0; i <= n; i++) {
    		for(int j = 0; j < a; j++) {
    			for(int k = 0; k < b; k++) {
    				for(int l = 0; l <= 2 * n; l++) {
    					dp[i][j][k][l] = false;
    				}
    			}
    		}
    	}
    	dp[0][0][0][n] = true;
    	r[0][0][0][n] = -1;
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < a; j++) {
    			for(int k = 0; k < b; k++) {
    				for(int l = 0; l <= 2 * n; l++) {
    					if(!dp[i][j][k][l]) {
    						continue;
    					}
    					dp[i + 1][(j * 10 + mass[i]) % a][k][l + 1] = true;
    					r[i + 1][(j * 10 + mass[i]) % a][k][l + 1] = i;
    					from[i + 1][(j * 10 + mass[i]) % a][k][l + 1] = j;
    					dp[i + 1][j][(k * 10 + mass[i]) % b][l - 1] = true;
    					r[i + 1][j][(k * 10 + mass[i]) % b][l - 1] = r[i][j][k][l];
    					from[i + 1][j][(k * 10 + mass[i]) % b][l - 1] = k;
    				}
    			}
    		}
    	}
    	int id1 = -1;
    	for(int i = 1; i < 2 * n; i++) {
    		if(dp[n][0][0][i] && abs(n - id1) > abs(n - i)) {
    			id1 = i;
    		}
    	}
    	if(id1 == -1) {
    		cout << "-1\n";
    		continue;
    	}
    	string res = "";
    	for(int i = 0; i < n; i++) {
    		res += "B";
    	}
    	int i = n;
    	int j = 0;
    	int k = 0;
    	while(i > 0) {
    		if(r[i][j][k][id1] == i - 1) {
    			res[i - 1] = 'R';
    			j = from[i][j][k][id1];
    			--i;
    			--id1;
    		} else {
    			k = from[i][j][k][id1];
    			--i;
    			++id1;
    		}
    	}
    	cout << res << '\n';

    }
}