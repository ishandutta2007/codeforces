#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 102, mod = (119 << 23) + 1;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
int tmw= 0;
string s;
void mv(int c, int p) {
	int t=p;
	while(t<s.size()&&s[t]-'0'!=c)t++;
	if(t==s.size()) {
		tmw = 1<<20;
		return;
	}
	while(t-->p) swap(s[t], s[t+1]), tmw++;
}
void norm() {
	while(s.back()=='0') s.pop_back(), tmw++;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string t;
	cin >> t;
	reverse(all(t));
	int ans = 1<<20;
	for(pi i : {pi{0, 0}, pi{2, 5}, pi{5, 0}, pi{7, 5}}) {
		s = t;
		tmw = 0;
		mv(i.second, 0);
		mv(i.first, 1);
//		cout << s << "\n";
		norm();
		ans = min(ans, tmw);
	}
	if(ans == 1<<20) ans = -1;
	cout << ans;
}