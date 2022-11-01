// Coding on my mac
// My mac doesn't have bits/stdc++.h
// http://codeforces.com/blog/entry/47152 looks helpful
// If only I could be bothered setting things up

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

multiset<ll> all;
set<pair<int, int> > hv;
ll arr[100005];
int p[100005];
int n;

void add(int lo, int hi)
{
	if (lo > hi) return;
	all.insert(arr[hi]-arr[lo-1]);
	hv.emplace(lo, hi);
}

void rem(int lo, int hi)
{
	all.erase(all.find(arr[hi]-arr[lo-1]));
	hv.erase(make_pair(lo, hi));
}

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	all.insert(0);
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> arr[i];
	for (int i = 1;i <= n;i++) arr[i] += arr[i-1];
	for (int i = 0;i < n;i++) cin >> p[i];
	add(1, n);
	for (int i = 0;i < n;i++)
	{
		auto what = *--hv.upper_bound(make_pair(p[i], 2147483647));
		rem(what.first, what.second);
		add(what.first, p[i]-1);
		add(p[i]+1, what.second);
		cout << *all.rbegin() << '\n';
	}
	return 0;
}