#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 3e5 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool can(int hy, int dy, int ay, int hm, int dm, int am) {
	if(ay <= dm) return 0;
	if(am <= dy) return 1;
	int X = (hm+ay-dm-1)/(ay-dm);
	int Y = (hy+am-dy-1)/(am-dy);
	//cout << X << " " << Y << endl;
	if(Y > X) {
		//cout << hy << " " << dy << " " << ay << " " << hm << " " << dm << " " << am << endl;
	}
	return Y > X;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int hm, dm, am, hy, dy, ay, h, a, d;
    cin >> hy >> ay >> dy >> hm >> am >> dm >> h >> a >> d;
    int ans = 1<<30;
	for(int u = 0; u <= 10000; u++) {
		int w = 10003;
		for(int v = 0; v <= 10000; v++) {
				while(w > 0 && can(hy+u, dy+v, ay+w-1, hm, dm, am)) w--;
				if(can(hy+u, dy+v, ay+w, hm, dm, am)) ans = min(ans, u*h + v*d + w*a);
		}
	}
	cout << ans << endl;
}