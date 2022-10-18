#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <math.h>
#include <set>
#include <random>
 
using namespace std;
 
/*const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
char *res = mem + mpos;
mpos += n;
assert(mpos <= MAX_MEM);
return (void *)res;
}
inline void operator delete ( void * ) { }*/
 
int n, k;
vector <int> g[200500];

long long koli[200500][6], r[200500][6]; 
long long ans = 0;

void dfs(int nom, int pr) {
	koli[nom][0] = 0;
	r[nom][0] = 1;
	for (int i = 0; i < g[nom].size(); i++) {
		if (g[nom][i] == pr) {
			continue;
		}
		int a = g[nom][i];
		dfs(g[nom][i], nom);
		for (int h = 0; h < k; h++) {
			for (int j = 0; j < k; j++) {
				if (h == 0 || j == 0) { 
					ans = ans + r[a][j] * koli[nom][h] + r[nom][h] * koli[a][j]; 
					continue;
				}
				if (h + j <= k) {
					ans = ans + r[a][j] * koli[nom][h] + r[nom][h] * koli[a][j] - r[nom][h] * r[a][j]; 
					continue;
				}
				ans = ans + r[a][j] * koli[nom][h] + r[nom][h] * koli[a][j];
			}
		}
		for (int h = 0; h < k; h++) {
			koli[nom][h] += koli[a][h];
			r[nom][h] += r[a][h];
		}
	}
	for (int i = k; i > 0; i--) {
		koli[nom][i] = koli[nom][i - 1];
		r[nom][i] = r[nom][i - 1];
	}
	koli[nom][1] += r[nom][1];
	koli[nom][0] = koli[nom][k];
	r[nom][0] = r[nom][k];

}

int main() {
    //srand(228);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    ///freopen("haircut.in", "r", stdin);
    //freopen("haircut.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 0);
	cout << ans;
}