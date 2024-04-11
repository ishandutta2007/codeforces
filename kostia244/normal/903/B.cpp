#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 998244353ll;

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	ll h, a, c;
	ll h1, a1;
	cin >> h >> a >> c >> h1 >> a1;
	vi ans;
	while(h1 > 0) {
		if(h > a1 || h1 <= a)
			ans.pb(0), h1 -= a, h-=a1;
		else
			ans.pb(1), h += c-a1;
	}
	cout << ans.size() << "\n";
	for(auto i : ans)
		if(i) cout << "HEAL\n";
		else cout << "STRIKE\n";
}