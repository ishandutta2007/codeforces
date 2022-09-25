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


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 20;
const int inf = 1000000007;
const int mod = 1000000007;

int gcd(int a, int b) {
    while (b) b ^= a ^= b ^= a %= b;
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

long long a, b;
int k, x = 1, d1[3000001], d2[maxn], used[maxn], ans1 = inf;
vector<int> e1[maxn], e2[maxn];

int norm(int y) {
    if (y < 0)
        y += x;
    return y;
}

void dijkstra(int v, int * d, vector<int> * e) {
    int V = v;
    set<pair<int, int> > s;
    for (int i = 0; i < 2 * x; i++)
        d[i] = inf;
    d[v] = 0;
    for (int i = 0; i < 2 * x; i++)
        s.insert(make_pair(d[i], i));
    
    memset(used, 0, sizeof(used));
    int o = 1;
    while (!s.empty()) {
        v = s.begin()->second;
        s.erase(s.begin());
        for (int i = 0; i < e[v].size(); i++) {
            if (used[e[v][i]] != o) {
                used[e[v][i]] = o;
                if (d[e[v][i]] > d[v] + 1) {
                    s.erase(make_pair(d[e[v][i]], e[v][i]));
                    d[e[v][i]] = d[v] + 1;
                    s.insert(make_pair(d[e[v][i]], e[v][i]));
                }
                if (e[v][i] == V)
                    ans1 = min(ans1, d[v] + 1);
            }
        }
    }
}

ll abs1(ll x) {
    if (x < 0)
        return -x;
    return x;
}

void naive_sol() {
    int * d = d1;
    for (int i = 0; i <= a - b; i++)
        d[i] = inf;
    d[a - b] = 0;
    for (int i = a - b; i >= 0; i--) {
        ll cur = i + b;
        if (cur - 1 >= 0)
            d[i - 1] = min(d[i - 1], d[i] + 1);
        for (int j = 2; j <= k; j++)
            d[i - cur % j] = min(d[i - cur % j], d[i] + 1);
    }
    cout << d[0];
    exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    cin >> a >> b >> k;
    for (int i = 1; i <= k; i++)
        x = lcm(x, i);
    
    if (a - b <= 3e6)
        naive_sol();

    /*for (int i = 0; i < x; i++) {
        e1[i].push_back(norm(i - 1));
        e2[norm(i - 1)].push_back(i);
        e1[i + x].push_back(norm(i + x - 1));
        e2[norm(i + x - 1)].push_back(i + x);
        for (int j = 2; j <= k; j++) {
            if (i % j != 0) {
                e1[i].push_back(norm(i - i % j));
                e1[i + x].push_back(norm(i + x - i % j));
                e2[norm(i - i % j)].push_back(i);
                e2[norm(i + x - i % j)].push_back(i + x);
            }
        }
    }
    e1[0].push_back(2 * x - 1);
    e2[2 * x - 1].push_back(0);

    dijkstra(a % x + x, d1, e1);
    dijkstra(b % x, d2, e2);

    long long ans = 1e18;
    for (int i = 0; i < x; i++) {
        long long res = 0;
        res = (a - b) / x * abs1(d1[i + x] - d1[i]) + min(d2[i], d2[i + x]);
        ans = min(ans, res);
    }*/

    for (int i = 0; i < x; i++) {
        e2[norm(i - 1)].push_back(i);
        for (int j = 2; j <= k; j++)
            if (i % j != 0)
                e2[norm(i - i % j)].push_back(i);
    }
    dijkstra(b % x, d2, e2);


    long long cur = a, o = 0, oo = 0;
    memset(used, 0, sizeof(used));
    while (!used[cur % x]) {
        o++; oo++;
        used[cur % x] = o;
        long long newcur = cur - 1;
        for (int i = 2; i <= k; i++)
            newcur = min(newcur, cur - cur % i);
        cur = newcur;
    }
    o -= used[cur % x] - 1;

    long long ans = oo + (cur - b) / x * o + d2[cur % x];
    cout << ans;

    return 0;
}