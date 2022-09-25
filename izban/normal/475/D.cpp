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

void Unique(vector<pair<int, int> > &v) {
    vector<pair<int, int> > nv;
    for (int i = 0; i < (int)v.size(); i++) {
        if (!nv.empty() && nv.back().first == v[i].first) continue;
        nv.push_back(v[i]);
    }
    v = nv;
}

int gcd(int a, int b) {
    while (b) b ^= a ^= b ^= a %= b;
    return a;
}

void print(vector<pair<int, int> > v) {
    for (int i = 0; i < (int)v.size(); i++) cout << v[i].first << " " << v[i].second << " " << " \n"[i + 1 == (int)v.size()];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        vector<pair<int, int> > v;
        map<int, ll> ans;
        for (int i = n - 1; i >= 0; i--) {
            v.push_back(make_pair(0, 0));
            for (int j = (int)v.size() - 1; j > 0; j--) v[j] = v[j - 1];
            v[0] = make_pair(a[i], i);
            for (int j = 0; j < (int)v.size(); j++) v[j].first = gcd(v[j].first, a[i]);
            Unique(v);
            for (int j = 0; j < (int)v.size(); j++) {
                int l = v[j].second;
                int r = j + 1 == (int)v.size() ? n - 1 : v[j + 1].second - 1;
                ans[v[j].first] += r - l + 1;
            }
        }
        
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            cout << ans[x] << "\n";
        }
    }
    
    return 0;
}