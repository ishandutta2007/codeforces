#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int am1[2000000];

int _gcd(int a, int b) {
	if(b == 0) {
		return a;
	}
	return _gcd(b, a % b);
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
    	int n;
    	cin >> n;
    	vi a(n);
    	map<int, int> am;
    	for(int i = 0; i < n; i++) {
    		cin >> a[i];
    		++am[a[i]];
    	}
    	bool ok = false;
    	for(auto& el : am) {
    		if(el.second >= n / 2) {
    			cout << "-1\n";
    			ok = true;
    			break;
    		}
    	}
    	if(ok) {
    		continue;
    	}
    	vi check;
    	for(int i = 0; i < n; i++) {
    		for(int j = i + 1; j < n; j++) {
    			int here = abs(a[i] - a[j]);
    			for(int k = 1; k * k <= here; k++) {
    				if(here % k == 0) {
    					check.push_back(k);
    					check.push_back(here / k);
    				}
    			}
    		}
    	}
    	sort(check.begin(), check.end());
    	for(int k = check.size() - 1; k >= 0; k--) {
    		int i = check[k];
    		vector<int> pos;
    		bool ok = false;
    		for(int j = 0; j < n; j++) {
    			int val = (a[j] + 1000000) % i;
    			am1[val]++;
    			pos.push_back(val);
    			if(am1[val] >= n / 2) {
    				ok = true;
    				break;
    			}
    		}
    		for(const auto& el : pos) {
    			am1[el] = 0;
    		}
    		if(ok) {
    			cout << i << '\n';
    			break;
    		}
    	}
    }
}