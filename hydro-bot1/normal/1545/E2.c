// Hydro submission #61b558b4e2b0fa8e2f76adcf@1639274677570
#include <stdio.h>
#include <sys/time.h>
 
#define N	200610
#define N_	(1 << 19)	/* N_ = pow2(ceil(log2(N * 2))) */
#define INF	0x3f3f3f3f3f3f3f3fLL
#define X	10000000
 
long long min(long long a, long long b) { return a < b ? a : b; }
 
unsigned int Z;
 
void srand_() {
	struct timeval tv;
 
	gettimeofday(&tv, NULL);
	Z = tv.tv_sec ^ tv.tv_usec | 1;
}
 
int rand_() {
	return (Z *= 3) >> 1;
}
 
int xx[N * 2], xx_[N * 2], yy[N * 2], inv[N * 2];
 
int *aa;
 
void sort(int *ii, int l, int r) {
	while (l < r) {
		int i = l, j = l, k = r, i_ = ii[l + rand_() % (r - l)], tmp;
 
		while (j < k) {
			int c = aa[ii[j]] != aa[i_] ? aa[ii[j]] - aa[i_] : (i_ & 1) - (ii[j] & 1);
 
			if (c == 0)
				j++;
			else if (c < 0) {
				tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
				i++, j++;
			} else {
				k--;
				tmp = ii[j], ii[j] = ii[k], ii[k] = tmp;
			}
		}
		sort(ii, l, i);
		l = k;
	}
}
 
int zz[1 + N * 2], ll[1 + N * 2], rr[1 + N * 2], xy[1 + N * 2]; long long dd[1 + N * 2]; int u_, l_, r_;
 
int node(int k, long long v) {
	static int _ = 1;
 
	zz[_] = rand_();
	xy[_] = k, dd[_] = v;
	return _++;
}
 
void split(int u, int k) {
	if (u == 0) {
		u_ = l_ = r_ = 0;
		return;
	}
	if (xy[u] <= k) {
		split(rr[u], k);
		rr[u] = l_, l_ = u;
	} else {
		split(ll[u], k);
		ll[u] = r_, r_ = u;
	}
}
 
int merge(int u, int v) {
	if (u == 0)
		return v;
	if (v == 0)
		return u;
	if (zz[u] < zz[v]) {
		rr[u] = merge(rr[u], v);
		return u;
	} else {
		ll[v] = merge(u, ll[v]);
		return v;
	}
}
 
int first(int u) { return ll[u] == 0 ? u : first(ll[u]); }
int last(int u) { return rr[u] == 0 ? u : last(rr[u]); }
 
int remove_first(int u) {
	int p, v;
 
	if (ll[u] == 0)
		return rr[u];
	p = u, v = ll[u];
	while (ll[v])
		p = v, v = ll[v];
	ll[p] = rr[v];
	return u;
}
 
int remove_last(int u) {
	int p, v;
 
	if (rr[u] == 0)
		return ll[u];
	p = u, v = rr[u];
	while (rr[v])
		p = v, v = rr[v];
	rr[p] = ll[v];
	return u;
}
 
int y_, head, tail, next[N * 2], prev[N * 2], tt[N * 2];
 
char st1[N_ * 2], st2[N_ * 2]; int n_;
 
