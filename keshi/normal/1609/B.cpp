//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, q, cnt;
string s;

ll cal(ll i){
	if(i < 0 || i + 2 >= n) return 0;
	return (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c');
}

int main(){
	fast_io;
	
	cin >> n >> q;
	cin >> s;
	for(ll i = 0; i < n; i++){
		cnt += cal(i);
	}
	for(ll i = 0; i < q; i++){
		ll x;
		char c;
		cin >> x >> c;
		x--;
		cnt -= cal(x) + cal(x - 1) + cal(x - 2);
		s[x] = c;
		cnt += cal(x) + cal(x - 1) + cal(x - 2);
		cout << cnt << "\n";
	}
	
	return 0;
}