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
    	set<int> s;
    	for(int i = 0; i < n; i++) {
    		s.insert(i);
    	}
    	for(int i = 0; i < m; i++) {
    		int a, b, c;
    		cin >> a >> b >> c;
    		--b;
    		if(s.find(b) != s.end()) {
    			s.erase(s.find(b));
    		}
    	}
    	int v = *(s.begin());
    	for(int i = 0; i < n; i++) {
    		if(v == i) {
    			continue;
    		}
    		cout << v + 1 << ' ' << i + 1 << '\n';
    	}
    }
}