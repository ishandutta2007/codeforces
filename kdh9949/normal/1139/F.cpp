#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 300005;

struct BIT2{
	struct BIT{
		vector<int> v, d;
		int s;
		void b(int y){ v.push_back(y); }
		void a(){
			sort(v.begin(), v.end());
			s = v.size();
			d = vector<int>(s + 1, 0);
		}
		int i(int y){ return int(upper_bound(v.begin(), v.end(), y) - v.begin()); }
		void u(int y, int v){ for(y = i(y); y <= s; y += y & -y) d[y] += v; }
		int g(int y){ int r = 0; for(y = i(y); y; y -= y & -y) r += d[y]; return r; }
	} d[N];
	void b(int x, int y){ for(; x < N; x += x & -x) d[x].b(y); }
	void a(){ for(int i = 1; i < N; i++) d[i].a(); }
	void u(int x, int y, int v){ for(; x < N; x += x & -x) d[x].u(y, v); }
	int g(int x, int y){ int r = 0; for(; x; x -= x & -x) r += d[x].g(y); return r; }
} A, B;

int n, m;
ll b[N], p[N], s[N], x[N], y[N], z[N], inc[N], pre[N];
ll qx[N], qy[N], qz[N], qw[N];
ll wx[N], wy[N], wz[N];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", p + i);
	for(int i = 1; i <= n; i++) scanf("%lld", s + i);
	for(int i = 1; i <= n; i++) scanf("%lld", b + i);
	for(int i = 1; i <= m; i++) scanf("%lld", inc + i);
	for(int i = 1; i <= m; i++) scanf("%lld", pre + i);
	int c = 0, d = 0;
	for(int i = 1; i <= n; i++, c++, d += 2){
		x[c] = qx[i] = p[i] + b[i];
		y[c] = qy[i] = s[i] + 1;
		z[d] = qz[i] = p[i] - b[i];
		z[d + 1] = qw[i] = 2 * s[i] - b[i] - p[i];
	}
	for(int i = 1; i <= m; i++, c++, d++){
		x[c] = wx[i] = pre[i] + inc[i];
		y[c] = wy[i] = inc[i];
		z[d] = wz[i] = inc[i] - pre[i];
	}
	sort(x, x + c);
	sort(y, y + c);
	sort(z, z + d);
	auto cpr = [](ll &x, ll a[], int c){ x = int(lower_bound(a, a + c, x) - a + 1); };
	for(int i = 1; i <= n; i++){
		cpr(qx[i], x, c);
		cpr(qy[i], y, c);
		cpr(qz[i], z, d);
		cpr(qw[i], z, d);
		A.b(qx[i], qz[i]); A.b(qx[i], qw[i] + 1);
		B.b(qy[i], qz[i]); B.b(qy[i], qw[i] + 1);
	}
	A.a(); B.a();
	for(int i = 1; i <= n; i++){
		A.u(qx[i], qz[i], 1); A.u(qx[i], qw[i] + 1, -1);
		B.u(qy[i], qz[i], 1); B.u(qy[i], qw[i] + 1, -1);
	}
	for(int i = 1; i <= m; i++){
		cpr(wx[i], x, c);
		cpr(wy[i], y, c);
		cpr(wz[i], z, d);
		printf("%d ", A.g(wx[i], wz[i]) - B.g(wy[i], wz[i]));
	}
	puts("");
	return 0;
}