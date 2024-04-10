#include <iostream>
#include <vector>
#include <array>
using namespace std;

#define VAL_SIZE 60

typedef array<int, VAL_SIZE> TValue;

TValue GetPrimitiveValue(int p) {
	TValue result;
	for (int i = 0; i < 60; ++i) {
		if (i % p == 0) {
			result[i] = 2;
		} else {
			result[i] = 1;
		}
	}
	return result;
}

TValue Sum(const TValue& l, const TValue& r) {
	TValue result;
	for (int i = 0; i < VAL_SIZE; ++i) {
		result[i] = l[i] + r[(i + l[i]) % VAL_SIZE];
	}
	return result;
}

const int MAXN = 1<<17;

TValue tree[MAXN * 2];

void set(int p, int y) {
	p += MAXN;
	tree[p] = GetPrimitiveValue(y);
	while (p != 1) {
		p /= 2;
		tree[p] = Sum(tree[p * 2], tree[p * 2 + 1]);
	}
}

TValue get(int l, int r) {
	l += MAXN;
	r += MAXN;
	if (l == r) {
		return tree[l];
	}
	TValue lval = tree[l];
	TValue rval = tree[r];
	while (l + 1 != r) {
		if (l % 2 == 0) {
			lval = Sum(lval, tree[l + 1]);
		}
		if (r % 2 == 1) {
			rval = Sum(tree[r - 1], rval);
		}
		l/=2; r/=2;
	}
	return Sum(lval, rval);
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		set(i, a);
	}
	int q;
	cin >> q;
	while (q--) {
		char c[10];
		int x, y;
		cin >> c >> x >> y;
		switch(c[0]) {
		case 'A':
			cout << get(x-1, y-2)[0] << endl;
			break;
		case 'C':
			set(x - 1, y);
			break;
		default:
			return -1;
		}
	}
}