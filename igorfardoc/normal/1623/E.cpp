#include<bits/stdc++.h>
#define next next1
#define prev prev1
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, k;
string a;
vvi g;
string s;
vi order;
vi where;
int noworder = 0;
string next;
string res = "";
vector<bool> used;
vi depth;
vi prev;

void dfs1(int v) {
    if(v == -1) return;
    dfs1(g[v][0]);
    order.push_back(v);
    where[v] = noworder++;
    dfs1(g[v][1]);
}

void dfs(int v, bool baned=false, int lastused=1) {
    if(v == -1) return;
    //cout << v << ' ' << next[where[v]] << endl;
    if(baned) {
        dfs(g[v][0], true);
        res += a[v];
        dfs(g[v][1], true);
        return;
    }
    dfs(g[v][0], false, lastused + 1);
    if(used[v]) {
        res += a[v];
        res += a[v];
    } else {
        if(next[where[v]] > a[v]) {
            if(lastused <= k) {
                int v1 = v;
                while(v1 != -1 && !used[v1]) {
                    used[v1] = true;
                    v1 = prev[v1];
                    --k;
                }
                res += a[v];
                res += a[v];
            } else {
                res += a[v];
            }
        } else {
            res += a[v];
            dfs(g[v][1], true);
            return;
        }
    }
    if(used[v]) {
        lastused = 0;
    }
    dfs(g[v][1], false, lastused + 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> k >> a;
    g.resize(n);
    prev.assign(n, -1);
    s = "";
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        g[i] = {l, r};
        if(l != -1) {
            prev[l] = i;
        }
        if(r != -1) {
            prev[r] = i;
        }
        s += ' ';
        next += ' ';
    }
    where.resize(n);
    dfs1(0);
    for(int i = 0; i < n; i++) {
        s[where[i]] = a[i];
    }
    next[n - 1] = (char)('a' - 1);
    for(int i = n - 2; i >= 0; i--) {
        if(s[i] != s[i + 1]) {
            next[i] = s[i + 1];
            continue;
        }
        next[i] = next[i + 1];
    }
    used.assign(n, false);
    dfs(0);
    cout << res;
}