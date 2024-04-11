#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
const ll mod = 696969569;
using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int C = 450, N = 1e5;
ll n, q, col[N], val[N], add[N/C], sum[N/C], dv[N], md[N];
int fcol[C];
void upd(int bl) {
	if(fcol[bl]==-1) return;
	for(int i = bl*C; i < (bl+1)*C; i++) {
		col[i] = fcol[bl];
		val[i] += add[bl];
	}
	fcol[bl]=-1;
	add[bl]=0;
}
void print() {
	for(int i = 0; i < n; i++) {
		upd(dv[i]);
		cout << col[i] << " ";
	}
	cout << "\n";
	for(int i = 0; i < n; i++) {
		cout << val[i] << " ";
	}
	cout << "\n";
	cout << "=======\n";
}
void setv(int bl, ll x) {
//	cout << "setv\n";
	upd(bl);
	for(int i = bl*C; i < (bl+1)*C; i++) {
		val[i] += abs(col[i]-x);
		sum[bl] += abs(col[i]-x);
		col[i] = x;
//		cout << i << " ";
	}
//	cout << "\n";
	fcol[bl]=x;
	add[bl]=0;
//	print();
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	memset(fcol, -1, sizeof fcol);
	for (int i = 0; i < n; i++)
		col[i]=i+1, dv[i] = i / C, md[i] = i % C, val[i]=0, fcol[dv[i]]=-1;
//	return 0;
//	print();
	for (ll t, l, r, x, i = 0; i < q; i++) {
		cin >> t >> l >> r, l--, r--;
		if (t == 1) {
			cin >> x;
			while (l <= r) {
				if (md[l] == 0&&l+C-1<=r) {
					if(fcol[dv[l]]==-1) {
						setv(dv[l], x);
					} else {
						add[dv[l]]+=abs(fcol[dv[l]]-x);
						sum[dv[l]]+=C*abs(fcol[dv[l]]-x);
					}
					fcol[dv[l]]=x;
					l+=C;
				} else {
					upd(dv[l]);
					val[l] += abs(x-col[l]);
					sum[dv[l]] += abs(x-col[l]);
					col[l]=x;
					l++;
				}
			}
		} else {
			ll ans = 0;
			while (l <= r) {
				if (md[l] == 0&&l+C-1<=r) {
					ans += sum[dv[l]];
					l+=C;
				} else {
					upd(dv[l]);
					ans += val[l];
					l++;
				}
			}
			cout << ans << "\n";
		}
//		cout << "done\n";
	}
//	print();
}