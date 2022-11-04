#include<bits/stdc++.h>
#define INF 1000000000000000001ll
#define INF1 ((__int128)1000000000000000000ll * 1000000000000000000ll)
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
    	ll x; 
    	cin >> n >> k >> x;
    	string s;
    	cin >> s;
    	vector<int> a;
    	int prev = -1;
    	for(int i = 0; i < n; i++) {
    		if(s[i] == 'a') {
    			if(prev != -1) {
    				a.push_back((i - prev) * k + 1);
    				prev = -1;
    			}
    			a.push_back(-1);
    		} else {
    			if(prev == -1) {
    				prev = i;
    			}
    		}
    	}
    	if(prev != -1) {
			a.push_back((n - prev) * k + 1);
		}
		vector<__int128> can(a.size() + 1, 1);
		for(int i = a.size() - 1; i >= 0; i--) {
			if(a[i] == -1) {
				can[i] = can[i + 1];
			} else {
				if(can[i + 1] >= INF) {
					can[i] = INF;
				} else {
					can[i] = can[i + 1] * a[i];
				}
			}
		}
		string res = "";
		for(int i = 0; i < a.size(); i++) {
			if(a[i] == -1) {
				res += 'a';
				continue;
			}
			while(x > can[i + 1]) {
				res += 'b';
				x -= can[i + 1];
			}
		}
		//cout << (ll)can[1] << endl;
		cout << res << '\n';
	}
}