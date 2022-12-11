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

const int N = 4e5 + 10;

int q, n, p[N], bel[N], sz[N];
bool vis[N];

int main() {
	ucin();
	cin >> q;
	while(q --) {
		cin >> n;
		for(int i = 1; i <= n; i ++) cin >> p[i], vis[i] = 0;
		int b = 0;
		for(int i = 1; i <= n; i ++) if(!vis[i]) {
			int v = i; b ++; sz[b] = 0;
			while(!vis[v]) {
				vis[v] = 1;
				bel[v] = b;
				v = p[v];
				sz[b] ++;
			}
		}
		for(int i = 1; i <= n; i ++) cout << sz[bel[i]] << ' ';
		cout << endl;
	}
	return 0;
}