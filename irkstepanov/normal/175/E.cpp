#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int cnt[3];
int r[3];
int damage[2];

const ld eps = 1e-4;
const ld inf = 1e9;

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

bool lt(ld a, ld b) {
	return b - a > eps;
}

bool gt(ld a, ld b) {
	return a - b > eps;
}

bool leq(ld a, ld b) {
	return lt(a, b) || eq(a, b);
}

bool geq(ld a, ld b) {
	return gt(a, b) || eq(a, b);
}

struct event {
	ld pos;
	char type;
	bool operator<(const event& other) const {
		return lt(pos, other.pos);
	}
};

bool bit(int mask, int pos) {
	return (mask >> pos) & 1;
}

struct segment {
	ld lf, rg;
	int k;
};

bool in(ld pos, const segment& s) {
	return geq(pos, s.lf) && leq(pos, s.rg);
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	int n = 0;

	for (int i = 0; i < 3; ++i) {
		cin >> cnt[i];
		n += cnt[i];
	}
	for (int i = 0; i < 3; ++i) {
		cin >> r[i];
	}
	for (int i = 0; i < 2; ++i) {
		cin >> damage[i];
	}

	int b = n / 2;
	int a = n - b;

	ld ans = 0;

	ld width[3];
   	for (int i = 0; i < 3; ++i) {
		if (r[i] == 1) {
			width[i] = 0;
		} else {
			width[i] = sqrt(ld(r[i] * r[i]) - 1);
		}
	}

	for (int mask = 0; mask < (1 << n); ++mask) {
		if (__builtin_popcount(mask) == cnt[2]) {
			vector<event> events;
			for (int r = 0; r < n; ++r) {
				if (bit(mask, r)) {
					int x = r;
					if (x >= a) {
						x -= a;
					}
					events.pb({x - width[2], '+'});
					events.pb({x + width[2], '-'});
				}
			}
			sort(all(events));
			vector<segment> segments;
			ld border = -inf;
			int curr = 1;
			for (int i = 0; i < sz(events); ++i) {
				int old = curr;
				if (events[i].type == '+') {
					++curr;
				} else {
					--curr;
				}
				if (i == 0 || !eq(events[i].pos, events[i - 1].pos)) {
					segments.pb({border, events[i].pos, old});
				}
				border = events[i].pos;
			}
			segments.pb({border, inf, 1});

			vector<vector<ld> > profit(n, vector<ld>(2));

			for (int type = 0; type < 2; ++type) {
				int ptr_lf = 0, ptr_rg = 0;
				ld lf = -inf;
			    ld rg = -inf + 2 * width[type];
				ld sum = 2 * width[type];
				for (int i = 0; i < a; ++i) {
					ld u = ld(i) - width[type];
					ld v = ld(i) + width[type];
					while (lt(rg, v)) {
						if (in(v, segments[ptr_rg])) {
							sum += (v - rg) * segments[ptr_rg].k;
							rg = v;
							continue;
						}
						sum += (segments[ptr_rg].rg - rg) * segments[ptr_rg].k;
						rg = segments[ptr_rg].rg;
						++ptr_rg;
					}
					while (lt(lf, u)) {
						if (in(u, segments[ptr_lf])) {
							sum -= (u - lf) * segments[ptr_lf].k;
							lf = u;
							continue;
						}
						sum -= (segments[ptr_lf].rg - lf) * segments[ptr_lf].k;
						lf = segments[ptr_lf].rg;
						++ptr_lf;
					}
					profit[i][type] = sum * damage[type];
					if (i + a < n) {
						profit[i + a][type] = sum * damage[type];
					}
				}
			}

			/*cout << "E\n";
			for (int i = 0; i < sz(events); ++i) {
				cout << events[i].pos << " " << events[i].type << "\n";
			}

			cout << "S\n";

			for (int i = 0; i < sz(segments); ++i) {
				cout << segments[i].lf << " " << segments[i].rg << " " << segments[i].k << endl;
			}

			for (int type = 0; type < 2; ++type) {
				for (int i = 0; i < a; ++i) {
					ld lf = ld(i) - width[type];
					ld rg = ld(i) + width[type];
					ld val = 2 * width[type];
					for (int i = 0; i < n; ++i) {
						if (bit(mask, i)) {
							int x = i;
							if (x >= a) {
								x -= a;
							}
							ld u = x - width[2];
							ld v = x + width[2];
							if (leq(v, lf) || geq(u, rg)) {
								continue;
							}
							val += min(rg, v) - max(lf, u);
						}
					}
					cout << profit[i][type] << " " << val * damage[type] << endl;
					assert(abs(profit[i][type] - val * damage[type]) < 1e-5);
				}
			}*/

			ld sum = 0;
			vector<ld> diff;
			for (int i = 0; i < n; ++i) {
				if (!bit(mask, i)) {
					sum += profit[i][0];
					diff.pb(profit[i][1] - profit[i][0]);
				}
			}
			sort(all(diff));
			reverse(all(diff));
			for (int i = 0; i < cnt[1]; ++i) {
				sum += diff[i];
			}

			/*if (sum > 43500) {
				for (int i = 0; i < a; ++i) {
					if (bit(mask, i)) {
						cout << 1;
					} else {
						cout << 0;
					}
				}
				cout << "\n";
				for (int i = a; i < n; ++i) {
					if (bit(mask, i)) {
						cout << 1;
					} else {
						cout << 0;
					}
				}
				cout << "\n\n";
			}*/
			ans = max(ans, sum);
		}
	}

	cout << fixed;
	cout.precision(12);
	cout << ans << "\n";

}