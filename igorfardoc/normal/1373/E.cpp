#include<bits/stdc++.h>
#define INF 1000000000000000000ll
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

ll to_ll(vi a) {
	ll now = 1;
	ll ans = 0;
	for(int i = a.size() - 1; i >= 0; i--) {
		ans += now * a[i];
		now *= 10;
	}
	return ans;
}

ll get_min(int sum) {
	vi ans;
	if(sum == 0) {
		return 0;
	}
	while(sum) {
		ans.push_back(min(sum, 9));
		sum -= min(sum, 9);
	}
	reverse(ans.begin(), ans.end());
	return to_ll(ans);
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
    int t;
    cin >> t;
    while(t--) {
    	int n, k;
    	cin >> n >> k;
    	ll ans = INF;
    	for(int i = 0; i + k <= 9; i++) {
    		int sumend = (i + k) * (i + k + 1) / 2 - i * (i - 1) / 2;
    		if(sumend > n) {
    			break;
    		}
    		int nnow = n - sumend;
    		if(nnow % (k + 1) == 0) {
    			ans = min(ans, get_min(nnow / (k + 1)) * 10 + i);
    		}
    	}
    	if(k >= 1) {
    		for(int y = 1; y <= k; y++) {
    			int start = 10 - y;
    			int sumend = 45 - start * (start - 1) / 2;
    			sumend += (k - y + 1) * (k - y) / 2;
    			if(sumend > n) {
    				continue;
    			}
    			int nnow = n - sumend;
    			for(int sum10 = 0; sum10 <= nnow / y; sum10++) {
    				int sum1 = sum10;
    				if((nnow - sum1 * y) % (k + 1 - y) != 0) {
    					continue;
    				}
    				int sum2 = (nnow - sum1 * y) / (k + 1 - y);
    				vi a;
    				if(sum2 > sum1 + 1 || sum2 == 0) {
    					continue;
    				}
    				while(true) {
    					if(sum2 == sum1 + 1) {
    						a.push_back(min(8, sum1));
    						sum1 -= min(8, sum1);
    						ll ch = get_min(sum1);
    						ll st = 1;
    						for(int c = 0; c < a.size(); c++) {
    							st *= 10;
    						}
    						ch *= st;
    						for(int c = a.size() - 1; c >= 0; c--) {
    							st /= 10;
    							ch += st * a[c];
    						}
    						ans = min(ans, ch * 10 + start);
    						break;
    					}
    					if(sum1 - 9 < 0 || sum1 - 8 < sum2) {
    						break;
    					}
    					a.push_back(9);
    					sum1 -= 9;
    				}
    			}
    		}
    	}
    	if(ans == INF) {
    		cout << "-1\n";
    	} else {
    		cout << ans << '\n';
    	}
    	//cout << endl;
    }
}