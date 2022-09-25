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

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int a;
string s;
int cnt[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    while (cin >> a >> s) {
        memset(cnt, 0, sizeof(cnt));
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += s[j] - '0';
                cnt[sum]++;
            }
        }
        ll ans = 0;
        if (a == 0) {
            for (int i = 0; i < maxn; i++) ans += (1LL + (i != 0)) * cnt[0] * cnt[i];
        } else {
            for (int i = 1; i * i <= a; i++) if (a % i == 0) {
                if (i * i == a) {
                    ans += 1LL * cnt[i] * cnt[i];
                } else {
                    if (a / i < maxn) {
                        ans += 2LL * cnt[i] * cnt[a / i];
                    }
                }
            }
        }
        cout << ans << endl;
    }

	return 0;
}