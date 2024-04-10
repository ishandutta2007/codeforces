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

const int maxn = 550200;

struct node {
    int l, r, p, link;
    int next[37];
    
    node() {
        l = r = p = link = -1;
        memset(next, -1, sizeof(next));
    }
    
    node(int l, int r, int p) : l(l), r(r), p(p), link(-1) {
        memset(next, -1, sizeof(next));
    }
    
    int len() {
        return r - l;
    }
};

string si[11];
vector<unsigned char> s;
int n, k, li[11], ri[11];
int sz;
node t[2 * maxn];
pair<int, int> cur;

pair<int, int> go(pair<int, int> cur, int l, int r) {
    while (l < r) {
        if (cur.second == t[cur.first].len()) {
            cur = make_pair(t[cur.first].next[s[l++] - 'a'], 1);
            if (cur.first == -1) return cur;
            continue;
        }
        if (s[l] != s[t[cur.first].l + cur.second]) return make_pair(-1, -1);
        int d = min(r - l, t[cur.first].len() - cur.second);
        l += d;
        cur.second += d;
    }
    return cur;
}

int split(pair<int, int> cur) {
    if (cur.second == t[cur.first].len()) return cur.first;
    int res = sz++;
    t[res] = node(t[cur.first].l, t[cur.first].l + cur.second, t[cur.first].p);
    t[t[res].p].next[s[t[cur.first].l] - 'a'] = res;
    t[cur.first].p = res;
    t[res].next[s[t[res].r] - 'a'] = cur.first;
    t[cur.first].l += cur.second;
    return res;
}

int getLink(int v) {
    if (t[v].link != -1) return t[v].link;
    int to = getLink(t[v].p);
    return t[v].link = split(go(make_pair(to, t[to].len()), t[v].l + !(t[v].p), t[v].r));
}

void add(int id) {
    while (1) {
        pair<int, int> nw = go(cur, id, id + 1);
        if (nw.first != -1) {
            cur = go(cur, id, id + 1);
            //cur = nw;
            break;
        }
        int mid = split(cur);
        int leaf = sz++;
        t[leaf] = node(id, n, mid);
        t[mid].next[s[id] - 'a'] = leaf;
        
        cur.first = getLink(mid);
        cur.second = t[cur.first].len();
        if (!mid) break;
    }
}

int pos[11];
ll ans;
int cnt[2 * maxn][11];

void dfs(int v) {
    for (int i = 0; i <= k; i++) {
        if (t[v].l <= pos[i] && t[v].r > pos[i]) {
            if (i == 0) {
                bool ok = 1;
                for (int j = 1; j <= k; j++) ok &= li[j] == 0;
                if (ok) ans += pos[0] - t[v].l;
            }
            for (int j = 0; j <= k; j++) cnt[v][j] = 0;
            cnt[v][i] = 1;
            return;
        }
    }
    for (int i = 0; i < 26 + k + 1; i++) {
        if (t[v].next[i] == -1) continue;
        dfs(t[v].next[i]);
        for (int j = 0; j <= k; j++) cnt[v][j] += cnt[t[v].next[i]][j];
    }
    bool ok = 1;
    for (int i = 0; i <= k; i++) ok &= cnt[v][i] >= li[i] && cnt[v][i] <= ri[i];
    if (ok) ans += t[v].len();
}

ll fastsolve() {
    s.clear();
    for (int i = 0; i <= k; i++) {
        //s += si[i];
        for (int j = 0; j < (int)si[i].length(); j++) s.push_back(si[i][j]);
        s.push_back((unsigned char)('z' + i + 1));
        pos[i] = s.size() - 1;
    }
    n = s.size();
    
    for (int i = 0; i < min(2 * n, maxn); i++) t[i] = node();
    sz = 1;
    t[0].link = t[0].p = 0;
    cur = make_pair(0, 0);
    for (int i = 0; i < n; i++)
        add(i);
    
    ans = 0;
    for (int i = 0; i < sz; i++) for (int j = 0; j <= k; j++) cnt[i][j] = 0;
    dfs(0);
    
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
        
    while (cin >> si[0] >> k) {
        li[0] = 1;
        ri[0] = si[0].length();
        for (int i = 1; i <= k; i++) {
            cin >> si[i] >> li[i] >> ri[i];
        }
        cout << fastsolve() << endl;
    }
    
    return 0;
}