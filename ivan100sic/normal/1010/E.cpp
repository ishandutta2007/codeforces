#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct triple {
	int x, y, z;
};

triple mn(triple a, triple b) {
	return {min(a.x, b.x), min(a.y, b.y), min(a.z, b.z)};
}

triple mx(triple a, triple b) {
	return {max(a.x, b.x), max(a.y, b.y), max(a.z, b.z)};
}

int xh, yh, zh, n, m, k;
triple op[100005], cl[100005], qr[100005];
int ans[100005];

const int OPEN = 1;
const int CLOSED = 2;
const int UNKNOWN = 3;

template<int MAXN>
struct segtree {

	multiset<int> a[2*MAXN];

	bool get(int lx, int rx, int ly, int ry, int node=1, int nl=1, int nr=MAXN) {
		if (ly > ry)
			return false;
		if (rx < nl || nr < lx) {
			return false;
		}

		if (lx <= nl && nr <= rx) {
			return a[node].lower_bound(ly) != a[node].lower_bound(ry+1);
		}

		if (a[node].lower_bound(ly) == a[node].lower_bound(ry+1))
			return false;

		int nm = (nl + nr) >> 1;

		return get(lx, rx, ly, ry, 2*node, nl, nm) ||
			get(lx, rx, ly, ry, 2*node+1, nm+1, nr);
	}

	void add(int pos, int val) {
		pos += MAXN-1;
		a[pos].insert(val);
		while (pos > 1) {
			pos >>= 1;
			a[pos].insert(val);
		}
	}

	void rem(int pos, int val) {
		pos += MAXN-1;
		a[pos].erase(a[pos].find(val));
		while (pos > 1) {
			pos >>= 1;
			a[pos].erase(a[pos].find(val));
		}
	}
};

segtree<131072> drvo, drvo2;

struct event {
	int xl, xr, yl, yr, z, id;
	bool operator< (const event& o) const {
		return z < o.z;
	}
};

vector<triple> govanca[100005];

// naravno ja sam ofc

int main() {

	scanf("%d%d%d%d%d%d", &xh, &yh, &zh, &n, &m, &k);
	for (int i=0; i<n; i++)
		scanf("%d%d%d", &op[i].x, &op[i].y, &op[i].z);
	for (int i=0; i<m; i++)
		scanf("%d%d%d", &cl[i].x, &cl[i].y, &cl[i].z);
	for (int i=0; i<k; i++)
		scanf("%d%d%d", &qr[i].x, &qr[i].y, &qr[i].z);

	triple opnal = op[0], opnah = op[0];
	for (int i=1; i<n; i++) {
		opnal = mn(opnal, op[i]);
		opnah = mx(opnah, op[i]);
	}

	for (int i=0; i<m; i++) {
		if (opnal.x <= cl[i].x && cl[i].x <= opnah.x &&
			opnal.y <= cl[i].y && cl[i].y <= opnah.y &&
			opnal.z <= cl[i].z && cl[i].z <= opnah.z)
		{
			puts("INCORRECT");
			return 0;
		}
	}

	puts("CORRECT");

	// dodaj sve cl koji su izmedju z, trebace nam
	for (int i=0; i<m; i++)
		if (opnal.z <= cl[i].z && cl[i].z <= opnah.z)
			drvo.add(cl[i].x, cl[i].y);

	// odgovori potvrdno na sve koji su unutar zone
	for (int i=0; i<k; i++) {
		if (opnal.x <= qr[i].x && qr[i].x <= opnah.x &&
			opnal.y <= qr[i].y && qr[i].y <= opnah.y &&
			opnal.z <= qr[i].z && qr[i].z <= opnah.z)
		{
			ans[i] = OPEN;
		}
	}

	// odgovori na sve kojima je z izmedju
	for (int i=0; i<k; i++) {
		if (ans[i])
			continue;

		if (opnal.z <= qr[i].z && qr[i].z <= opnah.z) {
			int xx1 = min(opnal.x, qr[i].x);
			int xx2 = max(opnah.x, qr[i].x);

			int yy1 = min(opnal.y, qr[i].y);
			int yy2 = max(opnah.y, qr[i].y);

			if (drvo.get(xx1, xx2, yy1, yy2))
				ans[i] = CLOSED;				
		}
	}

	for (int i=0; i<m; i++)
		govanca[cl[i].z].push_back(cl[i]);

	drvo2 = drvo;
	// odgovori na sve kojima je z vece
	{
		vector<event> up;
		for (int i=0; i<k; i++) {
			if (ans[i])
				continue;

			if (qr[i].z > opnah.z) {
				int xx1 = min(opnal.x, qr[i].x);
				int xx2 = max(opnah.x, qr[i].x);

				int yy1 = min(opnal.y, qr[i].y);
				int yy2 = max(opnah.y, qr[i].y);

				up.push_back({xx1, xx2, yy1, yy2, qr[i].z, i});
			}
		}

		sort(up.begin(), up.end());
		int zi = opnah.z;
		for (auto u : up) {
			while (zi < u.z) {
				zi++;
				for (auto g : govanca[zi])
					drvo.add(g.x, g.y);
			}

			if (drvo.get(u.xl, u.xr, u.yl, u.yr))
				ans[u.id] = CLOSED;
		}
	}

	// odgovori na sve kojima je z manje
	{
		vector<event> up;
		for (int i=0; i<k; i++) {
			if (ans[i])
				continue;

			if (qr[i].z < opnal.z) {
				int xx1 = min(opnal.x, qr[i].x);
				int xx2 = max(opnah.x, qr[i].x);

				int yy1 = min(opnal.y, qr[i].y);
				int yy2 = max(opnah.y, qr[i].y);

				up.push_back({xx1, xx2, yy1, yy2, qr[i].z, i});
			}
		}

		sort(up.begin(), up.end());
		reverse(up.begin(), up.end());
		int zi = opnal.z;
		for (auto u : up) {
			while (zi > u.z) {
				zi--;
				for (auto g : govanca[zi])
					drvo2.add(g.x, g.y);
			}

			if (drvo2.get(u.xl, u.xr, u.yl, u.yr))
				ans[u.id] = CLOSED;
		}
	}

	for (int i=0; i<k; i++)
		if (ans[i] == OPEN)
			puts("OPEN");
		else if (ans[i] == CLOSED)
			puts("CLOSED");
		else
			puts("UNKNOWN");
}