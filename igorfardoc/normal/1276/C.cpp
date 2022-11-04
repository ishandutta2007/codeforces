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
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end());
    map<int, int> d, d1;
    int now = 0;
    for(int i = 0; i < n; i++) {
    	if(d.find(a[i]) == d.end()) {
    		d[a[i]] = now++;
    		d1[now - 1] = a[i];
    	}
    	a[i] = d[a[i]];
    }
    vi bigger(n + 1, 0);
    int now1 = 0;
    vi am(now, 0);
    vi am1(n + 1, 0);
    for(int i = 0; i < n; i++) {
    	am[a[i]]++;
    }
    for(int i = 0; i < now; i++) {
    	am1[am[i]]++;
    }
    for(int i = n; i >= 0; i--) {
    	now1 += am1[i];
    	bigger[i] = now1;
    }
    int x1 = 1;
    int y1 = 1;
    now1 = 0;
    for(int i = 1; i <= n; i++) {
    	int x = i;
    	int elements = bigger[i] * i + now1;
    	int y = elements / x;
    	if(x > y) {
    		continue;
    	}
    	if(x * y > x1 * y1) {
    		x1 = x;
    		y1 = y;
    	}
    	now1 += am1[i] * i;
    }
    cout << x1 * y1 << '\n';
    cout << x1 << ' ' << y1 << '\n';
    vi b;
    for(int i = 0; i < now; i++) {
    	if(am[i] >= x1) {
    		for(int j = 0; j < x1; j++) {
    			b.push_back(i);
    		}
    	}
    }
    for(int i = 0; i < now; i++) {
    	if(am[i] < x1) {
    		for(int j = 0; j < am[i]; j++) {
    			b.push_back(i);
    		}
    	}
    }
    int here = 0;
    int x = 0;
    int y = 0;
    vvi ans(x1, vi(y1, -1));
    for(int i = 0; i < x1 * y1; i++) {
    	if(ans[x][y] != -1) {
    		x = (x + 1) % x1;
    	}
    	ans[x][y] = d1[b[here++]];
    	x = (x + 1) % x1;
    	y = (y + 1) % y1;
    }
    for(int i = 0; i < x1; i++) {
    	for(int j = 0; j < y1; j++) {
    		cout << ans[i][j] << ' ';
    	}
    	cout << '\n';
    }
}