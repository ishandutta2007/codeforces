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
    	int n, k;
    	cin >> n >> k;
    	string s;
    	cin >> s;
    	int prev = -1;
    	bool wasW = false;
    	vector<pair<int, int>> a;
    	for(int i = 0; i < n; i++) {
    		if(s[i] == 'W') {
    			if(!wasW) {
    				prev = -1;
    				wasW = true;
    			} else if(prev != -1) {
    				a.push_back({i - prev, prev});
    				prev = -1;
    			}
    		} else {
    			if(prev == -1) {
    				prev = i;
    			}
    		}
    	}
    	sort(a.begin(), a.end());
    	for(int i = 0; i < a.size(); i++) {
    		if(a[i].first > k) {
    			break;
    		}
    		k -= a[i].first;
    		for(int j = a[i].second; j < n && s[j] == 'L'; j++) {
    			s[j] = 'W';
    		}
    	}
    	int last = -1;
    	for(int i = 0; i < n; i++) {
    		if(s[i] == 'W') {
    			last = i;
    		}
    	}
    	for(int i = last; i >= 0; i--) {
    		if(s[i] == 'L' && k > 0) {
    			k--;
    			s[i] = 'W';
    		}
    	}
    	for(int i = 0; i < n; i++) {
    		if(s[i] == 'L' && k > 0) {
    			k--;
    			s[i] = 'W';
    		}
    	}
    	//cout << s << endl;
    	int res = 0;
    	for(int i = 0; i < n; i++) {
    		if(s[i] == 'W') {
    			if(i == 0 || s[i - 1] == 'L') {
    				res++;
    			} else {
    				res += 2;
    			}
    		}
    	}
    	cout << res << '\n';
    }
}