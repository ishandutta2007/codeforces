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

int n, m;
pair<int, int> a[maxn];

bool reading() {
    if (!(cin >> n >> m)) return 0;
    for (int i = 0; i < m; i++) cin >> a[i].first >> a[i].second;
    return 1;
}

int solve() {
    vector<int> vx;
    for (int i = 0; i < m; i++) {
        vx.push_back(a[i].first);
        if (a[i].first > 1) vx.push_back(a[i].first - 1);
    }
    vx.push_back(1);
    vx.push_back(n);
    sort(vx.begin(), vx.end());
    vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
    sort(a, a + m);
    
    vector<pair<int, int> > cur;
    cur.push_back(make_pair(1, 1));
    int j = 0;
    for (int i = 0; i < vx.size(); i++) {
        vector<int> v;
        v.push_back(0);
        while (j < m && a[j].first == vx[i]) {
            v.push_back(a[j++].second);
        }
        v.push_back(n + 1); 
        vector<pair<int, int> > nv;
        
        int ci = 0;
        for (int cj = 1; cj < v.size(); cj++) {
            while (ci < cur.size() && cur[ci].second <= v[cj - 1]) ci++;
            if (ci < cur.size() && max(cur[ci].first, v[cj - 1] + 1) < v[cj]) nv.push_back(make_pair(max(cur[ci].first, v[cj - 1] + 1), v[cj] - 1));
        }
        cur = nv;
    }
    if (cur.empty() || cur.back().second < n) return -1;
    return 2 * n - 2;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    while (reading()) cout << solve() << endl;

    return 0;
}