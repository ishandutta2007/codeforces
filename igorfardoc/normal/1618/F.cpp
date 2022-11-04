#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vi to_v(ll a) {
	vi ans;
	while(a) {
		ans.push_back(a % 2);
		a /= 2;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

bool ins(vi a, vi b) {
	if(a.size() > b.size()) {
		return false;
	}
	for(int i = 0; i < (int)b.size() - a.size() + 1; i++) {
		for(int j = 0; j < i; j++) {
			if(b[j] != 1) {
				return false;
			}
		}
		bool ok = true;
		for(int j = 0; j < a.size(); j++) {
			if(a[j] != b[j + i]) {
				ok = false;
				break;
			}
		}
		for(int j = a.size() + i; j < b.size(); j++) {
			if(b[j] != 1) {
				ok = false;
				break;
			}
		}
		if(ok) {
			return true;
		}
	}
	return false;
}

bool can(ll a, ll b) {
	vi fir = to_v(a);
	vi sec = to_v(b);
	if(ins(fir, sec)) {
		return true;
	}
	reverse(fir.begin(), fir.end());
	return ins(fir, sec);
}

bool get_ans(ll x, ll y) {
	if(x == y) {
		return true;
	}
	if(can((x << 1) + 1, y)) {
		return true;
	}
	while(x % 2 == 0) {
		x /= 2;
	}
	return can(x, y);
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
    ll x, y;
    cin >> x >> y;
    if(get_ans(x, y)) {
    	cout << "YES\n";
    } else {
    	cout << "NO\n";
    }
}