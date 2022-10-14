#include<bits/stdc++.h>
using namespace std;
const int local = 0;
int lx, rx, ly, ry;
int ask(int A, int B) {
	vector<array<int, 2>> pts;
	for(int x = 1; x <= 200; x++)
		for(int y = 1; y <= 200; y++) if(x%A == 0 && y%B == 0)
			pts.push_back({x, y});
	if(pts.empty()) return 0;
	if(!local) {
		cout << "? " << pts.size() << " ";
		for(auto [x, y] : pts) cout << x << " " << y << " "; cout << endl;
	}
	int t = 0;
	if(local) {
		for(auto [x, y] : pts)
			t += x >= lx && x <= rx && y >= ly && y <= ry;
	} else cin >> t;
	return t;
}
void answer(int A = 0, int x = -1) {
	assert(A%x == 0);
	A /= x;
	if(local && 2*(A+x-2) != 2*(rx+ry-lx-ly))
		cout << "OOPS " << rx << " " << ry << " " << 2*(A+x-2), exit(1);
	cout << "! " << 2*(A+x-2) << endl;
}
#define ctz __builtin_ctz
int calc(int A, int p) {
	return min(ctz(A)-ctz(p), ctz(p));
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	if(local) cin >> lx >> ly >> rx >> ry;
	// lx=ly=1;
	// for(rx = 1; rx <= 200; rx++)
	// for(ry = 1; ry <= 200; ry++)
	{
	int A = ask(1, 1);
	for(auto p : {2, 3, 5, 7}) {
		if(A%(p*p) == 0) continue;
		int v;
		if(A%p == 0) {
			v = ask(p, p)*p;
		} else {
			v = ask(1, p);
		}
		v = abs(v*p-A);
		vector<int> opts;
		for(int z = 1; z < 5; z*=2)
			if(p > z-1 && v%z == 0)
				opts.push_back(calc(A, v/z));
		sort(opts.begin(), opts.end());
		opts.erase(unique(opts.begin(), opts.end()), opts.end());
		int c = 0, uh = -1;
		auto can = [&](int low) {
			if(low < 0) return 0;
			int x = low*2 == ctz(A);
			low = 2<<low;
			if(x)
				return abs(A - ask(1, low)*low)/(low/2);
			else
				return abs(A - ask(low, low)*low*low)/(low/2);
		};
		if(opts.size() < 3) {
			for(auto i : opts)
				if(uh = can(i))
					break;
		} else {
			if(!(uh = can(opts[1])))
				uh = can(opts.back());
			else {
				int t = can(opts[0]);
				if(t)
					uh = t;
			}
		}
		answer(A, uh);
		break;
	}
	}
}