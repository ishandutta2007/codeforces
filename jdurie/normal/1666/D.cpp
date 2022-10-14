#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(char i = l; i < (r); i++)
#define all(a) begin(a), end(a)
#define K first
#define V second

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	G(tc) while(tc--) {
		GS(s) GS(t)
		F(c, 'A', 'Z' + 1) while(count(all(s), c) > count(all(t), c))
			s = s.substr(0, s.find(c)) + s.substr(s.find(c) + 1);
		cout << (s == t ? "YES\n" : "NO\n");
	}
}