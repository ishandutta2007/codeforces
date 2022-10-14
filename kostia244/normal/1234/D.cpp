#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 998244353ll;
set<int> pos[26];
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	string s;
	cin >> s;
	for(int i = 0; i<s.size(); i++)
		pos[s[i]-'a'].insert(i);
	int q, t, i, l, r;
	char c;
	cin >> q;
	while(q--) {
		cin >> t;
		if(t == 1) {
			cin >> i >> c, i--;
			pos[s[i]-'a'].erase(i);
			s[i]=c;
			pos[s[i]-'a'].insert(i);
		} else {
			cin >> l >> r, l--, r--;
			int ans = 0;
			for(int i = 0; i < 26; i++) {
				auto it = pos[i].lower_bound(l);
				ans += (it!=pos[i].end()&&*it<=r);
//				if(i < 3){
//					for(auto j : pos[i]) cout << j << " ";
//				cout << "=\n";}
			}
			cout << ans << "\n";
		}
	}
}