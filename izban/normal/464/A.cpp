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

const int maxn = 200200;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, p;
string s;
string cur;


bool rec(int x) {
    if (x == n) return true;
    for (char c = 'a'; c < 'a' + p; c++) {
        if (x > 0 && cur[x - 1] == c) continue;
        if (x > 1 && cur[x - 2] == c) continue;
        cur[x] = c;
        if (rec(x + 1)) return 1;
    }
    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    while (cin >> n >> p >> s) {
        /*if (p == 1) {
            assert(s == "a");
            cout << "NO" << endl;
            continue;
        }
        if (p == 2) {
            if (s == "a") {
                cout << "b" << endl;
                continue;
            }
            if (s == "b") {
                cout << "NO" << endl;
                continue;
            }
            if (s == "ab") {
                cout << "ba" << endl;
                continue;
            }
            if (s == "ba") {
                cout << "NO" << endl;
                continue;
            }
            assert(0);
            continue;
        }*/
        bool ok = false;
        for (int i = n - 1; i >= 0 && !ok; i--) {
            cur = s;
            
            for (char c = s[i] + 1; c < 'a' + p && !ok; c++) {
                cur[i] = c;
                if (i > 0 && cur[i] == cur[i - 1]) continue;
                if (i > 1 && cur[i] == cur[i - 2]) continue;
                if (rec(i + 1)) {
                    cout << cur << endl;
                    ok = true;
                }
            }
        }
        if (!ok) cout << "NO" << endl;
    }
    
    return 0;
}