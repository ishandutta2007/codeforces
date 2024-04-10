#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:50000000")
typedef long long ll;

using namespace std;

const int maxn = 1 << 18;
const int inf = 1e9;

int s[maxn];
//const int k = 333;

int add(int l, int r) {
    s[l]++;
    s[r + 1]--;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	//ios_base::sync_with_stdio(0);
    int n;
    while (scanf("%d", &n) == 1) {
    //n = 2e5;
    //{
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) s[i] = 0;

        int k = sqrt(n) + 1;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < k; j++) {
                int pi = (i - 1) / j;
                if (a[i] < a[pi]) {
                    add(j, j);
                }
            }
            int last = k - 1;
            for (int pi = (i - 1) / (k - 1); pi >= 0; pi--) {
                int l, r;
                if (pi == 0) {
                    l = i - 1 + 1;
                    r = n - 1;
                } else {
                    // min l: (i - 1) / l <= pi
                    // (i - 1) <= pi * l
                    // l >= (i - 1) / pi
                    // max r: (i - 1) / r >= pi
                    // (i - 1) >= pi * r
                    // r <= (i - 1) / pi

                    l = last + 1;
                    r = (i - 1) / pi;
                    while ((i - 1) / (r + 1) >= pi) r++;
                }
                l = max(l, last + 1);
                if (a[i] < a[pi]) add(l, r);
                last = r;
            }
        }

        for (int i = 1; i < n; i++) {
            s[i] += s[i - 1];
            printf("%d%c", s[i], " \n"[i == n - 1]);
        }
    }


	return 0;
}