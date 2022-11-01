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

vector<pair<pair<int, int>, pair<int, int> > > ans;
bool open[52][52][2];

int main()
{
	cout << 42 << ' ' << 50 << '\n';
	cin.sync_with_stdio(false); cin.tie(0);
	ll n; cin >> n;
	for (int i = 0;i < 52;i++) for (int j = 0;j < 52;j++) open[i][j][0] = open[i][j][1] = true;
	for (int i = 0;i < 13;i++)
	{
		int r = 3*i+3, c = 3*i+11;
		open[r][c+3][0] = false;
		open[r+1][c+3][0] = false;
		open[r+2][c+3][0] = false;
		open[r+3][c][1] = false;
		open[r+3][c+1][1] = false;
		open[r+3][c+2][1] = false;
	}
	int from = 1;
	for (int i = 1;i <= 42;i++)
	{
		open[i][from][0] = false;
		if (i >= 7 && i%3 == 1)
		{
			open[i][from][0] = true;
			open[i][from][1] = false;
			open[i][from+1][1] = false;
			open[i][from+2][1] = false;
			open[i][from+3][0] = false;
			from += 3;
		}
	}
	for (int i = 12;i >= -1;i--)
	{
		int r = 3*i+3, c = 3*i+11;
		int va = n%20; n /= 20;
		if (va == 0) continue;
		int bone = c - 10;
		if (bone <= 0) bone = 1;
		for (int j = bone+1;j < c+3;j++) open[r+3][j][1] = false;
		open[r+3][bone][0] = true;
		if (va == 1) continue;
		open[r+2][bone][0] = true;
		if (va <= 10) open[r+2][bone+va-1][0] = false;
		else
		{
			open[r+2][bone+9][0] = false;
			int wh = bone + 20 - va;
			open[r+1][bone][0] = true;
			for (int j = bone+1;j < wh;j++) open[r+1][j][1] = false;
			open[r+1][wh][0] = false;
		}
	}
	for (int i = 1;i <= 42;i++) for (int j = 1;j <= 50;j++)
	{
		if (!open[i][j][0] && j != 50)
			ans.push_back({{i, j}, {i, j+1}});
		if (!open[i][j][1] && i != 42)
			ans.push_back({{i, j}, {i+1, j}});
	}
	cout << ans.size() << '\n';
	for (auto u: ans) cout << u.first.first << ' ' << u.first.second << ' ' << u.second.first << ' ' << u.second.second << '\n';
	return 0;
}