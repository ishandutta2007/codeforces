#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <iomanip>
#include <deque>
#include <stack>
#include <cmath>
#include <unordered_set>

using namespace std;

//inline void operator delete (void *) {};


int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k, m, a;
	cin >> n >> k >> m >> a;
	vector< pair<int, pair<int, int> > > cnt(n);
	for (int i = 0; i < n; i++)
		cnt[i].second.second = i;
	for (int i = 0; i < a; i++){
		int to;
		cin >> to;
		cnt[to - 1] = { cnt[to - 1].first + 1, { -i, to - 1 } };
	}
	sort(cnt.begin(), cnt.end());
	vector<int> ans(n);
	for (int i = 0; i < n; i++){
		bool is1 = 0, is2 = 0;
		auto ws = cnt[i];
		cnt[i].first += m - a;
		cnt[i].second.first = -m - 1;
		int out = 0;
		for (int j = 0; j < n; j++){
			if (i != j && cnt[i] > cnt[j])
				out++;
		}
		if (out >= n - k && cnt[i].first != 0)
			is1 = 1;
		cnt[i] = ws;
		int now = m - a;
		out = 0;
		for (int j = n - 1; j >= 0; j--){
			if (j > i && cnt[j].first > 0){
				out++;
			}
			else{
				if (i != j && now >= max(0, cnt[i].first - cnt[j].first + 1)){
					now -= max(0, cnt[i].first - cnt[j].first + 1);
					out++;
				}
			}
		}
		if (out >= k || cnt[i].first == 0)
			is2 = 1;
		if (is2 == 0){
			ans[i] = 1;
		}
		else
		if (is1 == 1){
			ans[i] = 2;
		}
		else{
			ans[i] = 3;
		}
	}
	vector<int> get(n);
	for (int i = 0; i < n; i++)
		get[cnt[i].second.second] = ans[i];
	for (int i : get)
		cout << i << ' ';
	return 0;
}