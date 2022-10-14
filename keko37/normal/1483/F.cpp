#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1000005;
const int LOG = 20;

int n, cnt = 1, br, sol;
int sus[MAXN][26], nxt[MAXN][26], par[MAXN][LOG];
int ok[MAXN], len[MAXN], suf[MAXN], dub[MAXN], lo[MAXN], hi[MAXN], val[MAXN];
bool leaf[MAXN];
string s[MAXN];
vector <int> v, ch[MAXN], r, st;
queue <int> q;

void ubaci (int ind) {
    int curr = 1;
    for (int i = 0; i < len[ind]; i++) {
        int c = s[ind][i] - 'a';
        if (sus[curr][c] == 0) sus[curr][c] = ++cnt;
        curr = sus[curr][c];
    }
    ok[curr] = ind;
}

void aho_corasick () {
    suf[1] = 1;
    for (int i = 0; i < 26; i++) nxt[1][i] = 1;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        v.push_back(x);
        if (ok[suf[x]]) par[x][0] = suf[x]; else par[x][0] = par[suf[x]][0];
        dub[x] = 1 + dub[par[x][0]];
        if (x != par[x][0]) ch[par[x][0]].push_back(x);
        for (int i = 0; i < 26; i++) {
            if (sus[x][i] != 0) {
                suf[sus[x][i]] = nxt[suf[x]][i];
                nxt[x][i] = sus[x][i];
                q.push(sus[x][i]);
            } else {
                nxt[x][i] = nxt[suf[x]][i];
            }
        }
    }
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= cnt; j++) {
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }
}

void dfs (int x) {
    lo[x] = hi[x] = br++;
    for (auto y : ch[x]) {
        dfs(y);
        hi[x] = hi[y];
    }
}

int kth (int x, int k) {
    int pot = 0;
    while (k > 0) {
        if (k & 1) x = par[x][pot];
        k /= 2;
        pot++;
    }
    return x;
}

int lca (int a, int b) {
    if (dub[a] < dub[b]) swap(a, b);
    a = kth(a, dub[a] - dub[b]);
    if (a == b) return a;
    for (int i = LOG - 1; i >= 0; i--) {
        if (par[a][i] != par[b][i]) {
            a = par[a][i];
            b = par[b][i];
        }
    }
    return par[a][0];
}

bool cmp (int a, int b) {
    return lo[a] < lo[b];
}

void solve (int ind) {
    r.clear();
    r.push_back(1);
    int curr = 1;
    for (int i = 0; i < len[ind]; i++) {
        int c = s[ind][i] - 'a';
        curr = nxt[curr][c];
        if (ok[curr] != 0 && ok[curr] != ind) val[i] = curr; else val[i] = par[curr][0];
        r.push_back(val[i]);
    }
    sort(r.begin(), r.end(), cmp);
    r.erase(unique(r.begin(), r.end()), r.end());
    for (int i = r.size() - 1; i >= 1; i--) {
        r.push_back(lca(r[i], r[i - 1]));
    }
    sort(r.begin(), r.end(), cmp);
    r.erase(unique(r.begin(), r.end()), r.end());
    //cout << ind << "  ";
    //for (auto x : r) cout << x << " "; cout << endl;
    st.clear();
    st.push_back(1);
    for (int i = 1; i < r.size(); i++) {
        int x = r[i];
        while (lo[x] > hi[st.back()]) st.pop_back();
        leaf[st.back()] = 0;
        leaf[x] = 1;
        st.push_back(x);
    }
    st.clear();
    for (int i = 0; i < len[ind]; i++) {
        if (val[i] == 1) continue;
        while (!st.empty() && i - len[ok[val[i]]] <= st.back() - len[ok[val[st.back()]]]) {
            leaf[val[st.back()]] = 0;
            st.pop_back();
        }
        st.push_back(i);
    }
    for (auto x : r) sol += leaf[x];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ok[1] = -1;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        len[i] = s[i].size();
        ubaci(i);
    }
    aho_corasick();
    dfs(1);
    for (auto x : v) {
        if (ok[x] > 0) solve(ok[x]);
    }
    cout << sol;
    return 0;
}