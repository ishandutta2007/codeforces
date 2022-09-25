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


int n;
int a[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < a[i]; j++) {
                if (i > 0) ans += "LR";
                else ans += "RL";            
                ans += "P";
            }
            if (i < n - 1) ans += "R";
        }
        cout << ans << endl;
    }

	return 0;
}