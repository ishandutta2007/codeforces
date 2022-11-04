#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
ll p[19];

void precalc() {
	p[0] = 1;
	for(int i = 1; i < 19; i++) {
		p[i] = p[i - 1] * 10;
	}
}
vi to_v(ll a) {
	vi ch;
	while(a > 0) {
		ch.push_back(a % 10);
		a /= 10;
	}
	if(ch.size() == 0) {
		ch.push_back(0);
	}
	reverse(ch.begin(), ch.end());
	return ch;
}

int get_sign(ll a, int num) {
	auto ch = to_v(a);
	return ch[num - 1];
}

int get_small(ll val) {
	ll now = 9;
	ll p = 1;
	for(int am = 1; am <= 10; am++) {
		if(now * am >= val) {
			ll ch = (val - 1) / am + 1;
			ll ch1 = p + ch - 1;
			val -= (ch - 1) * am;
			return get_sign(ch1, val);
		} else {
			val -= now * am;
		}
		now *= 10;
		p *= 10;
	}
}

__int128 get_sum(ll l, ll r) {
	if(l > r) {
		return 0;
	}
	__int128 res = (__int128)r * (r + 1) / 2;
	res -= (__int128)l * (l - 1) / 2;
	return res;
}

__int128 calc(ll mid) {
	if(mid == 0) {
		return 0;
	}
	auto v = to_v(mid);
	__int128 amch = 0;
	ll now = 9;
	for(int i = 1; i <= v.size(); i++) {
		if(i != v.size()) {
			amch += get_sum(mid - p[i - 1] + 1 - p[i] + p[i - 1] + 1, mid - p[i - 1] + 1) * i;
		} else {
			amch += get_sum(1, mid - p[i - 1] + 1) * i;
		}
		now *= 10;
	}
	return amch;
}

int get_num(ll a) {
	ll l = 0;
	ll r = 2000000000ll;
	while(r - l > 1) {
		ll mid = (l + r) / 2;
		__int128 amch = calc(mid);
		//cout << mid << ' ' << (ll)amch << endl;
		if(amch >= a) {
			r = mid;
		} else {
			l = mid;
		}
	}
	//cout << "L: " << l << endl;
	return get_small(a - calc(l));
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
    precalc();
    //cout << (ll)calc(10) << endl;
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
    	ll a;
    	cin >> a;
    	cout << get_num(a) << '\n';
    }
}