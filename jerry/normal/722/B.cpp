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

int val[256];
char buf[512];

int main()
{
	gets(buf); int n = atoi(buf), m = 0;
	gets(buf);
	for (char *ptr = strtok(buf, " ");ptr != NULL;ptr = strtok(NULL, " "))
		val[m++] = atoi(ptr);
	for (int i = 0;i < n;i++)
	{
		gets(buf);
		int hv = 0;
		for (int j = 0;buf[j];j++) if (buf[j] == 'a' || buf[j] == 'e' || buf[j] == 'i' || buf[j] == 'o' || buf[j] == 'u' || buf[j] == 'y') hv++;
		if (hv != val[i])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}