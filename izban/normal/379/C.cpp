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
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 19;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
pair<int, int> a[maxn];
pair<int, int> b[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
        
        sort(a, a + n);
        int last = 1;
        for (int i = 0; i < n; i++) {
            b[i].first = a[i].second;
            if (last < a[i].first) last = a[i].first;
            b[i].second = last++;
        }
        sort(b, b + n);
        for (int i = 0; i < n; i++) cout << b[i].second << " \n"[i + 1 == n];
    }  

	return 0;
}