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

const int N = 1e5 + 10;

int q, n, a[N];

int main() {
	ucin();
	cin >> q;
	while(q --) {
		cin >> n; bool t = 0;
		for(int i = 1; i <= n; i ++) {
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; i ++)
			if(i > 1 && a[i - 1] + 1 == a[i]) t = 1;
		cout << (t ? 2 : 1) << endl;
	}
	return 0;
}