void pul(int i) {
	int l = i << 1, r = l | 1;
	st1[i] = st1[l] || st1[r], st2[i] = st2[l] || st2[r];
}
void pull(int i) {
	while (i > 1)
		pul(i >>= 1);
}
void update(int i, int x) {
	i = xx_[i];
	st1[n_ + i] = x, st2[n_ + i] = st1[n_ + i] && tt[inv[i]];
	pull(i + n_);
}
int floor_(int i) {
	int r = xx_[i] + n_;
 
	while (1) {
		if ((r & 1) == 0) {
			if (st1[r]) {
				i = r;
				while (i < n_)
					i = st1[i << 1 | 1] ? i << 1 | 1 : i << 1 | 0;
				return inv[i - n_];
			}
			r--;
		}
		r >>= 1;
	}
}
void clear_(int i) {
	if (st2[i]) {
		st2[i] = 0;
		if (i >= n_)
			tt[inv[i - n_]] = 0;
		else
			clear_(i << 1 | 0), clear_(i << 1 | 1);
	}
}
void clear(int l, int r) {
	int l_ = l += n_, r_ = r += n_;
 
	for ( ; l <= r; l >>= 1, r >>= 1) {
		if ((l & 1) == 1)
			clear_(l++);
		if ((r & 1) == 0)
			clear_(r--);
	}
	pull(l_), pull(r_);
}
void refresh(int i) {
	int z = xx[next[i]] - y_;
	split(tt[i], z);
	if (r_) {
		int u = last(l_), v = first(r_);
 
		if (u == 0 || dd[v] + xy[v] - z < dd[u] + z - xy[u])
			dd[v] += xy[v] - z, xy[v] = z, ll[v] = rr[v] = 0, l_ = merge(l_, v);
	}
	tt[i] = l_;
}
void insert(int i) {
	int p = floor_(i);
	if (tt[p]) {
		int z, u, v;
		long long d1, d2;
		refresh(p);
		split(tt[p], z = xx[i] - y_);
		u = last(l_), v = first(r_);
		d1 = u == 0 ? INF : dd[u] + z - xy[u], d2 = v == 0 ? INF : dd[v] + xy[v] - z;
		tt[p] = l_, tt[i] = r_;
		if (d1 < d2) tt[i] = merge(node(z, d1), tt[i]);
		else if (d1 > d2) tt[p] = merge(tt[p], node(z, d2));
	}
	update(p, 1), update(i, 1), next[i] = next[p], prev[next[p]] = i, next[p] = i, prev[i] = p;
}
void extract(int i) {
	int p = prev[i], u, v;
	refresh(p), refresh(i);
	u = last(tt[p]), v = first(tt[i]);
	while (u && v)
		if (dd[u] >= dd[v] + xy[v] - xy[u]) u = last(tt[p] = remove_last(tt[p]));
		else if (dd[u] + xy[v] - xy[u] <= dd[v]) v = first(tt[i] = remove_first(tt[i]));
		else break;
	tt[p] = merge(tt[p], tt[i]);
	update(p, 1), update(i, 0), next[p] = next[i], prev[next[i]] = p;
}
long long getans(int u) {
	return u == 0 ? INF : min(dd[u], min(getans(ll[u]), getans(rr[u])));
}
int main() {
	static int ii[N * 2];
	int n, x, h, i;
	srand_();
	scanf("%d%d", &n, &x);
	for (i = 0; i < n; i++) scanf("%d%d%d%d", &yy[i << 1 | 0], &yy[i << 1 | 1], &xx[i << 1 | 0], &xx[i << 1 | 1]), xx[i << 1 | 0]--, xx[i << 1 | 1]++, yy[i << 1 | 0]--, yy[i << 1 | 1]++;
	xx[n << 1 | 0] = -X, xx[n << 1 | 1] = X;
	for (i = 0; i < n * 2 + 2; i++) inv[i] = i;
	aa = xx, sort(inv, 0, n * 2 + 2);
	for (i = 0; i < n * 2 + 2; i++) xx_[inv[i]] = i;
	n_ = 1;
	while (n_ < n * 2 + 2) n_ <<= 1;
	for (i = 0; i < n * 2; i++) ii[i] = i;
	aa = yy, sort(ii, 0, n * 2);
	head = n << 1 | 0, tail = n << 1 | 1;
	next[head] = tail, prev[tail] = head, tt[head] = node(x, 0);
	update(head, 1), update(tail, 1);
	for (h = 0; h < n * 2; h++) {
		i = ii[h] >> 1, y_ = yy[ii[h]];
		if ((ii[h] & 1) == 0)
			insert(i << 1 | 0), insert(i << 1 | 1), clear(xx_[i << 1 | 0], xx_[i << 1 | 1] - 1);
		else
            extract(i << 1 | 0), extract(i << 1 | 1);
	}
	printf("%lld\n", getans(tt[head]));
	return 0;
}