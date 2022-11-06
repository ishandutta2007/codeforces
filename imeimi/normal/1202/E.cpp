#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>

using namespace std;
typedef long long llong;

struct node {
    int nxt[26];
    int cnt, fail;
    node() : cnt(0), fail(0) {
        for (int i = 0; i < 26; ++i) nxt[i] = 0;
    }
} ns[200001];
int tp;

char in[200001];
vector<string> ss;

void new_node(int x, const char * s) {
    if (*s == 0) {
        ++ns[x].cnt;
        return;
    }
    int &nxt = ns[x].nxt[*s - 'a'];
    if (nxt == 0) nxt = ++tp;
    new_node(nxt, s + 1);
}

void make_trie() {
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < 26; ++i) {
            int v = ns[x].nxt[i];
            if (v == 0) continue;
            q.push(v);
            int pf = ns[x].fail;
            while (pf > 0 && ns[pf].nxt[i] == 0)
                pf = ns[pf].fail;
            if (x > 0) pf = ns[pf].nxt[i];
            ns[v].fail = pf;
            ns[v].cnt += ns[pf].cnt;
        }
    }
}

void solve(int n, int V[]) {
    tp = 0;
    for (string &s : ss) {
        new_node(0, s.c_str());
    }
    make_trie();
    for (int i = 0, x = 0; i < n; ++i) {
        int s = in[i] - 'a';
        while (x > 0 && ns[x].nxt[s] == 0)
            x = ns[x].fail;
        x = ns[x].nxt[s];
        V[i] = ns[x].cnt;
    }
}

int L[200001], R[200001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> in;
    int n;
    cin >> n;
    while (n--) {
        ss.emplace_back();
        cin >> ss.back();
    }
    n = strlen(in);
    solve(n, L);
    reverse(in, in + n);
    for (string &s : ss) reverse(s.begin(), s.end());
    for (int i = 0; i <= tp; ++i) ns[i] = node();
    solve(n, R);
    llong ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans += (llong)L[i] * R[n - 2 - i];
    }
    printf("%lld\n", ans);
    return 0;
}