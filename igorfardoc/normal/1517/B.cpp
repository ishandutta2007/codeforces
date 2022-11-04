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
	    vector<multiset<int>> s(n);
	    for(int i = 0; i < n; i++) {
	    	for(int j = 0; j < m; j++) {
	    		int a;
	    		cin >> a;
	    		s[i].insert(a);
	    	}
	    }
	    vvi ans(n, vi(m));
	    for(int i = 0; i < m; i++) {
	    	vi res(n);
	    	int min1 = 1000000001;
	    	int id1 = -1;
	    	for(int j = 0; j < n; j++) {
	    		if(*(s[j].begin()) < min1) {
	    			min1 = *(s[j].begin());
	    			id1 = j;
	    		}
	    	}
	    	res[id1] = min1;
	    	s[id1].erase(s[id1].find(min1));
	    	for(int j = 0; j < n; j++) {
	    		if(j == id1) {
	    			continue;
	    		}
	    		res[j] = *(--(s[j].end()));
	    		s[j].erase(--(s[j].end()));
	    	}
	    	for(int j = 0; j < n; j++) {
	    		ans[j][i] = res[j];
	    	}
	    }
	    for(int i = 0; i < n; i++) {
	    	for(int j = 0; j < m; j++) {
	    		cout << ans[i][j] << ' ';
	    	}
	    	cout << '\n';
	    }
	}
}