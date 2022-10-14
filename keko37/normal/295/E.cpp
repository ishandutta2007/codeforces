#include<iostream>
#include<cstdio>
#include<set>
#include<unordered_map>

using namespace std;

typedef long long llint;

const int MAXN = 100005;

llint n, m, ofs=1;
llint x[MAXN], org[MAXN];
llint tip[MAXN], p[MAXN], d[MAXN];
set <llint> s, curr;
unordered_map <llint, llint> mp;

struct cvor {
	llint cnt, sum, suf, pre;
	cvor () {
		cnt = sum = suf = pre = 0;
	}
	cvor (llint _cnt, llint _sum, llint _suf, llint _pre) {
		cnt = _cnt; sum = _sum; suf = _suf; pre = _pre;
	}
} t[MAXN*6];

cvor spoji (cvor a, cvor b) {
	cvor res;
	res.cnt = a.cnt + b.cnt;
	res.sum = a.sum + b.sum;
	res.suf = a.suf + b.suf + a.cnt * b.sum;
	res.pre = a.pre + b.pre + b.cnt * a.sum;
	return res;
}

void build () {
	int br = 0;
	for (set <llint> :: iterator it = s.begin(); it!=s.end(); it++) {
		mp[*it] = br;
		br++;
	}
	while (ofs < s.size()) ofs*=2;
	for (int i=1; i<=n; i++) {
		llint ind = mp[x[i]];
		t[ofs + ind] = cvor(1, x[i], x[i], x[i]);
	}
	for (int i=ofs-1; i>=1; i--) {
		t[i] = spoji(t[i*2], t[i*2+1]);
	}
}

void update (llint pos, int flg) {
	int ind = mp[pos] + ofs;
	if (flg == 0) t[ind] = t[0]; else t[ind] = cvor(1, pos, pos, pos);
	ind /= 2;
	while (ind) {
		t[ind] = spoji(t[ind*2], t[ind*2+1]);
		ind /= 2;
	}
}

cvor upit (int node, llint from, llint to, llint low, llint high) {
	if (to<low || high<from) return t[0];
	if (from<=low && high<=to) return t[node];
	return spoji(upit(node*2, from, to, low, (low+high)/2), upit(node*2+1, from, to, (low+high)/2+1, high));
}

int main () {
	cin >> n;
	for (int i=1; i<=n; i++) {
		scanf("%I64d", &x[i]);
		org[i] = x[i];
		s.insert(x[i]);
	}
	curr = s;
	cin >> m;
	for (int i=0; i<m; i++) {
		scanf("%I64d%I64d%I64d", &tip[i], &p[i], &d[i]);
		if (tip[i] == 1) {
			x[p[i]] += d[i];
			s.insert(x[p[i]]);
		}
	}
	for (int i=1; i<=n; i++) {
		x[i] = org[i];
	}
	build();
	for (int i=0; i<m; i++) {
		if (tip[i] == 1) {
			curr.erase(x[p[i]]);
			update(x[p[i]], 0);
			x[p[i]] += d[i];
			curr.insert(x[p[i]]);
			update(x[p[i]], 1);
		} else {
			set <llint> :: iterator it = curr.lower_bound(p[i]);
			if (it == curr.end()) {
				printf("0\n");
				continue;
			}
			llint lef = *it;
			it = curr.upper_bound(d[i]);
			if (it == curr.begin()) {
				printf("0\n");
				continue;
			}
			it--;
			llint rig = *it;
			llint ind1 = mp[lef], ind2 = mp[rig];
			cvor r = upit(1, ind1, ind2, 0, ofs-1);
			printf("%I64d\n", r.suf - r.pre);
		}
	}
	return 0;
}