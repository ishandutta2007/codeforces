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
    	string s;
    	cin >> s;
    	int n = s.size();
    	vi len;
    	int prev = -1;
    	for(int i = 0; i < n; i++) {
    		if(s[i] == '1' && prev == -1) {
    			prev = i;
    		} else if(s[i] == '0') {
    			if(prev != -1) {
    				len.push_back(i - prev);
    				prev = -1;
    			}
    		}
    	}
    	if(prev != -1) {
    		len.push_back(n - prev);
    	}
    	sort(len.begin(), len.end());
    	int ans = 0;
    	for(int i = (int)len.size() - 1; i >= 0; i-=2) {
    		ans += len[i];
    	}
    	cout << ans << '\n';
    }
}