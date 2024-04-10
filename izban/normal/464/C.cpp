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

const int maxn = 100100;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};


string s, s0[maxn];
int n, k;
vector<int> nxt[maxn];
int len[maxn], sum[maxn];
int cur[10];

int bin(int n, int k) {
    if (k == 0) return 1;
    int res = bin(n, k / 2);
    res = 1LL * res * res % mod;
    if (k % 2) res = 1LL * res * n % mod;
    return res;
}

int getLen(int x) {
    if (len[x] != -1) {
        return len[x];
    }
    len[x] = 0;
    for (int i = 0; i < (int)nxt[x].size(); i++) {
        len[x] = (len[x] + getLen(nxt[x][i])) % (mod - 1);
    }
    return len[x];
}

int getSum(int x) {
    if (sum[x] != -1) {
        return sum[x];
    }
    sum[x] = 0;
    int clen = 0;
    for (int i = (int)nxt[x].size() - 1; i >= 0; i--) {
        sum[x] = (sum[x] + 1LL * getSum(nxt[x][i]) * bin(10, clen)) % mod;
        clen = (clen + getLen(nxt[x][i])) % (mod - 1);
    }
    return sum[x];    
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    while (cin >> s >> k) {
        for (int i = 0; i < k; i++) cin >> s0[i];
        n = s.length();
        
        for (int i = 0; i < maxn; i++) {
            nxt[i].clear();
            len[i] = sum[i] = -1;
        }
        for (int i = 0; i < 10; i++) {
            cur[i] = i;
            len[i] = 1;
            sum[i] = i;
        }
        
        for (int i = 0; i < k; i++) {
            int x = s0[i][0] - '0';
            int y = cur[x];
            len[y] = sum[y] = -1;
            cur[x] = 10 + i;
            len[cur[x]] = 1;
            sum[cur[x]] = x;
            for (int j = 3; j < (int)s0[i].size(); j++) {
                nxt[y].push_back(cur[s0[i][j] - '0']);
            }
        }
        
        int ans = 0;
        int clen = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans = (ans + 1LL * getSum(s[i] - '0') * bin(10, clen)) % (mod);
            clen = (clen + getLen(s[i] - '0')) % (mod - 1);
        }
        cout << ans << endl;
    }
    
    return 0;
}