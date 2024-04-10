#include <bits/stdc++.h>

using namespace std;
#define DIM 300007
#define DIM2 100007
#define DIM3 200007
#define INF 10E16
#define MAXN 2750137
#define LG 18
#define MODULO 998244353
#define fi first
#define sc second
#define pb push_back
#define pu push
#define sz size()
#define po(power) ( 1<<power)
#define schnell ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

typedef  long long ll;
typedef long double ld;
const ld eps = 0.00000001;
const ll MASK(1 << 10);
const ll MC = 5007;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef ll msk[MASK + 7];
typedef vector<ll> vec;
typedef pair<string, string> ps;
#define forn(i,n) for (ll i = 1;i<=n;i++)
#define fore(y,i,n) for (ll i = y;i<=n;i++)
string s;
ll Check(string &x) {
	ll len = x.length();
	for (ll i = 0; i < len / 2; i++) {
		if (x[i] != x[len - 1 - i])return 1;
	}
	return 0;
}
int main()
{
	schnell;
	cin >> s;
	ll len = s.length();
	if (len % 2 == 0) {
		ll flag;
		for (ll i = 1; i <= len / 2; i++) {
			flag = 0; ll r = 1, p = i - 1;
			for (ll j = i; r <= len / 2; j++) {
				if (s[j] != s[p]) {
					flag = 1;
					break;
				}
				r++;
				p--;
				if (p < 0)p = len - 1;
			}
			if (flag == 1)continue;
			p = i - 1;
			for (ll j = 0; j < len ; j++) {
				if (s[j] != s[p]) {
					flag = 1;
					break;
				}
				p--;
				if (p < 0)p = len - 1;
			}
			if (flag == 1) {
				cout << 1 << endl;
				return 0;
			}
		}
	}
	else {
		ll flag;
		for (ll i = 1; i < len / 2; i++) {
			flag = 0; ll r = 1, p = i - 1;
			for (ll j = i; r <= len / 2; j++) {
				if (s[j] != s[p]) {
					flag = 1;
					break;
				}
				r++;
				p--;
				if (p < 0)p = len - 1;
			}
			if (flag == 1)continue;
			p = i - 1;
			for (ll j = 0; j < len; j++) {
				if (s[j] != s[p]) {
					flag = 1;
					break;
				}
				p--;
				if (p < 0)p = len - 1;
			}
			if (flag == 1) {
				cout << 1 << endl;
				return 0;
			}
		}
	}
	
	string s1="";
	for (ll i = 0; i < len/2; i++) {
		s1 += s[i];
		if (Check(s1)) {
			cout << 2 << endl;
			return 0;
		}
	}
	cout << "Impossible" << endl;
}