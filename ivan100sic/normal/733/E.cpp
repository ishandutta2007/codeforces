/*

UUD
^
DUD
 ^
DDD
  ^
DDU
 ^
DUU
^
UUU
<

RRLRLRRLLR
    ^
RRLRRRRLLR
   ^
RRLLRRRLLR
    ^
RRLLLRRLLR
     ^
RRLLLLRLLR
      ^
RRLLLLLLLR
       ^
RRLLLLLRLR
      ^
RRLLLLRRLR
     ^
RRLLLRRRLR
    ^
RRLLRRRRLR
   ^
RRLRRRRRLR
  ^
RRRRRRRRLR
 ^
RLRRRRRRLR
  ^


RRRLLLLLLRRR
     ^
RRRRRRLLLRRR
  ^
RRLLLLLLLRRR
      ^
RRRRRRRLLRRR
 ^
RLLLLLLLLRRR
       ^
RRRRRRRRLRRR
^
LLLLLLLLLRRR
        ^
RRRRRRRRRRRR
<

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

vector<int> upos, dpos;
vector<long long> upos_pos_sum, dpos_pos_sum;
vector<long long> upos_cnt_sum, dpos_cnt_sum;
string s;
int n;

long long range_sum(const vector<long long>& v, int l, int r) {
	// cerr << "Range sum " << l << ' ' << r << '\n';

	if (l > r) return 0;
	if (r >= v.size()) {
		r = v.size() - 1;
	}
	if (l < 0) {
		l = 0;
	}	
	
	l--;
	return v[r] - (l >= 0 ? v[l] : 0);
}

int main() {
	cin >> n;
	cin >> s;
	s = string("U") + s + string("D");

	upos_pos_sum.resize(n+2);
	dpos_pos_sum.resize(n+2);
	upos_cnt_sum.resize(n+2);
	dpos_cnt_sum.resize(n+2);
	
	for (int i=0; i<=n+1; i++) {
		if (i > 0) {
			upos_pos_sum[i] = upos_pos_sum[i-1];
			dpos_pos_sum[i] = dpos_pos_sum[i-1];
			upos_cnt_sum[i] = upos_cnt_sum[i-1];
			dpos_cnt_sum[i] = dpos_cnt_sum[i-1];
		}
		if (s[i] == 'U') {
			upos.push_back(i);
			upos_cnt_sum[i]++;
			upos_pos_sum[i] += i;
		} else {
			dpos.push_back(i);
			dpos_cnt_sum[i]++;
			dpos_pos_sum[i] += i;
		}
	}

	vector<long long> sols;

	for (int i=1; i<=n; i++) {
		if (s[i] == 'D') {
			long long obs_levo = range_sum(upos_cnt_sum, 1, i-1);
			long long obs_desno = range_sum(dpos_cnt_sum, i+1, n);

			if (obs_levo > obs_desno) {
				int br = obs_desno;

				auto it_levo = lower_bound(upos.begin(), upos.end(), i) - br;
				auto it_desno = lower_bound(dpos.begin(), dpos.end(), i) + br;

				int p_levo = !br ? i : *it_levo;
				int p_desno = !br ? i : *it_desno;

				// cerr << i << ' ' << br << ' ' << p_levo << ' ' << p_desno << '\n';

				long long x = 0;

				x += range_sum(dpos_pos_sum, i+1, p_desno) - range_sum(upos_pos_sum, p_levo, i-1);
				x *= 2;

				x += i - *prev(it_levo);
				x += n+1 - *prev(it_levo);

				sols.push_back(x);
			} else {
				int br = obs_levo;

				auto it_levo = lower_bound(upos.begin(), upos.end(), i) - br;
				auto it_desno = lower_bound(dpos.begin(), dpos.end(), i) + br;

				int p_levo = !br ? i : *it_levo;
				int p_desno = !br ? i : *it_desno;

				// cerr << i << ' ' << br << ' ' << p_levo << ' ' << p_desno << '\n';

				long long x = 0;

				x += range_sum(dpos_pos_sum, i+1, p_desno) - range_sum(upos_pos_sum, p_levo, i-1);
				x *= 2;

				x += i;

				sols.push_back(x);
			}
		} else {

			long long obs_levo = range_sum(upos_cnt_sum, 1, i-1);
			long long obs_desno = range_sum(dpos_cnt_sum, i+1, n);

			if (obs_levo < obs_desno) {
				int br = obs_levo;

				auto it_levo = lower_bound(upos.begin(), upos.end(), i) - br;
				auto it_desno = lower_bound(dpos.begin(), dpos.end(), i) + (br - 1);

				int p_levo = !br ? i : *it_levo;
				int p_desno = !br ? i : *it_desno;

				// cerr << i << ' ' << br << ' ' << p_levo << ' ' << p_desno << '\n';

				long long x = 0;

				x += range_sum(dpos_pos_sum, i+1, p_desno) - range_sum(upos_pos_sum, p_levo, i-1);
				x *= 2;

				x += *next(it_desno) - i;
				x += *next(it_desno);

				sols.push_back(x);
			} else {
				int br = obs_desno;

				auto it_levo = lower_bound(upos.begin(), upos.end(), i) - br;
				auto it_desno = lower_bound(dpos.begin(), dpos.end(), i) + (br - 1);

				int p_levo = !br ? i : *it_levo;
				int p_desno = !br ? i : *it_desno;

				// cerr << i << ' ' << br << ' ' << p_levo << ' ' << p_desno << '\n';

				long long x = 0;

				x += range_sum(dpos_pos_sum, i+1, p_desno) - range_sum(upos_pos_sum, p_levo, i-1);
				x *= 2;

				x += n+1-i;

				sols.push_back(x);
			}
		}
	}
	for (long long x : sols) {
		cout << x << ' ';
	}
}