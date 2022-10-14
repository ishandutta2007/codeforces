#include<bits/stdc++.h>
using namespace std;
#define A(x) begin(x), end(x)
#define V vector
#define L long long
#define vo void
#define ar array
#define Lb lower_bound
#define F(x, y, z, t) for(x; y; z) {t}
auto &I = cin;
auto &O = cout;
V<V<L>>f(1e6);
V<L>cnt(1e6);
L co(L l, L r, L v) {return Lb(A(f[v]),r)-Lb(A(f[v]),l);}
main() {
	cin.tie(0)->sync_with_stdio(0);
	L n,q,id=0;
	I>>n>>q;
	V<ar<L,3>>Q(q);
	V<L>a(n),b(q);
	for(L &i:a){I>>i;f[i].push_back(id++);}id=0;
	mt19937 R(chrono::steady_clock::now().time_since_epoch().count());
	L i,t,l,r,z;
	F(i=q,i--,0,I>>l>>r;--l;t=0;
	F(z=44,z--,0,t=max(t, co(l,r,a[l+(R()%(r-l))]));)
	O<<max<L>(1,2*t-r+l)<<'\n';)
}