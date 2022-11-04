#include<bits/stdc++.h>
#define INF 1000000000
#define MAX 1000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi a, prefmax, prefmin, suffmax, suffmin;
int n, m;

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
    	cin >> n >> m;
    	a.assign(n, vi(m));
    	prefmax.assign(n, vi(m + 1, -INF));
    	prefmin.assign(n, vi(m + 1, INF));
    	suffmax.assign(n, vi(m + 1, -INF));
    	suffmin.assign(n, vi(m + 1, INF));
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < m; j++) {
    			cin >> a[i][j];
    		}
    	}
    	for(int i = 0; i < n; i++) {
    		for(int j = 1; j <= m; j++) {
    			prefmax[i][j] = max(prefmax[i][j - 1], a[i][j - 1]);
    			prefmin[i][j] = min(prefmin[i][j - 1], a[i][j - 1]);
    		}
    		for(int j = m - 1; j >= 0; j--) {
    			suffmax[i][j] = max(suffmax[i][j + 1], a[i][j]);
    			suffmin[i][j] = min(suffmin[i][j + 1], a[i][j]);
    		}
    	}
    	bool ok = false;
    	for(int spl = 0; spl < m - 1; spl++) {
    		string ans = "";
    		for(int i = 0; i < n; i++) {
    			ans += 'R';
    		}
    		ans[0] = 'B';
    		set<pair<int, int>> s1, s2;
    		for(int i = 1; i < n; i++) {
    			s1.insert({prefmin[i][spl + 1], i});
    			s2.insert({suffmax[i][spl + 1], i});
    		}
    		queue<int> q;
    		q.push(0);
    		while(!q.empty()) {
    			int now = q.front();
    			q.pop();
    			ans[now] = 'B';
    			int maxhere = prefmax[now][spl + 1];
    			while(!s1.empty() && (*(s1.begin())).first <= maxhere) {
    				int v = (*(s1.begin())).second;
    				s1.erase(s1.begin());
    				q.push(v);
    				s2.erase(s2.find({suffmax[v][spl + 1], v}));
    			}
    			int minhere = suffmin[now][spl + 1];
    			while(!s2.empty() && (*(s2.rbegin())).first >= minhere) {
    				int v = (*(s2.rbegin())).second;
    				s2.erase(--s2.end());
    				q.push(v);
    				s1.erase(s1.find({prefmin[v][spl + 1], v}));
    			}
    		}
    		if(s1.size() != 0) {
    			ok = true;
    			cout << "YES\n";
    			cout << ans << ' ' << spl + 1 << '\n';
    			break;
    		}
    	}
    	if(!ok) {
    		for(int spl = 0; spl < m - 1; spl++) {
	    		string ans = "";
	    		for(int i = 0; i < n; i++) {
	    			ans += 'B';
	    		}
	    		ans[0] = 'R';
	    		set<pair<int, int>> s1, s2;
	    		for(int i = 1; i < n; i++) {
	    			s1.insert({prefmax[i][spl + 1], i});
	    			s2.insert({suffmin[i][spl + 1], i});
	    		}
	    		queue<int> q;
	    		q.push(0);
	    		while(!q.empty()) {
	    			int now = q.front();
	    			q.pop();
	    			ans[now] = 'R';
	    			int minhere = prefmin[now][spl + 1];
	    			while(!s1.empty() && (*(s1.rbegin())).first >= minhere) {
	    				int v = (*(s1.rbegin())).second;
	    				s1.erase(--s1.end());
	    				q.push(v);
	    				s2.erase(s2.find({suffmin[v][spl + 1], v}));
	    			}
	    			int maxhere = suffmax[now][spl + 1];
	    			while(!s2.empty() && (*(s2.begin())).first <= maxhere) {
	    				int v = (*(s2.begin())).second;
	    				s2.erase(s2.begin());
	    				q.push(v);
	    				s1.erase(s1.find({prefmax[v][spl + 1], v}));
	    			}
	    		}
	    		if(s1.size() != 0) {
	    			ok = true;
	    			cout << "YES\n";
	    			cout << ans << ' ' << spl + 1 << '\n';
	    			break;
	    		}
	    	}
	    }
	    if(!ok) {
	    	cout << "NO\n";
	    }

    }
}