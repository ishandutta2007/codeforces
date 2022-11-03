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
	int n, T;
	cin >> n >> T;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector< pair<int, int> > del;
	int ans = 0;
	int res = 0;
	vector<bool> add(n);
	for (int i = 0; i < n; i++){
		if (a[i] <= T + i - n){
			res++;
			add[i] = 1;
		}
		else
			del.push_back({ a[i] - (T + i - n), i });
	}
	sort(del.begin(), del.end());
	int now = 0;
	if(T - 1 >= n)
	ans = res;
	int pos = 0;
	while (now + 1 < n){
		now++;
		if (add[n - now])
			res--;
		while (pos < del.size() && del[pos].first == now){
			if (del[pos].second < n - now){
				add[del[pos].second] = 1;
				res++;
			}
			pos++;
		}
		if(T - 1 >= n - now)
		ans = max(ans, res);
	}
	cout << ans;
	return 0;
}