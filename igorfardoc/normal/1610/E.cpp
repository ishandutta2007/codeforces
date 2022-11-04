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
    	int n;
    	cin >> n;
    	vi a(n);
    	unordered_map<int, int> am;
    	am.reserve(4 * n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    		++am[a[i]];
    	}
    	int ans = n;

    	for(int i = 0; i < n; i++) {
    		if(i != n - 1 && a[i + 1] == a[i]) {
    			continue;
    		}
    		int cansave = am[a[i]];
    		vi deleted;
    		int now = a[i];
    		while(true) {
    			int id1 = upper_bound(a.begin(), a.end(), now) - a.begin();
    			//cout << id1 << endl;
    			if(id1 == n) {
    				break;
    			}
    			++cansave;
    			now = a[i] + (a[id1] - a[i]) * 2 - 1;
    		}
    		ans = min(ans, n - cansave);
    	}
    	if(ans == n) {
    		ans = 0;
    	}
    	cout << ans << '\n';
    }

}