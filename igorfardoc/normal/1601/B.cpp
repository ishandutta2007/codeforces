#include<bits/stdc++.h>
#define INF 1000000000
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
    int n;
    cin >> n;
    vi a(n), b(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    vi dst(n + 1, INF);
    dst[n] = 0;
    queue<int> q;
    q.push(n);
    set<int> free;
    for(int i = 0; i < n; i++) {
    	free.insert(i);
    }
    vi prev(n + 1);
    while(!q.empty()) {
    	int v = q.front();
    	if(v == 0) {
    		break;
    	}
    	q.pop();
    	int u = v + b[v - 1];
    	int r = u - 1;
    	int l = u - a[u - 1];
    	while(true) {
    		auto it = free.lower_bound(l);
    		if(it == free.end() || *it > r) {
    			break;
    		}
    		//cout << v << ' ' << u << ' ' << *it << endl;
    		dst[*it] = dst[v] + 1;
    		q.push(*it);
    		prev[*it] = v;
    		free.erase(it);
    	}
    }
    if(dst[0] == INF) {
    	cout << -1;
    } else {
    	cout << dst[0] << '\n';
    	int now = 0;
    	vi ans;
    	while(true) {
    		if(now == n) {
    			break;
    		}
    		ans.push_back(now);
    		now = prev[now];
    	}
    	for(int i = ans.size() - 1; i >= 0; i--) {
    		cout << ans[i] << ' ';
    	}
    }
}