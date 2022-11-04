#include<bits/stdc++.h>
#define maxn 200000
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;

struct Node {
	int l;
	int r;
	int am0;
	int am1;
	bool good;
};

Node t[maxn * 4 + 10];
int n, q;
string s;

Node sum(Node a, Node b) {
	if(!a.good) return b;
	if(!b.good) return a;
	Node res;
	res.good = true;
	res.am0 = a.am0 + b.am0 + (b.l == a.r && b.l == 0);
	res.am1 = a.am1 + b.am1 + (b.l == a.r && b.l == 1);
	res.l = a.l;
	res.r = b.r;
	return res;
}

void build(int now, int l, int r) {
	if(l == r) {
		t[now].am1 = 0;
		t[now].am0 = 0;
		t[now].good = true;
		t[now].l = (s[l] - '0');
		t[now].r = t[now].l;
		return;
	}
	int mid = (l + r) / 2;
	build(now * 2, l, mid);
	build(now * 2 + 1, mid + 1, r);
	t[now] = sum(t[now * 2], t[now * 2 + 1]);
}

Node get(int now, int l, int r, int l1, int r1) {
	if(l1 > r || l > r1) {
		Node res;
		res.good = false;
		return res;
	}
	if(l1 <= l && r <= r1) return t[now];
	int mid = (l + r) / 2;
	return sum(get(now * 2, l, mid, l1, r1), get(now * 2 + 1, mid + 1, r, l1, r1));
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> n >> q >> s;
	build(1, 0, n - 1);
	for(int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		--l;
		--r;
		auto res = get(1, 0, n - 1, l, r);
		cout << 1 + max(res.am1, res.am0) << '\n';
	}
}