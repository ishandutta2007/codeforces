#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<int, int>;
const int maxn = 1e5 + 55, mod = 1e9 + 7;
string s;
int n;
pair<int, pi> ans = {0, {0, 0}};
bool match(char o, char c) {
	if(o=='(') return c==')';
	return c==']';
}
void solve(int S) {
	vector<pi> st;
	for(int cur = 0, i = S; i < n; i++) {
		if(s[i] == '('||s[i] == '[') st.pb({i, cur});
		else if(!st.empty()&&match(s[st.back().first], s[i])) {
			st.pop_back();
			cur += s[i]==']';
			int t = cur, x = S;
			if(!st.empty()) {
				t -= st.back().second;
				x = st.back().first+1;
			}
			ans = max(ans, {t, {x, i-x+1}});
		} else {
			solve(i+1);
			break;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	n = s.size();
	solve(0);
	if(ans.first==0) return cout << 0, 0;
	cout << ans.first << '\n';
	cout << s.substr(ans.second.first, ans.second.second) << '\n';
}