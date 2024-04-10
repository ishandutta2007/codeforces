
/*
    Im not gonna run away, I never go back on my word! Thats my nindo: my ninja way. Naruto
























































*/

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second 
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define speed_up ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) (int)x.size()
#define szc(x) (int)strlen(x)
#define all(x) x.begin(), x.end()
#define debug cerr << "OK\n";
#define ub upper_bound
#define lb lower_bound 
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef set <int> si;
typedef set <ll> sll;
typedef multiset <int> msi;
typedef multiset <ll> msll;
typedef map <int, int> mi;
typedef map <ll, int> mll;
 
const int N = 2e5 + 2;
const int M = 2e6 + 2;
const int mod = 998244353;
const int inf = 2e9 + 3;
const ll INF = 1e16;

/*
	BIN POISK EBANA V ROT
	DP EBANA V ROT
	DO EBANA V ROT
*/

int T, n, was[10];
char s[N];

int main() {
	scanf("%d\n", &T);
	while (T--) {
		scanf("%s\n", s + 1);
		n = szc(s + 1);		
		for (int i = 0; i < 10; ++i)
			was[i] = 0;
		for (int i =1; i <= n; ++i) {
			was[s[i] - '0']++;
		}
		int ans = 0;
		for (int i = 0; i < 10; ++i)
			ans = max(ans, was[i]);
		for (int a = 0; a < 10; ++a) {
			for (int b = 0; b < 10; ++b) {
				if (a == b)
					continue;
				int last = b, sum = 0;
				for (int i = 1; i <= n; ++i) {
					if (last == b && s[i] - '0' == a) {
						sum++;
						last = a;
					}
					else if (last == a && s[i] - '0' == b) {
						sum++;
						last = b;
					}
				}
				ans = max(ans, sum - (sum % 2));
			}
		}
		printf("%d\n", n - ans);
	}
}

/*
	Timus: 288481RF
	CodeForces: fractal
*/