#include<bits/stdc++.h>
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mn = 1e5+10;
int aa[mn], bb[mn], cc[mn], dd[mn];
vector<int>use;
map<int, int> m;
int siz(int x) {
	return use[x + 1] - use[x];
}
ll seg[1<<20], laz[1<<20],lo[1<<20];
void prop(int x, int l, int r) {
	if (laz[x] == 0x3f3f3f3f3f3f3f3f)return;
	seg[x] = laz[x] * (use[r + 1] - use[l]);
	lo[x] = min(0LL, seg[x]);
	if (x < 1 << 19) {
		laz[x * 2] = laz[x];
		laz[x * 2 + 1] = laz[x];
	}
	laz[x] = 0x3f3f3f3f3f3f3f3f;
}
void calc(int x, int l, int r) {
	prop(x * 2, l, mid);
	prop(x * 2 + 1, mid + 1, r);
	seg[x] = seg[x * 2] + seg[x * 2 + 1];
	lo[x] = min(lo[x * 2], lo[x * 2 + 1] + seg[x * 2]);
}
void update(int x, int l, int r, int a, int b, ll c) {
	if (a == l && b == r) {
		laz[x] = c;
	}
	else {
		prop(x, l, r);
		if (b <= mid)update(x * 2, l, mid, a, b, c);
		else if (a > mid)update(x * 2 + 1, mid + 1, r, a, b, c);
		else update(x * 2, l, mid, a, mid, c), update(x * 2 + 1, mid + 1, r, mid + 1, b, c);
		calc(x, l, r);
	}
}
ll val(int x, int l, int r, int a, int b) {
	if (b < a)return 0;
	prop(x, l, r);
	if (a == l && b == r)return seg[x];
	else {
		if (b <= mid)return val(x * 2, l, mid, a, b);
		else if (a > mid)return val(x * 2 + 1, mid + 1, r, a, b);
		else return val(x * 2, l, mid, a, mid) + val(x * 2 + 1, mid + 1, r, mid + 1, b);
	}
}
long double query(int x, int l, int r,int a,ll c) {
	prop(x, l, r);
	prop(x * 2, l, mid);
	if (l == r) {
		if (c >= 0)return 0;
		ll rate = (seg[x] / siz(l));
		long double ans = 1.0L*c /rate ;
		if (rate>=0)return siz(l);
		return min(0.0L + siz(l),ans );
	}
	
	if (lo[x*2]>c||a>mid)return 0.0L+use[mid + 1] - use[l] + query(x * 2 + 1, mid + 1, r,a, c - seg[x * 2]);
	else {
		long double th;
		th = query(x * 2, l, mid, a, c);
		if(th+use[l]==use[mid+1])return th+ query(x * 2 + 1, mid + 1, r, mid+1, c - seg[x * 2]);
		else return th;
	}
}
ll s[3 * mn];
int main() {
	int n,i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d", aa + i, bb + i);
		if (aa[i] == 1)scanf("%d", cc + i);
		if (aa[i] == 3)scanf("%d%d",cc+i, dd + i);
		use.push_back(bb[i]);
		if(aa[i]==3)use.push_back(cc[i]);
	}
	use.push_back(0x7fffffff);
	use.push_back(0);
	sort(use.begin(), use.end());
	use.resize(distance(use.begin(), unique(use.begin(), use.end())));
	for (i = 1; i < use.size(); i++)m[use[i]] = i;
	set<int> tms;
	tms.insert(0);
	int tot = use.size()-2;
	tms.insert(tot+1);
	memset(laz, 0x3f, sizeof(laz));
	for (i = 0; i < n; i++) {
		if (aa[i] == 1) {
			ll t = m[bb[i]];
			set<int>::iterator it = tms.upper_bound(t);
			update(1, 1, tot, t, (*it) - 1, cc[i]);
			tms.insert(t);
			s[t] = cc[i];
		}
		else if (aa[i] == 2) {
			ll t = m[bb[i]];
			set<int>::iterator it = --tms.find(t),it2=tms.upper_bound(t);
			update(1, 1, tot, t, (*it2) - 1, s[*it]);
			tms.erase(t);
			s[t] = 0;
		}
		else {
			set<int>::iterator it = tms.lower_bound(m[bb[i]]);
			ll add = val(1, 1, tot, 1,(*it) - 1);
			long double ans = query(1, 1, tot,*it,add-dd[i])+use[1];
			if (dd[i] == 0)ans = bb[i];
			if (ans>cc[i]+1e-15)printf("-1\n");
			else printf("%.10Lf\n", ans);
		}
	}
}