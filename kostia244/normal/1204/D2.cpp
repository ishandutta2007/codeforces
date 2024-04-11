#include<bits/stdc++.h>
using namespace std;

string s;

//chekc radoslav11 at github out for nice seg tree implementations
struct node {//struct for segment tree node
	int o, z, zo;//o - number of Ones, z - nomber of Zeroes, zo - answer
	node(int i = -1) {
		if (i == -1)
			zo = o = z = 0;
		else {
			zo = 1; o = z = 0;
			if (i)
				o = 1;
			else
				z = 1;
		}
	}
};
//segment tree itself
node seg[400400];

node merge(node a, node b) {
	a.zo = max({a.z + b.zo, a.zo + b.o, a.z + b.z, a.z + b.o, a.o+b.o});
	a.o += b.o;
	a.z += b.z;
	return a;
}

void build(int v, int l, int r) {
	if (l == r) {
		seg[v] = node(s[l-1] - '0');
	} else {
		int mid = (l + r) / 2;
		build(2 * v, l, mid);
		build(2 * v + 1, mid + 1, r);
		seg[v] = merge(seg[2 * v], seg[2 * v + 1]);
	}
}

void upd(int v, int l, int r, int i, int val) {
	if (l == r) {
		seg[v] = node(val);
	} else {
		int mid = (l + r) / 2;
		if (i <= mid)
			upd(2 * v, l, mid, i, val);
		else
			upd(2 * v + 1, mid + 1, r, i, val);
		seg[v] = merge(seg[2 * v], seg[2 * v + 1]);
	}
}

int main() {
	//fast i/o
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//input
	cin >> s;

	//build seg tree
	build(1, 1, s.size());

	int x = seg[1].zo;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')
			continue;
		//try to set s[i] to 0
		s[i] = '0';
		upd(1, 1, s.size(), i+1, 0);
		if (x != max( { seg[1].o, seg[1].zo, seg[1].z })) {// it changes the LIS, set it back to 1
			s[i] = '1';
			upd(1, 1, s.size(), i+1, 1);
		}
	}
	cout << s;//print the answer
}