#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 100005;

llint n, k, l, r;
bool naso;

bool pitaj (llint x, llint y) {
	if (naso) return 1;
	cout << x << " " << y << endl;
	string s;
	cin >> s;
	if (x == y && s == "Yes") {
		naso = 1;
		return 1;
	}
	if (s == "Yes") return 1; return 0;
}

llint nxt (llint x) {
	if (x % 2 == 0) return x/2 + 2*k;
	return (x+1)/2 + 2*k;
}

bool pikni () {
	llint x = l + rand() % (r - l + 1);
	l = max(1LL, l - k);
	r = min(n, r + k);
	return pitaj(x, x);
}

void suzi () {
	while ((r - l + 1) > nxt(r - l + 1)) {
		if (naso) break;
		llint mid = (l + r) / 2;
		if (pitaj(l, mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
		l = max(1LL, l - k);
		r = min(n, r + k);
	}
}

int main () {
	srand(time(0) * getpid());
	cin >> n >> k;
	l = 1; r = n;
	while (1) {
		suzi();
		if (naso) break;
		if (pikni()) break;
		if (naso) break;
	}
	return 0;
}