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
    	int ans = n;
    	vector<char> st;
    	for(int i = 0; i < n; i++) {
    		if(st.empty() || s[i] == 'A') {
    			st.push_back(s[i]);
    		} else {
    			st.pop_back();
    			ans -= 2;
    		}
    	}
    	cout << ans << '\n';
    }
}