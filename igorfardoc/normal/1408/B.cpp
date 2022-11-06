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
    	int n, k;
    	cin >> n >> k;
    	set<int> s;
    	for(int i = 0; i < n; i++) {
    		int a;
    		cin >> a;
    		s.insert(a);
    	}
    	if(k == 1 && s.size() > 1) {
    		cout << -1 << '\n';
    	} else if(s.size() <= k) {
    		cout << 1 << '\n';
    	} else {
    		cout << (s.size() - k - 1) / (k - 1) + 2 << '\n';
    	}
    }
}