#include <bits/stdc++.h>

using namespace std;
#define DIM  2007
#define DIM2 107
#define INF 10E16
#define MAXN 2750137
#define LG 18
#define MODULO 1000000007
#define MODULO2 MODULO*2
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef ll arr[DIM];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
typedef ll table[DIM][DIM2];
typedef ll arr2[DIM2];
typedef pair<string, string> ps;
struct pp {
	ll a, b;
	bool operator <(const pp& V)const {
		if (a == V.a)return b < V.b;
		return a < V.a;
	}
	bool operator ==(const pp& V)const {
		if (a == V.a && b == V.b)return 1;
		return 0;
	}
};

ll n;
string s1, s2;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
		ll l = s1.length(), p = 0;
		ll hh = 0;
		for (int i = 0; i < l; i++) {
			ll flag = 0;
			while (s2[p] != s1[i] && p < s2.length()) {
				if (i>0 && s2[p] != s1[i - 1])break;
				if (i == 0)break;
				p++;
			}
			if (s2[p] == s1[i])flag = 1;
			p++;
			if (flag == 0) {
				cout << "NO" << endl;
				hh = 1;
				break;
			}
		}
		if (hh == 1)continue;
		while (p < s2.length()) {
			if (s2[p] != s1[l - 1]) {
				hh = 1;
				cout << "NO" << endl;
				break;
			}
			p++;
		}
		if (hh == 0) {
			cout << "YES" << endl;
		}
	}
}