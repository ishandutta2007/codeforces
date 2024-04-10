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

const int maxn = 1 << 7;
const int inf = 1000000007;
const int mod = 1000000007;

bool ok(int n, char c1, char c2, int need) {
    if (n == 1 && c1 != c2) return 0;
    if (n == 2 && c1 == 'A' && c2 == 'C') return need == 1;
    return (n - (c1 != 'A') - (c2 != 'C')) / 2 >= need;
}

int cnt[maxn];
char frst[maxn], lst[maxn];

int k, x, n, m;

string construct(int n, char c1, char c2, int k) {
    string s = "";
    s += c1;
    int cur = c1 == 'A' ? 2 : 0;
    for (int i = 1; i < n - 1; i++) {
        if (k > 0) s += (char)(cur + 'A');
        else s += 'B';
        cur = (cur + 2) % 4;
        k -= cur == 0;
    }
    if (n > 1) s += c2;
    return s;
}

pair<string, string> solve() {
        for (char c11 = 'A'; c11 <= 'C'; c11++) {
            for (char c12 = 'A'; c12 <= 'C'; c12++) {
                for (char c21 = 'A'; c21 <= 'C'; c21++) {
                    for (char c22 = 'A'; c22 <= 'C'; c22++) {
                        for (int k1 = 0; k1 <= n / 2; k1++) {
                            for (int k2 = 0; k2 <= m / 2; k2++) {
                                if (ok(n, c11, c12, k1) && ok(m, c21, c22, k2)) {
                                    cnt[1] = k1;
                                    cnt[2] = k2;
                                    frst[1] = c11;
                                    lst[1] = c12;
                                    frst[2] = c21;
                                    lst[2] = c22;
                                    for (int i = 3; i <= k; i++) {
                                        cnt[i] = min(cnt[i - 1] + cnt[i - 2] + (lst[i - 2] == 'A' && frst[i - 1] == 'C'), x + 1);
                                        frst[i] = frst[i - 2];
                                        lst[i] = lst[i - 1];
                                    }
                                    if (cnt[k] == x) {
                                        string s1 = construct(n, c11, c12, k1);
                                        string s2 = construct(m, c21, c22, k2);
                                        return make_pair(s1, s2);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return make_pair("Happy new year!", "");
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
    while (cin >> k >> x >> n >> m) {
        pair<string, string> o = solve();
        cout << o.first << endl;
        if (o.first != "Happy new year!") cout << o.second << endl;
    }

	return 0;
}