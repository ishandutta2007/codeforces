#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int n, val, cnt, mx = 1;
int p[MAXN], dub[MAXN], ch[MAXN], leaf[MAXN];
int par[MAXN], siz[MAXN], col[MAXN];
char sol[MAXN];
vector <int> v[MAXN], w[MAXN], sus[MAXN], st;
bitset <MAXN> bt[1005];

int nadi (int x) {
    if (x == par[x]) return x;
    return nadi(par[x]);
}

void spoji (int a, int b) {
    a = nadi(a); b = nadi(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    par[b] = a;
    siz[a] += siz[b];
}

void build_weights () {
    for (int i = 0; i <= n; i++) {
        if (v[i].empty()) continue;
        for (int j = 1; j < v[i].size(); j++) {
            spoji(v[i][j - 1], v[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i == nadi(i)) w[siz[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        while (w[i].size() >= 3) {
            int a = w[i].back(); w[i].pop_back();
            int b = w[i].back(); w[i].pop_back();
            spoji(a, b);
            if (siz[a] > siz[b]) {
                w[siz[a]].push_back(a);
            } else {
                w[siz[b]].push_back(b);
            }
        }
    }
}

void rip () {
    int sum = 0;
    for (int i = mx - 1; i >= 0; i--) {
        leaf[i] = 0;
        for (auto x : v[i]) {
            if (ch[x] == 0) leaf[i]++;
            sol[x] = 'a';
        }
        if (st.empty() || v[st.back()].size() < v[i].size()) st.push_back(i);
        sum += v[i].size();
        if (sum >= val) break;
    }
    if (sum > val) {
        for (int i = 0; i < st.size(); i++) {
            if (sum - v[st[i]].size() < val) {
                if (i - 1 >= 0) {
                    for (auto x : v[st[i - 1]]) sol[x] = 'b';
                    sum -= v[st[i - 1]].size();
                }
                for (auto x : v[st[i]]) {
                    if (ch[x] == 0) {
                        sol[x] = 'b';
                        sum--;
                    }
                    if (sum == val) break;
                }
                break;
            }
        }
    }
    cout << mx + 1 << '\n';
    for (int i = 1; i <= n; i++) cout << sol[i];
}

void knapsack () {
    bt[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        if (w[i].empty()) continue;
        for (int j = 0; j < w[i].size(); j++) {
            bt[cnt + 1] = bt[cnt] | (bt[cnt] << i);
            cnt++;
        }
    }
    int org_val = val;
    if (bt[cnt][val] == 1) {
        for (int i = n; i >= 1; i--) {
            if (w[i].empty()) continue;
            for (int j = 0; j < w[i].size(); j++) {
                if (bt[cnt][val] == 1 && bt[cnt - 1][val] == 0) {
                    col[w[i][j]] = 1;
                    val -= i;
                }
                cnt--;
            }
        }
        cout << mx << '\n';
        for (int i = 1; i <= n; i++) {
            if (col[nadi(i)] == 1) sol[i] = 'a';
            cout << sol[i];
        }
    } else {
        rip();
    }
}

void dfs (int x) {
    if (x == 1) dub[x] = 0; else dub[x] = 1 + dub[p[x]];
    mx = max(mx, dub[x] + 1);
    for (auto s : sus[x]) dfs(s);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> val;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        ch[p[i]] = 1;
        sus[p[i]].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        par[i] = i; siz[i] = 1; sol[i] = 'b';
        v[dub[i]].push_back(i);
    }
    build_weights();
    knapsack();
    return 0;
}