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
    int t;
    cin >> t;
    while(t--) {
    	int n, m;
    	cin >> n >> m;
    	int sum = 0;
    	int min1 = 1000;
    	int am = 0;
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < m; j++) {
    			int a;
    			cin >> a;
    			sum += abs(a);
    			min1 = min(min1, abs(a));
    			if(a < 0) {
    				++am;
    			}
    		}
    	}
    	if(am % 2 == 1) {
    		sum -= min1 * 2;
    	}
    	cout << sum << '\n';
    }
}