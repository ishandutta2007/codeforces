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

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

int t, n;
string s[maxn];

int cal(char a, char b){
	return int(a - 'a') * 26 + int(b - 'a');
}
int cal(char a, char b, char c){
	return int(a - 'a') * 26 * 26 + int(b - 'a') * 26 + int(c - 'a');
}

int main(){
	fast_io;

	cin >> t;
	while(t--){
		cin >> n;
		bool ok = 0;
		for(int i = 0; i < n; i++){
			cin >> s[i];
			if(s[i][0] == s[i][Sz(s[i]) - 1]) ok = 1;
		}
		if(ok){
			cout << "YES\n";
			continue;
		}
		set<int> s2, s3, s23;
		for(int i = n; i--;){
			if(Sz(s[i]) == 2){
				int x = cal(s[i][0], s[i][1]);
				if(s2.find(x) != s2.end()) ok = 1;
				if(s23.find(x) != s23.end()) ok = 1;
				s2.insert(cal(s[i][1], s[i][0]));
			}
			else{
				int x = cal(s[i][0], s[i][1], s[i][2]);
				if(s3.find(x) != s3.end()) ok = 1;
				x = cal(s[i][0], s[i][1]);
				if(s2.find(x) != s2.end()) ok = 1;
				s23.insert(cal(s[i][2], s[i][1]));
				s3.insert(cal(s[i][2], s[i][1], s[i][0]));
			}
		}
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}