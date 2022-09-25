#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXN = 1 << 18;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

ll gcd(ll a, ll b) {
	a = abs(a), b = abs(b);
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}
//typedef double d;
/*
struct d {
ll x, y;

d() : x(0), y(1) {}
d(ll x) : x(x), y(1) {}
d(ll x, ll y) {
ll g = gcd(x, y);
this->x = x / g;
this->y = y / g;
}

d operator+ (const d &o) const {
ll g = gcd(y, o.y);
ll ny = y / g * o.y;
ll nx = x * (ny / y) + o.x * (ny / o.y);
return d(nx, ny);
}

d operator* (ll o) const {
ll g = gcd(o, y);
return d(x * (o / y), y / g);
}

d operator- (const d &o) const {
return (*this) + (o * -1);
}

d operator* (const d &o) const {
ll g1 = gcd(x, o.y);
ll g2 = gcd(y, o.x);
return d((x / g1) * (o.x / g2), (y / g2) * (o.y / g1));
}

bool operator< (const d &o) const {
return x * o.y < o.x * y;
}
};*/

double d(ll a, ll b) {
	return a * 1.0 / b;
}

int n, t, q;
int ct;
int p[MAXN], l[MAXN];
ll cnt[MAXN];

double ans;
double ifAdd[MAXN], ifDel[MAXN];
set<pair<double, int> > stAdd, stDel;

void setIfAdd(int id) {
	if (cnt[id] == l[id]) ifAdd[id] = -10000;
	else ifAdd[id] = d(p[id] * (cnt[id] + 1), cnt[id] + 1 + l[id]) - d(p[id] * cnt[id], cnt[id] + l[id]);
}

void setIfDel(int id) {
	if (cnt[id] == 0) ifDel[id] = 10000;
	else ifDel[id] = d(p[id] * cnt[id], cnt[id] + l[id]) - d(p[id] * (cnt[id] - 1), cnt[id] + l[id] - 1);
}

double getExp(int id) {
	return cnt[id] * p[id] * 1.0 / (l[id] + cnt[id]);
}

void addTicket(int id) {
	stAdd.erase(make_pair(ifAdd[id], id));
	stDel.erase(make_pair(ifDel[id], id));

	ans -= getExp(id);
	cnt[id]++, ct++;
	setIfAdd(id);
	setIfDel(id);
	ans += getExp(id);

	stAdd.insert(make_pair(ifAdd[id], id));
	stDel.insert(make_pair(ifDel[id], id));
}

void delTicket(int id) {
	stAdd.erase(make_pair(ifAdd[id], id));
	stDel.erase(make_pair(ifDel[id], id));

	ans -= getExp(id);
	cnt[id]--, ct--;
	setIfAdd(id);
	setIfDel(id);
	ans += getExp(id);

	stAdd.insert(make_pair(ifAdd[id], id));
	stDel.insert(make_pair(ifDel[id], id));
}

void init() {
	stAdd.clear();
	stDel.clear();
	ans = 0;
	ct = 0;
	for (int i = 0; i < n; i++) {
		cnt[i] = 0;
		setIfAdd(i);
		setIfDel(i);
		stAdd.insert(make_pair(ifAdd[i], i));
		stDel.insert(make_pair(ifDel[i], i));
	}

	for (int i = 0; i < t; i++) {
		int id = stAdd.rbegin()->second;
		if (!(d(0, 1) < stAdd.rbegin()->first)) continue;
		addTicket(id);
	}
}

void fix(int id) {
	stAdd.erase(make_pair(ifAdd[id], id));
	stDel.erase(make_pair(ifDel[id], id));

	if (cnt[id] > l[id]) cnt[id]--, ct--;
	while (ct < t && cnt[id] < l[id]) cnt[id]++, ct++;

	while (!stAdd.empty()) {
		setIfAdd(id);
		setIfDel(id);
		if (ifDel[id] < stAdd.rbegin()->first) {
			int nid = stAdd.rbegin()->second;
			addTicket(nid);
			cnt[id]--;
			ct--;
		}
		else break;
	}
	while (!stDel.empty()) {
		setIfAdd(id);
		setIfDel(id);
		if (stDel.begin()->first < ifAdd[id]) {
			int nid = stDel.begin()->second;
			delTicket(nid);
			cnt[id]++;
			ct++;
		}
		else break;
	}
	while (ct < t) {
		if (d(0, 1) < stAdd.rbegin()->first) {
			addTicket(stAdd.rbegin()->second);
		}
		else break;
	}

	setIfAdd(id);
	setIfDel(id);
	stAdd.insert(make_pair(ifAdd[id], id));
	stDel.insert(make_pair(ifDel[id], id));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif


	while (scanf("%d%d%d", &n, &t, &q) == 3) {
		for (int i = 0; i < n; i++) scanf("%d", &p[i]);
		for (int i = 0; i < n; i++) scanf("%d", &l[i]);

		init();
		for (int i = 0; i < q; i++) {
			int t, id;
			scanf("%d%d", &t, &id);
			--id;
			ans -= getExp(id);
			if (t == 1) {
				l[id]++;
			}
			if (t == 2) {
				l[id]--;
			}
			fix(id);
			ans += getExp(id);
			printf("%.15f\n", ans);
		}
	}

	return 0;
}