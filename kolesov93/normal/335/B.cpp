#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>

typedef long long ll;
using namespace std;

const int N = 55555;
const int M = 3333;

int cnt[N];

int f[M][M];
char s[N], w[N];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    gets(s);
    int n = strlen(s);

    for (int i = 0; i < n; ++i) {
        cnt[ s[i] ]++;
        w[i] = s[n - i - 1];
    }

    for (char c = 'a'; c <= 'z'; ++c) {
        if (cnt[c] >= 100) {
            for (int i = 0; i < 100; ++i) putchar(c);
            puts("");
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) f[i][i] = 1;
    for (int i = 0; i + 1 < n; ++i)
        if (s[i] == s[i + 1]) {
            f[i][i + 1] = 2;
        } else {
            f[i][i + 1] = max(f[i][i], f[i + 1][i + 1]);
        }
    for (int len = 3; len <= n; ++len)
        for (int i = 0; i + len <= n; ++i) {
            int j = i + len - 1; 
            
            f[i][j] = max(f[i][j - 1], f[i + 1][j]);
            if (s[i] == s[j]) {
                f[i][j] = max(f[i][j], f[i + 1][j - 1] + 2);
            }
        }

    vector<char> ss;
    bool odd = (f[0][n - 1] & 1);
    int x = 0, y = n - 1;
    while (x <= y) {
        if (s[x] == s[y] && (x == y || f[x][y] == f[x + 1][y - 1] + 2)) {
            ss.push_back(s[x]);
            ++x;
            --y;
        } else {
            if (f[x + 1][y] == f[x][y]) ++x;
            else --y;
        }
    }

    if (f[0][n - 1] > 100) {
        odd = false;
        while (ss.size() > 50) ss.pop_back(); 
    }

    for (int i = 0; i < ss.size(); ++i) putchar(ss[i]);
    if (odd) ss.pop_back();
    reverse(ss.begin(), ss.end());
    for (int i = 0; i < ss.size(); ++i) putchar(ss[i]);
    puts("");

    return 0;
}