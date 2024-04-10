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


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 20;
const int inf = 1000000007;
const int mod = 1000000007;

char buf[maxn];
string s;
int ans[maxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	scanf("%s", buf);
	s = buf;

	int l = 0, r = (int)s.length() - 1;
	for (int i = 0; i < (int)s.length(); i++) {
		if (s[i] == 'r') {
			ans[l++] = i + 1;
		}
		if (s[i] == 'l') {
			ans[r--] = i + 1;
		}
	}
	for (int i = 0; i < (int)s.length(); i++)
		printf("%d\n", ans[i]);

	return 0;
}