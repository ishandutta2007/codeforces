#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int mod = 1000000007ll;
const int maxn = 1e6 + 33;
int n, sz, f[2][maxn], a[maxn], val[maxn];
void add(int i, int x, int v) {
	while(x <= n) {
		f[i][x]+=v;
//		cout << x << " "<< f[i][x] << "\n";
		x+=x&-x;
	}
}
int get(int i, int x) {
	int res = 0;
//	cout << "___\n";
	while(x) {
		res += f[i][x];
//		cout << f[i][x] << "\n";
		x-=x&-x;
	}
//	cout << "__"<<res<<"__\n";
	return res;
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	memset(f[0], 0, sizeof f[0]);
	memset(f[1], 0, sizeof f[1]);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		val[i]=a[i];
	}
	sort(val, val+n);
	for(int i = 0; i < n; i++){
		int c = 0;
		for(int j = 1<<20; j; j>>=1)
			if(c+j < n && val[c+j]<=a[i])
				c+=j;
		add(1, a[i] = c+1, 1);
	}
	ll ans = 0;
	for(int i = 0; i < n; i++){
		add(1, a[i], -1);
//		cout << a[i] << " ";// << get(0, n) << " " << get(1, n) << "\n";
		ans += (get(0, n)-get(0, a[i]))*1ll*get(1, a[i]-1);
		add(0, a[i], 1);
	}
	cout << ans;
}