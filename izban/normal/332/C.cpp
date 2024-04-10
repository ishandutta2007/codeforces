#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n, p, k;
vector<pair<pair<int, int>, int> > v;

bool cmp1(pair<pair<int, int>, int> i, pair<pair<int, int>, int> j) {
	if (i.first.second != j.first.second)
		return i.first.second > j.first.second;
	return i.first.first < j.first.first;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> p >> k) {
		v.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i].first.first >> v[i].first.second;
			v[i].second = i + 1;
		}
		sort(v.begin(), v.end(), cmp1);
		
		vector<ll> sum1(n), sum2(n + 1);
		set<pair<int, int> > st;

//---------------------------------------------------------------------------
		ll csum = 0;
		for (int i = 0; i < n; i++) {
			if (st.size() < k) {
				st.insert(make_pair(v[i].first.first, i));
				csum += v[i].first.first;
			} else {
				set<pair<int, int> >::iterator it = st.begin();
				if (it->first < v[i].first.first) {
					csum -= it->first;
					st.erase(it);
					st.insert(make_pair(v[i].first.first, i));
					csum += v[i].first.first;
				}
			}
			sum1[i] = csum;
		}
		
		st.clear();
		csum = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (st.size() < p - k) {
				st.insert(make_pair(v[i].first.second, i));
				csum += v[i].first.second;
			} else if (p - k) {
				set<pair<int, int> >::iterator it = st.begin();
				if (it->first < v[i].first.second) {
					csum -= it->first;
					st.erase(it);
					st.insert(make_pair(v[i].first.second, i));
					csum += v[i].first.second;
				}
			}
			sum2[i] = csum;
		}

//---------------------------------------------------------------------------
		ll ans1 = -1, ans2 = -1;
		int cans = -1;
		for (int i = k - 1; i + p - k < n; i++) {
			if (ans1 < sum1[i] || ans1 == sum1[i] && ans2 < sum2[i + 1]) {
				ans1 = sum1[i];
				ans2 = sum2[i + 1];
				cans = i;
			}
		}
//---------------------------------------------------------------------------
		set<int> ANS;

		st.clear();
		csum = 0;
		for (int i = 0; i < n; i++) {
			if (st.size() < k) {
				st.insert(make_pair(v[i].first.first, i));
				csum += v[i].first.first;
			} else {
				set<pair<int, int> >::iterator it = st.begin();
				if (it->first < v[i].first.first) {
					csum -= it->first;
					st.erase(it);
					st.insert(make_pair(v[i].first.first, i));
					csum += v[i].first.first;
				}
			}
			sum1[i] = csum;
			if (i == cans) {
				for (set<pair<int, int> > :: iterator it = st.begin(); it != st.end(); it++) {
					ANS.insert(v[it->second].second);
				}
			}
		}
		
		st.clear();
		csum = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (st.size() < p - k) {
				st.insert(make_pair(v[i].first.second, i));
				csum += v[i].first.second;
			} else if (p - k) {
				set<pair<int, int> >::iterator it = st.begin();
				if (it->first < v[i].first.second) {
					csum -= it->first;
					st.erase(it);
					st.insert(make_pair(v[i].first.second, i));
					csum += v[i].first.second;
				}
			}
			sum2[i] = csum;
			if (i == cans + 1) {
				for (set<pair<int, int> > :: iterator it = st.begin(); it != st.end(); it++) {
					ANS.insert(v[it->second].second);
				}
			}
		}
//---------------------------------------------------------------------------

		for (set<int> :: iterator it = ANS.begin(); it != ANS.end(); it++) cout << *it << " ";
		cout << endl;
	}

	return 0;
}