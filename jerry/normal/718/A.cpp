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

string buf;
int i;

void up(int at)
{
	at--;
	if (at < 0)
	{
		buf = '1' + buf;
		i++;
		return;
	}
	if (buf[at] == '.') at--;
	buf[at]++;
	if (buf[at] == '9'+1)
	{
		buf[at] = '0';
		up(at);
	}
}

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k >> buf;
	while (buf[i] != '.') i++; i++;
	while (i < buf.length() && buf[i] <= '4') i++;
	if (i == buf.length())
	{
		cout << buf << endl;
		return 0;
	}
	for (;buf[i] != '.' && k;i--) if (buf[i] >= '5')
	{
		buf.resize(i); up(i);
		k--;
	}
	if (buf.back() == '.') buf.pop_back();
	cout << buf << endl;
	return 0;
}