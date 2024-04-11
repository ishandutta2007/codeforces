#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = (1ll<<50);
int n;
ll ans = 0, last = -inf;
vector<ll> red, blue;
ll solve(ll l, ll r) {
	ll rgap = 0, bgap = 0;
	ll rdist = red.empty()?0:red.back()-red[0];
	ll bdist = blue.empty()?0:blue.back()-blue[0];
	if(l!=-inf) {
		if(!red.empty()) {
			rdist += red[0]-l;
			rgap = max(rgap, red[0]-l);
		}
		if(!blue.empty()) {
			bdist += blue[0]-l;
			bgap = max(bgap, blue[0]-l);
		}
	}
	if(r!=inf) {
		if(!red.empty()) {
			rdist += r-red.back();
			rgap = max(rgap, r-red.back());
		}
		if(!blue.empty()) {
			bdist += r-blue.back();
			bgap = max(bgap, r-blue.back());
		}
	}
	if(l!=-inf&&r!=inf) {
		rdist = bdist = r-l;
	}
	ll p = -inf;
	for(auto i : red) {
		if(p!=-inf) rgap = max(rgap, i-p);
		p = i;
	}
	p = -inf;
	for(auto i : blue) {
		if(p!=-inf) bgap = max(bgap, i-p);
		p = i;
	}

	ll ans = 0;
	if(red.empty()&&blue.empty()) ans = ((l==-inf||r==inf)?0:r-l);
	else if(red.empty()||blue.empty()) {
		ans = ((l==-inf||r==inf)?0:r-l) + max(rdist, bdist);
		if(!(l==-inf||r==inf)) ans -= max(rgap, bgap);
	} else ans = rdist + bdist + min(0ll, (r-l) - rgap - bgap);
	red.clear();
	blue.clear();
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	char type;
	ll pos;
	for(int i = 0; i < n; i++) {
		cin >> pos >> type;
		if(type=='R') red.push_back(pos);
		if(type=='B') blue.push_back(pos);
		if(type=='P') {
			ans += solve(last, pos);
			last = pos;
		}
	}
	ans += solve(last, inf);
	cout << ans;
}