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

const int N = 110;

int n, m, a[N][N], b[N][N];
vector<pii> ans;
bool tag;

int main() {
	ucin();
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			if(a[i][j]) {
				if(i == n || j == m) {
					if(!b[i][j]) {
						tag = 1;
					}
				} else {
					if(a[i][j + 1] && a[i + 1][j] && a[i + 1][j + 1]) {
						b[i][j] = b[i][j + 1] = b[i + 1][j] = b[i + 1][j + 1] = 1;
						ans.pb(mp(i, j));
					} else if(!b[i][j]) {
						tag = 1;
					}
				}
			}
		}
	}
	if(tag) cout << -1 << endl;
	else {
		cout << (int) ans.size() << endl;
		for(int i = 0; i < ans.size(); i ++) {
			cout << ans[i].fs << ' ' << ans[i].sc << endl;
		}
	}
	return 0;
}