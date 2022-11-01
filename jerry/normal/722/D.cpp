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

set<int> x;
int n;

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int A; cin >> A;
		x.insert(A);
	}
	while (true)
	{
		int va = *x.rbegin();
		while (va > 0)
		{
			va /= 2;
			if (x.find(va) == x.end()) break;
		}
		if (va == 0) break;
		x.erase(*--x.end());
		x.insert(va);
	}
	for (int u: x) cout << u << ' '; cout << endl;
	return 0;
}