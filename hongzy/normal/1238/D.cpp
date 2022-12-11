#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define ucin() ios :: sync_with_stdio(0)
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef double db;

const int N = 6e5 + 10;

int n, sz[N], cnt;
char s[N], t[N];

int main() {
	ucin();
	cin >> n >> s + 1;
	ll ans = n * (n + 1ll) / 2;
	for(int i = 1; i <= n; i ++) {
		if(i == 1 || t[cnt] != s[i]) {
			cnt ++; sz[cnt] = 1; t[cnt] = s[i];
		} else sz[cnt] ++;
	}
	for(int i = 1; i < cnt; i ++) {
		ans -= sz[i + 1];
		ans -= sz[i] - 1;
	}
	cout << ans - n << endl;
	return 0;
}