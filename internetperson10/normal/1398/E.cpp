#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

set<ll> s0, s1, s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	s0.insert(0);
	s.insert(0);
	auto it_s = s.begin(); // last thing that isn't in top k
	ll top = 0, sum = 0;
	for(int i = 0; i < n; i++) {
		int x, c;
		cin >> x >> c;
		sum += c;
		if(c > 0) {
			s.insert(c);
			if(c < *it_s && x == 0) {

			}
			if(c > *it_s && x == 0) {
				it_s++;
				top += c;
				top -= *it_s;
			}
			if(c < *it_s && x == 1) {
				top += *it_s;
				it_s--;
			}
			if(c > *it_s && x == 1) {
				top += c;
			}
			if(x == 0) s0.insert(c);
			else s1.insert(c);
		}
		else {
			if(-c < *it_s && x == 0) {

			}
			if(-c >= *it_s && x == 0) {
				top += *it_s;
				it_s--;
				top += c;
			}
			if(-c <= *it_s && x == 1) {
				it_s++;
				top -= *it_s;
			}
			if(-c > *it_s && x == 1) {
				top += c;
			}
			s.erase(-c);
			if(x == 0) s0.erase(-c);
			else s1.erase(-c);
		}
		auto it = s0.end();
		it--;
		ll highest_0 = *it;
		ll lowest_1 = *(s1.begin());
		// cout << sum << ' ' << top << ' ' << *it_s << ' ' << lowest_1 << ' ' << highest_0 << '\n';
		cout << top + sum - max((ll)0, lowest_1 - highest_0) << '\n';
	}
}