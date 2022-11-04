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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    set<int> s;
    for(int i = 1; i < n; i++) {
    	for(int j = 1; j < m; j++) {
    		if(a[i - 1][j] == 'X' && a[i][j - 1] == 'X') {
    			s.insert(j);
    		}
    	}
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
    	int l, r;
    	cin >> l >> r;
    	--l;
    	--r;
    	auto it = s.upper_bound(l);
    	if(it == s.end() || *it > r) {
    		cout << "YES\n";
    	} else {
    		cout << "NO\n";
    	}
    }
}