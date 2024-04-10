#include<iostream>
#include<cstdio>

using namespace std;

typedef long long llint;

const int MAXN = 100005;
const llint SIZ = 2000000005;

llint n, g, r, pot = (1LL<<31)-1, cnt=1, ofs, q;
llint t[30*MAXN], lef[30*MAXN], rig[30*MAXN], par[30*MAXN];
llint l[MAXN], dp[MAXN], p[MAXN];

void ubaci (llint pos, llint val) {
	llint cvor = 1, low = 0, high = pot-1, mid;
	while (low<high) {
		mid = (low + high)/2;
		if (pos <= mid) {
			lef[cvor] = lef[cvor]?lef[cvor]:(++cnt);
			par[lef[cvor]] = cvor;
			cvor = lef[cvor];
			high = mid;
		} else {
			rig[cvor]=rig[cvor]?rig[cvor]:(++cnt);
			par[rig[cvor]] = cvor;
			cvor = rig[cvor];
			low = mid+1;
		}
	}
	t[cvor] = val;
	cvor = par[cvor];
	while (cvor) {
		t[cvor] = min(t[lef[cvor]], t[rig[cvor]]);
		cvor = par[cvor];
	}
}

llint upit (int cvor, int from, int to, llint low, llint high) {
	if (cvor == 0 || to<low || high<from) return SIZ;
	if (from<=low && high<=to) return t[cvor];
	return min(upit(lef[cvor], from, to, low, (low+high)/2), upit(rig[cvor], from, to, (low+high)/2+1, high));
}

void calc_dp () {
	for (int i=n; i>=1; i--) {
		ofs = (ofs + l[i]) % (g+r);
		if (ofs == 0) ofs = g+r;
		ubaci(g+r - ofs, i);
		ubaci(g+r + g+r - ofs, i);
		llint ind = upit(1, g+r - ofs + g, g+r - ofs + g+r -1, 0, pot-1);
		if (ind==SIZ) dp[i] = p[n] - p[i-1]; else dp[i] = dp[ind] + ((p[ind-1] - p[i-1]) / (g+r) +1) * (g+r);
	}
	ofs = (ofs + l[0]) % (g+r);
}

int main () {
	t[0] = SIZ;
	cin >> n >> g >> r;
	for (int i=0; i<n+1; i++) {
		scanf("%I64d", &l[i]);
		if (i==0) p[i] = l[i]; else p[i] = p[i-1] + l[i];
	}
	calc_dp();
	cin >> q;
	for (int i=0; i<q; i++) {
		llint x, res;
		scanf("%I64d", &x);
		ofs = (ofs + x) % (g+r);
		if (ofs == 0) ofs = g+r;
		llint ind = upit(1, g+r - ofs + g, g+r - ofs + g+r -1, 0, pot-1);
		if (ind==SIZ) res = p[n] + x; else res = dp[ind] + ((p[ind-1] + x) / (g+r) +1) * (g+r);
		ofs = ((ofs - x) % (g+r) + g+r) % (g+r);
		printf("%I64d\n", res);
	}
	return 0;
}