#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int lp[MAX + 1];
vi pr;

ll solve(vi b) {
	int prev = 0;
	vi dst;
	for(int i = 0; i < b.size(); i++) {
		if(b[i] == 1) {
			++prev;
		} else {
			dst.push_back(prev);
			prev = 0;
		}
	}
	dst.push_back(prev);
	/*for(const auto& el : dst) {
		cout << el << ' ';
	}*/
	//cout << endl;
	ll ans = 0;
	for(int i = 0; i < dst.size() - 1; i++) {
		ans += (ll)dst[i] * dst[i + 1];
		ans += dst[i] + dst[i + 1];
	}
	//cout << ans << endl;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    for(int i = 2; i <= MAX; i++) {
    	if(lp[i] == 0) {
    		lp[i] = i;
    		pr.push_back(i);
    	}
    	for(int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= MAX; j++) {
    		lp[i * pr[j]] = pr[j];
    	}
    }
    int t;
    cin >> t;
    while(t--) {
    	int n, e;
    	cin >> n >> e;
    	vi a(n);
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    	}
    	ll ans = 0;
    	for(int mod = 0; mod < e; mod++) {
    		vi b;
    		for(int i = mod; i < n; i+=e) {
    			if(a[i] == 1) {
    				b.push_back(1);
    			} else if(lp[a[i]] == a[i]) {
    				b.push_back(2);
    			} else {
    				ans += solve(b);
    				b.clear();
    			}
    		}
    		ans += solve(b);
    	}
    	cout << ans << '\n';
    }
}