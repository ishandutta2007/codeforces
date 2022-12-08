#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>


#define size(x) (x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;

const ll inf0 = 2 * 1024 * 1024 * 1023;
const ll inf = inf0 * inf0;
double eps = 1e-6;
ll mod = 1e9+ 7;

mt19937 mrand(random_device{} ());

const int N = 1e4 + 7;

int t[N];
int n;


int sum(int r) {
	if (r < 0) return 0;
	int ans = 0;
	for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
		ans += t[i];
	}
	return ans;
}

void add(int r, int k) {
	for (int i = r; i < N; i = (i | (i + 1))) {
		t[i] += k;
	}
}


int ask(int l, int r) {
	return sum(r) - sum(l - 1);
}

struct Point {
	int x, y;
	Point() {}
	Point(int _x, int _y) : x(_x), y(_y) {}
}; istream& operator>>(istream& in, Point& A) {
	in >> A.x >> A.y; A.x += 5e3; A.y += 5e3;
	return in;
}

struct Item {
	int tp;
	Point A, B;
	Item() {}
	Item(int _t, Point _A, Point _B) : tp(_t), A(_A), B(_B) {}
};

struct Seg {
	Point A, B;
	Seg() {}
}; istream& operator>>(istream& in, Seg& A) {
	in >> A.A >> A.B;
	if (A.A.y == A.B.y && A.A.x > A.B.x) swap(A.A, A.B);
	if (A.A.x == A.B.x && A.A.y > A.B.y) swap(A.A, A.B);
	return in;
}

bool cmp(Item a, Item b) {
	if (a.A.y == b.A.y) return a.tp < b.tp;
	return a.A.y < b.A.y;
}

bool between(int a, int l, int r) { return l <= a && a <= r; }

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	#endif
	
	int n;
	cin >> n;
	ll ans = 0;
	vector<Seg> a(n);
	for (Seg& i : a) cin >> i;
	for (int cur = 0; cur < n; cur++) {
		vector<Item> ed;
		if (a[cur].A.y != a[cur].B.y) continue;
		for (int j = 0; j < n; j++) {
			if (a[j].A.y == a[j].B.y) {
				if (a[j].A.y <= a[cur].A.y) continue;
				ed.push_back({ 0, a[j].A, a[j].B });
			}
			else {
				if (between(a[j].A.x, a[cur].A.x, a[cur].B.x) && a[j].A.y <= a[cur].A.y) {
					ed.push_back({ 1, a[j].B, a[j].A });
					add(a[j].A.x, 1);
				}
			}
		}
		sort(all(ed), cmp);
		for (auto u : ed) {
			if (u.tp == 0) {
				ll ss = ask(u.A.x, u.B.x);
				ans += ss * (ss - 1) / 2;
			}
			else {
				add(u.A.x, -1);
			}
		}
	}
	cout << ans << endl;
	return 0;
}