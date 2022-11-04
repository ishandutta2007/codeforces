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
    	for(int i = 0; i < n; i++) {
    		char c;
    		cin >> c;
    		a[i] = (int)(c - '0') - 1;
    	}
    	map<int, int> am;
    	am[0] = 1;
    	int now = 0;
    	ll ans = 0;
    	for(int i = 0; i < n; i++) {
    		now += a[i];
    		ans += am[now];
    		++am[now];
    	}
    	cout << ans << '\n';
    }
}