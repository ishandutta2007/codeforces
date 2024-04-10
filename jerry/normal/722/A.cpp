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

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	int n; string buf;
	cin >> n >> buf;
	if (buf[3] < '0' || buf[3] > '5') buf[3] = '1';
	if (n == 12)
	{
		if (buf[0] < '0' || buf[0] > '1') buf[0] = '0';
		if (buf[0] == '0' && buf[1] == '0') buf[0] = '1';
		if (buf[0] == '1' && buf[1] > '2') buf[1] = '0';
	} else
	{
		if (buf[0] < '0' || buf[0] > '2')
			buf[0] = '1';
		if (buf[0] == '2' && buf[1] > '3') buf[1] = '0';
	}
	cout << buf << endl;
	return 0;
}