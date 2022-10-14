#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long llint;

const int MAXN = 200005;
const int B = 31337;
const int M = 1000000007;

int n, q, siz, ofs = 1, cnt = 1;
string s[MAXN], t;
int len[MAXN], lim[MAXN], sf[MAXN], val[MAXN], r[MAXN], rev[MAXN], br[MAXN];
int root[25*MAXN], lef[25*MAXN], rig[25*MAXN];
llint h1[MAXN], pot1[MAXN], h2[MAXN], pot2[MAXN], sum[25*MAXN], ost[421*421 + 5];

void precompute () {
	for (int i=0; i<siz; i++) {
		pot1[i] = i==0 ? 1 : pot1[i-1] * B;
		pot2[i] = i==0 ? 1 : pot2[i-1] * 7 % 421;
		h1[i] = i==0 ? t[i] : h1[i-1] * B + t[i];
		h2[i] = i==0 ? t[i] % 421 : (h2[i-1] * 7 + t[i])%421;
	}
}

inline llint add (llint a, llint b) {
	return ost[a+b];
}

inline llint sub (llint a, llint b) {
	a -= b;
	if (a < 0) return a+421; return a;
}

inline llint mul (llint a, llint b) {
	return ost[a*b];
}

llint geth1 (int a, int b) {
	if (a == 0) return h1[b]; else return h1[b] - h1[a-1] * pot1[b-a+1];
}

llint geth2 (int a, int b) {
	if (a == 0) return h2[b]; else return sub(h2[b], mul(h2[a-1], pot2[b-a+1]));
}

bool isti (int a1, int b1, int a2, int b2) {
	if (t[a1] != t[a2] || t[b1] != t[b2] || b1 - a1 != b2 - a2) return 0;
	return geth1(a1, b1) == geth1(a2, b2) && geth2(a1, b1) == geth2(a2, b2);
}

bool cmp (int x, int y) {
	if (t[x] != t[y]) return t[x] < t[y];
	int low = 0, high = min(lim[x] - x + 1, lim[y] - y + 1), mid;
	while (low < high) {
		mid = (low + high + 1) / 2;
		if (isti(x, x + mid - 1, y, y + mid - 1)) {
			low = mid;
		} else {
			high = mid - 1;
		}
	}
	if (lim[x] - x + 1 == low || lim[y] - y + 1 == low) return lim[x] - x + 1 < lim[y] - y + 1;
	return t[x + low] < t[y + low];
}

void suf () {
	for (int i=0; i<siz; i++) {
		sf[i] = i;
	}
	sort(sf, sf+siz, cmp);
	for (int i=0; i<siz; i++) {
		rev[sf[i]] = i;
	}
}

int build (int num) {
	if (num == 1) return cnt;
	int curr = cnt;
	cnt++; lef[curr] = build(num/2);
	cnt++; rig[curr] = build(num/2);
	return curr;
}

int update (int cvor, int pos, int low, int high) {
	if (low == high) {
		cnt++;
		sum[cnt] = br[pos];
		return cnt;
	}
	int mid = (low + high) / 2, curr;
	cnt++; curr = cnt;
	if (pos <= mid) {
		lef[curr] = update(lef[cvor], pos, low, mid);
		rig[curr] = rig[cvor];
	} else {
		rig[curr] = update(rig[cvor], pos, mid+1, high);
		lef[curr] = lef[cvor];
	}
	sum[curr] = sum[lef[curr]] + sum[rig[curr]];
	return curr;
}

void build_all () {
	root[0] = 1;
	build(ofs);
	for (int i=0; i<siz; i++) {
		br[val[sf[i]]]++;
		root[i+1] = update(root[i], val[sf[i]], 0, ofs-1);
	}
}

llint upit (int a, int b, int from, int to, int low, int high) {
	if (to<low || high<from) return 0;
	if (from<=low && high<=to) return sum[b] - sum[a];
	return upit(lef[a], lef[b], from, to, low, (low+high)/2) + upit(rig[a], rig[b], from, to, (low+high)/2+1, high);
}

int lb (int ind) {
	int low = 0, high = rev[ind], mid;
	while (low < high) {
		mid = (low + high) / 2;
		if (lim[ind] - ind + 1 == lim[sf[mid]] - sf[mid] + 1 && isti(ind, lim[ind], sf[mid], lim[sf[mid]])) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	return low;
}

int ub (int ind) {
	int low = rev[ind], high = siz - 1, mid;
	while (low < high) {
		mid = (low + high + 1) / 2;
		if (lim[ind] - ind + 1 <= lim[sf[mid]] - sf[mid] + 1 && isti(ind, lim[ind], sf[mid], sf[mid] + lim[ind] - ind)) {
			low = mid;
		} else {
			high = mid - 1;
		}
	}
	return low;
}

int main () {
	for (int i=0; i<421 * 421; i++) {
		ost[i] = i%421;
	}
	cin >> n >> q;
	for (int i=0; i<n; i++) {
		cin >> s[i];
		len[i] = s[i].size();
		for (int j=0; j<len[i]; j++) {
			lim[siz + j] = siz + len[i] - 1;
			val[siz + j] = i;
		}
		r[i] = siz;
		t += s[i];
		siz += len[i];
	}
	precompute();
	suf();
	while (ofs < n) ofs *= 2;
	build_all();
	for (int i=0; i<q; i++) {
		int ll, rr, k;
		scanf("%d%d%d", &ll, &rr, &k);
		k--;
		printf("%I64d\n", upit(root[lb(r[k])], root[ub(r[k]) + 1], ll-1, rr-1, 0, ofs-1));
	}
	return 0;
}