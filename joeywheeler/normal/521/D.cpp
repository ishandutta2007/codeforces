#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define N 100005

using namespace std;

typedef long long ll;

struct op {
	int id, t; ll b;
	bool operator<(const op &o) const { return b > o.b; }
};

struct ov {
	double delta; int id;
	bool operator<(const ov &o) const { return delta > o.delta; }
};

vector<op> v[100005];
ll oval[100005];
int k, n, m;
vector<ov> r;

void addops(int i) {
	ll b = oval[i]; op *bop;
	for (op &o : v[i]) if (o.t == 1 && o.b > b) {
		b = o.b;
		bop = &o;
	}
	if (b != oval[i]) {
		bop->t = 2; bop->b -= oval[i];
	}
	sort(v[i].begin(),v[i].end());
	ll val = oval[i];
	for (op o : v[i]) {
		ov x; x.id = o.id;
		if (o.t == 3) {
			x.delta = o.b;
			r.push_back(x);
		} else if (o.t == 2) {
			x.delta = (val+o.b)/1./val;
			val += o.b;
			r.push_back(x);
		}
	}
}

int TV[100005];
bool cmp(int i, int j) {
	return TV[i] < TV[j];
}

int main() {
	scanf("%d %d %d", &k, &n, &m);

	FO(i,0,k) scanf("%lld", &oval[i]);
	FO(i,0,n) {
		int T, I; ll B; scanf("%d %d %lld", &T, &I, &B); I--;
		TV[i+1] = T;
		v[I].push_back({i+1, T, B});
	}
	FO(i,0,k) addops(i);
	sort(r.begin(),r.end());
	vector<int> res;
	FO(i,0,min(m,sz(r))) res.push_back(r[i].id);
	sort(res.begin(),res.end(),cmp);

	printf("%d\n", sz(res));
	FO(i,0,sz(res)) printf("%d ", res[i]);
	printf("\n");
}