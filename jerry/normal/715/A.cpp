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

//////////////////////////////////////////////////

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	int n; scanf("%d", &n);
	printf("2\n");
	for (ll i = 2;i <= n;i++)
		printf("%lld\n", i*(i+1)*(i+1)-i+1);
	return 0;
}