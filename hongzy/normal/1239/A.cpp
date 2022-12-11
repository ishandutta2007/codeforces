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

const int N = 2e5 + 10;
const int mo = 1e9 + 7;
int main() {
	ucin();
	int n, m;
	cin >> n >> m;
	if(n > m) swap(n, m);
	static ll ff[N];
	ff[0] = 1;
	for(int i = 1; i <= m; i ++) {
		ff[i] = (ff[i - 1] + (i == 1 ? 0 : ff[i - 2])) % mo;
	}
	cout << 2ll * (ff[n] + ff[m] - 1) % mo;
	return 0;
}