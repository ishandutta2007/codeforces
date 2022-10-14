//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 7 * 17 * (1 << 23) + 1;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, mat[1010][1010], eq[1010][1010];
vector<pair<int, int>> a;
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	a.resize(n);
	int __t = 0;
	for(auto &i : a) cin >> i.first, i.second = __t++;
	sort(rall(a));
	int op = a[0].first+(n>1&&a[1].first==a[0].first);
	cout << op;
	for(int i = 0; i < a[0].first; i++)
		mat[a[0].second][i] = 1;
	if(n>1&&a[1].first==a[0].first) {
		for(int i = 1; i <= a[0].first; i++)
			mat[a[1].second][i] = 1, eq[a[1].second][i] = i>1&&i<a[0].first;
	}
	for(int i = 1; i < op; i++)
		eq[a[0].second][i] = mat[a[0].second][i]==mat[a[0].second][i-1];
	for(int i = 1+(n>1&&a[1].first==a[0].first); i < n; i++) {
		int l = 0,ll=0, j=0;
		for(int k = 0; k < op; k++) {
			if(!eq[a[i-1].second][k]) {
				ll = 0;
			}
			ll++;
//			cout << eq[a[i-1].second][k] << ", " << ll << " " << l << " __\n";
			if(l<ll)l=ll, j = k;
		};
//		cout << a[i].second << " " << l << "\n";
		if(a[i].first<l) {
//			cout << "case1)\n";
			while(a[i].first--) mat[a[i].second][j--]=1;
		} else {
			int q = l-1;
			a[i].first-=l-1;
			while(q--) mat[a[i].second][j--]=1;
			for(int j = 0, c = 0; c < a[i].first; j++)
				if(mat[a[i].second][j]==0&&(j==op-1||mat[a[i].second][j+1]==0))
				mat[a[i].second][j]=1, c++;
		}
		for(int j = 1; j < op; j++)
			eq[a[i].second][j] = mat[a[i].second][j] == mat[a[i].second][j-1] && eq[a[i-1].second][j];
	}
	cout << "\n";
	for(int i = 0; i < op; i++, cout << "\n")
		for(int j = 0; j < n; j++)
			cout << mat[j][i];
}