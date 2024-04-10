#include<bits/stdc++.h>
#define BOUND 707
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int a[500001];
int ans[BOUND][BOUND];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
   	int q;
   	cin >> q;
   	for(int i = 0; i < q; i++) {
   		int t, x, y;
   		cin >> t >> x >> y;
   		if(t == 1) {
   			a[x] += y;
   			for(int i = 1; i < BOUND; i++) {
   				ans[i][x % i] += y;
   			}
   		} else {
   			if(x >= BOUND) {
   				int res = 0;
   				for(int i = y; i <= 500000; i+=x) {
   					res += a[i];
   				}
   				cout << res << '\n';
   			} else {
   				cout << ans[x][y] << '\n';
   			}
   		}
   	}
}