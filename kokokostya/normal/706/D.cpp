#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <queue>
#include <cstdio>

using namespace std;

struct vert {
	int l, r, val;
	int p;
	bool isleft;
};

int n = 0;

vector<vert> tree;

void add(int x) {
	int now = 0;
	int y = 1 << 30;
	while (y) {
		if (x & y) {
			if (tree[now].r)
				now = tree[now].r;
			else {
				n++;
				tree.push_back({ 0, 0, 0, now, 0 });
				tree[now].r = n;
				now = n;
			}
		}
		else {
			if (tree[now].l)
				now = tree[now].l;
			else {
				n++;
				tree.push_back({ 0, 0, 0, now, 1 });
				tree[now].l = n;
				now = n;
			}
		}
		tree[now].val++;
		y >>= 1;
	}
	return;
}

void del(int x) {
	int now = 0;
	int y = 1 << 30;
	while (y) {
		if (x & y) {
				now = tree[now].r;
		}
		else {
				now = tree[now].l;
		}
		tree[now].val--;
		if (tree[now].val == 0) {
			if (tree[now].isleft)
				tree[tree[now].p].l = 0;
			else
				tree[tree[now].p].r = 0;
		}
		y >>= 1;
	}
	return;
}

int ask(int x) {
	int now = 0;
	int y = 1 << 30;
	while (y) {
		if (x & y) {
			if (tree[now].l) 
				now = tree[now].l;
			else {
				now = tree[now].r;
				x ^= y;
			}
		}
		else {
			if (tree[now].r) {
				now = tree[now].r;
				x ^= y;
			}
			else {
				now = tree[now].l;
			}
		}
		y >>= 1;
	}
	return x;
}

int main() {
	int q;
	scanf("%d", &q);
	tree.push_back({ 0, 0, 1000000, 0, 0 });
	add(0);
	while (q--) {
		char c;
		int x;
		scanf("%c%c%d", &c, &c,&x);
		if (c == '+')
			add(x);
		if (c == '-')
			del(x);
		if (c == '?')
			printf("%d\n", ask(x));
	}
	
	return 0;
}