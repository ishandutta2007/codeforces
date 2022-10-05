#include <bits/stdc++.h>
using namespace std;

const int N = 100005, sz = 131072;

struct Seg{
	int d[2 * sz];
	void ini(){ fill(d + 1, d + 2 * sz, 0); }
	void upd(int x, int v){
		x += sz;
		d[x] = max(d[x], v);
		for(x /= 2; x; x /= 2) d[x] = max(d[2 * x], d[2 * x + 1]);
	}
	int get(int s, int e){
		int r = 0;
		for(s += sz, e += sz; s <= e; s /= 2, e /= 2){
			if( s & 1) r = max(r, d[s++]);
			if(~e & 1) r = max(r, d[e--]);
		}
		return r;
	}
} S;

int m, n, a[N], l[N], r[N], ans;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> m >> n;
	for(int x, y; m--; ){
		cin >> x >> y;
		a[x]++;
		a[y + 1]--;
	}
	for(int i = 1; i <= n; i++) a[i] += a[i - 1];
	for(int i = 1; i <= n; i++){
		l[i] = S.get(0, a[i]) + 1;
		S.upd(a[i], l[i]);
	}
	S.ini();
	for(int i = n; i >= 1; i--){
		r[i] = S.get(0, a[i]) + 1;
		S.upd(a[i], r[i]);
		ans = max(ans, l[i] + r[i] - 1);
	}
	cout << ans << endl;
}