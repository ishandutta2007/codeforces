#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define ucin() ios :: sync_with_stdio(0)

typedef map<int, int> mii;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int N = 1e5 + 10;

long long n, l, r, a, b;

int main() {
	ucin(); cin >> n >> l >> r;
	for(int i = 0; i < l; i ++) {
		a += 1ll << i;
	}
	a += n - l;
	for(int i = 0; i < r; i ++) {
		b += 1ll << i;
	}
	b += (n - r) * 1ll << (r - 1);
	cout << a << " " << b << endl;
	return 0;
}