#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
//using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
const ll mod = 1e9 + 7;
//using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ld = double;
ld x[111], ttx[111];
int ord[11][11], f[111], m[11][11];
void kostil() {
	for(int i = 100; i--;) {
		ttx[i]=0.;
		for(int j = 1; j<7; j++)
				ttx[i]+=min(x[i+j<=100?i+j:i], x[f[i+j<=100?i+j:i]]);
		ttx[i]/=6.;
		ttx[i]+=1;
	}
	for(int i = 1; i <= 100;i++)x[i]=ttx[i];//, cout << x[i] << " ";cout << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 11; i-- > 1;)
		for (int j = 1; j <= 10; j++)
			cin >> m[i][j];
	int X = 1, Y = 1;
	for (int i = 1; i <= 100; i++) {
		ord[X][Y] = i;
		if (X & 1) {
			if (Y == 10)
				X++;
			else
				Y++;
		} else {
			if (Y == 1)
				X++;
			else
				Y--;
		}
	}
	x[100] = 0;
	for(int i = 99; i--;)
		x[i]=1;
	for (int i = 11; i-- > 1;)
		for (int j = 1; j <= 10; j++)
			f[ord[i][j]] = ord[i + m[i][j]][j];
	for (int i = 1000; i--;)
		kostil();
	cout << fixed << setprecision(15) << x[1];
}