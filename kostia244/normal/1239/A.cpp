#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
const ll mod = (1e9+7);
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
ll f[100100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	f[0]=1;
	f[1]=1;
	for(int i = 2; i < 100100; i++) {
		f[i]=(f[i-1]+f[i-2])%mod;
	}
	cout << (2*(f[n]+f[m]-1))%mod;
}