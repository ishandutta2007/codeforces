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
#include <cstring>


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 200;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int g(char c) {
    if (c == 'R') return 5;
    if (c == 'G') return 6;
    if (c == 'B') return 7;
    if (c == 'Y') return 8;
    if (c == 'W') return 9;
    return -1;
}

int n;
string a[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> a[i];
        
        int ans = 100;
        for (int mask = 0; mask < 1 << 10; mask++) {
            if (mask == (1 << 3) + (1 << 6)) {
                mask = mask - 1;
                mask = mask + 1;
            }
            vector<string> b(n);
            for (int i = 0; i < n; i++) b[i] = "zz";
            for (int i = 0; i < n; i++) {
                if (mask & (1 << (a[i][1] - '1'))) {
                    b[i][1] = a[i][1];
                }
                if (mask & (1 << (g(a[i][0])))) {
                    b[i][0] = a[i][0];
                }
            }
            while (1) {
                bool oo = false;
                for (int i = 0; i < n; i++) {
                    for (int o = 0; o < 2 && !oo; o++) {
                        if (b[i][o ^ 0] == 'z') {
                            bool t = b[i][o ^ 1] != 'z';
                            for (int j = 0; j < n; j++) {
                                //t &= a[j][o ^ 1] != a[i][o ^ 1] || a[j][o ^ 0] == a[i][o ^ 0] || b[j][o ^ 0] != 'z';
                                t &= !(a[j][o ^ 1] == a[i][o ^ 1] && a[j][o ^ 0] != a[i][o ^ 0] && b[j][o ^ 0] == 'z');
                            }
                            bool t2 = 1;
                            for (int j = 0; j < n; j++) {
                                t2 &= !(a[j][o ^ 0] != a[i][o ^ 0] && b[j][o ^ 0] == 'z');
                            }                            
                            if (t || t2) {
                                b[i][o ^ 0] = a[i][o ^ 0];
                                oo = true;
                                break;
                            }
                        }
                    }
                }
                if (!oo) break;
            }
            bool ok = 1;
            for (int i = 0; i < n; i++) ok &= b[i][0] != 'z' && b[i][1] != 'z';
            if (!ok) continue;
            int res = 0;
            for (int i = 0; i < 10; i++) res += !!(mask & (1 << i));
            if (ans > res) {
                ans = res;
            }
        }
        cout << ans << endl;
    }

	return 0;
}