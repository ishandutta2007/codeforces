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

const int maxn = 1024;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m, k, p;
int a[maxn][maxn];
ll row[maxn], col[maxn];
ll sumrow[maxn * maxn], sumcol[maxn * maxn];

void print(priority_queue<ll> q) {
    while (!q.empty()) {
        cerr << q.top() << " ";
        q.pop();
    }
    cerr << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    while (cin >> n >> m >> k >> p) {
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
        
        for (int i = 0; i < n; i++) row[i] = 0;
        for (int j = 0; j < m; j++) col[j] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i] += a[i][j];
                col[j] += a[i][j];
            }
        }
        priority_queue<ll> q;
        sumrow[0] = sumcol[0] = 0;
        
        for (int i = 0; i < n; i++) {
            q.push(row[i]);
        }
        for (int i = 1; i <= k; i++) {
            ll x = q.top();
            q.pop();
            sumrow[i] = sumrow[i - 1] + x;
            q.push(x - p * m);
        }
        
        while (!q.empty()) q.pop();
        for (int i = 0; i < m; i++) {
            q.push(col[i]);
        }
        for (int i = 1; i <= k; i++) {
            ll x = q.top();
            q.pop();
            sumcol[i] = sumcol[i - 1] + x;
            q.push(x - p * n);
        }
        
        ll ans = -1e18;
        for (int i = 0; i <= k; i++) {
            ans = max(ans, sumrow[i] + sumcol[k - i] - 1LL * p * i * (k - i));
        }
        cout << ans << endl;
    }
    
    return 0;
}