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

const int maxn = 500200;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

struct node {
    int next[26], len;
    vector<int> v;
};

string s;
int n;
int sz;
node t[maxn];
map<pair<int, int>, int> ans;

void add(int x) {
    int cur = 0;
    for (int i = x; i < n && i - x < 4; i++) {
        if (t[cur].next[s[i] - 'a'] == -1) {
            t[cur].next[s[i] - 'a'] = sz++;
        }
        cur = t[cur].next[s[i] - 'a'];
        t[cur].v.push_back(x);
        t[cur].len = i - x;
    }
}

int get(const string &s) {
    int cur = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        if (t[cur].next[s[i] - 'a'] == -1) return 0;
        cur = t[cur].next[s[i] - 'a'];
    }
    return cur;
}

int f(int a, int b, int c, int d) {
    return max(b, d) - min(a, c) + 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
    ios_base::sync_with_stdio(0);
    
    while (cin >> s) {
        for (int i = 0; i < maxn; i++) {
            memset(t[i].next, -1, sizeof(t[i].next));
            t[i].v.clear();
        }
        sz = 1;
        ans.clear();
        
        n = s.length();
        for (int i = 0; i < n; i++) add(i);
        
        int q;
        cin >> q;
        for (int it = 0; it < q; it++) {
            string a, b;
            cin >> a >> b;
            int x = get(a), y = get(b);
            if (t[x].v.size() < t[y].v.size()) swap(x, y);
            
            if (ans.count(make_pair(x, y))) {
                cout << ans[make_pair(x, y)] << "\n";
                continue;
            }
            
            if (t[y].v.size() == 0) {
                ans[make_pair(x, y)] = -1;
                cout << -1 << "\n";
                continue;
            }
            int res = n + 1;
            for (int i = 0; i < (int)t[y].v.size(); i++) {
                int j = lower_bound(t[x].v.begin(), t[x].v.end(), t[y].v[i]) - t[x].v.begin();
                for (int k = max(0, j - 5); k <= min((int)t[x].v.size() - 1, j + 5); k++) {
                    res = min(res, f(t[y].v[i], t[y].v[i] + t[y].len, t[x].v[k], t[x].v[k] + t[x].len));
                }
            }
            ans[make_pair(x, y)] = res;
            cout << res << "\n";
            continue;
        }
    }
    
    return 0;
}