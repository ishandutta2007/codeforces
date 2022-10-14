    #pragma GCC optimize("trapv")
    #include<bits/stdc++.h>
    #define all(x) x.begin(), x.end()
    #define pb push_back
    using namespace std;
    using ll = long long;
    using vi = vector<ll>;
    using pi = pair<ll, ll>;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
     
    int main() {
    	ios::sync_with_stdio(0);
    	cin.tie(0);
    	int n;
    	string s;
    	cin >> n >> s;
    	map<char, int> cnt;
    	for(auto i : s) cnt[i]++;
    	if((cnt['B']&1)&&(cnt['W']&1)) return cout << -1, 0;
    	vi ans;
    	char x = (cnt['B']&1)?'W':'B';
    	for(int i = 0; i+1 < s.size(); i++) {
    		if(s[i]==x) {
    			ans.pb(i+1);
    			s[i+1] = (s[i+1]=='W'?'B':'W');
    		}
    	}
    	cout << ans.size() << '\n';
    	for(auto i : ans) cout << i << " ";
    }