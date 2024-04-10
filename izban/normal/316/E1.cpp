#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 18;
const int inf = 1000000007;
const int mod = 1000000000 ;

struct item {
	int prior, cnt, value, sum1, sum2;
	item *l, *r;

	item() {prior = 0; cnt = 0; value = 0; sum1 = 0; sum2 = 0; l = 0; r = 0;}
};

typedef item * pitem;

int cnt(pitem t) {
	return t? t->cnt : 0;
}

int sum1(pitem t) {
	return t? t->sum1 : 0;
}

int sum2(pitem t) {
	return t? t->sum2 : 0;
}

ll a11, a12, a21, a22;
ll q11, q12, q21, q22;

pair<int, int> lol(int r12, int r11, int n) {
	 a11 = 1, a12 = 1, a21 = 1, a22 = 0;
	 q11 = 0, q12 = 0, q21 = 0, q22 = 0;
	while (n) {
		if (n & 1) {
			q11 = (r11 * a11 + r12 * a21) % mod;
			r12 = (r11 * a12 + r12 * a22) % mod;
			r11 = q11;
			//r12 = q12;
		}
        q11 = (a11 * a11 + a12 * a21) % mod;
        q12 = (a11 * a12 + a12 * a22) % mod;
        q21 = (a21 * a11 + a22 * a21) % mod;
        a22 = (a21 * a12 + a22 * a22) % mod;
        a11 = q11;
        a12 = q12;
        a21 = q21;
        //a22 = q22;
		n >>= 1;
	}
	return make_pair(r12, r11);
}

void push2(pitem t) {
	if (t) {
		t->cnt = cnt(t->l) + cnt(t->r) + 1;
	}
}

void push1(pitem t) {
	if (t) {
		pair<int, int> o1 = lol(t->value, t->value, cnt(t->l));
		pair<int, int> o2 = lol(sum1(t->r), sum2(t->r), cnt(t->l) + 1);
		t->sum1 = sum1(t->l);
		t->sum1 += o1.first; if (t->sum1 >= mod) t->sum1 -= mod;
		t->sum1 += o2.first; if (t->sum1 >= mod) t->sum1 -= mod;
		t->sum2 = sum2(t->l);
		t->sum2 += o1.second; if (t->sum2 >= mod) t->sum2 -= mod;
		t->sum2 += o2.second; if (t->sum2 >= mod) t->sum2 -= mod;
	}
}

void merge(pitem &t, pitem l, pitem r) {
	if (!l || !r) t = l ? l : r;
	else if (l->prior > r->prior)
		merge(l->r, l->r, r), t = l;
	else
		merge(r->l, l, r->l), t = r;
	push1(t); push2(t);
}

void split(pitem t, pitem &l, pitem &r, int key, int add = 0) {
	if (!t) return void(l = r = 0);
	int cur_key = add + cnt(t->l);
	if (key <= cur_key)
		split(t->l, l, t->l, key, add), r = t;
	else
		split(t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;
	push1(t); push2(t);
}

int n, m;
int a[maxn], q[maxn], x1[maxn], x2[maxn], x3[maxn];
item b[maxn];
pitem t;

bool reading() {
	//if (!(cin >> n >> m)) return 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &q[i], &x1[i], &x2[i]);
		if (q[i] == 3) scanf("%d", &x3[i]);
	}
	return 1;
}

void print(vector<int> v) {
	for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
}

vector<int> slowsolve() {
	vector<int> res;
	for (int i = 0; i < m; i++) {
		if (q[i] == 1) {
			a[x1[i] - 1] = x2[i];
		}
		if (q[i] == 2) {
			int f0 = 1, f1 = 1, ans = 0;
			for (int j = x1[i] - 1; j <= x2[i] - 1; j++) {
				ans = (ans + (1LL * a[j] * f0 % mod)) % mod;
				int f2 = (f0 + f1) % mod;
				f0 = f1;
				f1 = f2;
			}
			res.push_back(ans);
		}
	}
	return res;
}

vector<int> fastsolve() {
	t = 0;
	vector<int> res;
	for (int i = 0; i < n; i++) {
		b[i].value = a[i];
		b[i].prior = (rand() << 15) + rand();
		b[i].cnt = 1;
		b[i].l = b[i].r = 0;
		push2(&b[i]);
		merge(t, t, &b[i]);
	}

	for (int i = 0; i < m; i++) {
		if (q[i] == 1) {
			pitem t1 = 0, t2 = 0, t3 = 0;
			split(t, t1, t2, x1[i] - 1);
			split(t2, t2, t3, 1);
			t2->value = x2[i];
			merge(t2, t2, t3);
			merge(t, t1, t2);
		}
		if (q[i] == 2) {
			pitem t1 = 0, t2 = 0, t3 = 0;
			split(t, t1, t2, x1[i] - 1);
			split(t2, t2, t3, x2[i] - x1[i] + 1);
			res.push_back(sum1(t2));
			merge(t2, t2, t3);
			merge(t, t1, t2);
		}
	}
	return res;
}

void gen() {
	n = rand() % 30 + 1;
	m = rand() % 30 + 1;
	for (int i = 0; i < n; i++) a[i] = rand() % 10 + 1;
	for (int i = 0; i < m; i++) {
		q[i] = rand() % 2 + 1;
		x1[i] = rand() % n + 1;
		x2[i] = rand() % n + 1;
		if (x1[i] > x2[i]) swap(x1[i], x2[i]);
		x3[i] = rand() % n + 1;
	}
}

void stress() {
	for (int it = 0; it < 1000; it++) {
		gen();
		vector<int> a2 = fastsolve();
		vector<int> a1 = slowsolve();
		if (a1 != a2) {
			cout << n << " " << m << endl;
			for (int i = 0; i < n; i++) cout << a[i] << " \n"[i + 1 == n];
			for (int i = 0; i < m; i++) {
				cout << q[i] << " " << x1[i] << " " << x2[i];
				if (q[i] == 3) cout << " " << x3[i];
				cout << endl;
			}
			cout << endl;
			for (int i = 0; i < a1.size(); i++) cout << a1[i] << " \n"[i + 1 == a1.size()];
			for (int i = 0; i < a2.size(); i++) cout << a2[i] << " \n"[i + 1 == a2.size()];
			cout << it << endl;
			fastsolve();
			slowsolve();
			break;
		}
		cerr << it << endl;
	}
	exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    srand(13);
	if (0) stress();
	if (reading()) print(fastsolve());

	return 0;
}