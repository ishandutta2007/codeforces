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
    	int ans = n + m;
    	set<int> s;
    	for(int i = 0; i < n; i++) {
    		int a;
    		cin >> a;
    		s.insert(a);
    	}
    	for(int i = 0; i < m; i++) {
    		int a;
    		cin >> a;
    		if(s.find(a) != s.end()) {
    			--ans;
    		}
    	}
    	cout << n + m - ans << '\n';
    }
}