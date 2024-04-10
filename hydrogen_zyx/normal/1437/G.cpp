#include <bits/stdc++.h>
using namespace std;
struct AC {
    static const int maxnode = 300005;
    static const int sigma_size = 26;
    char T[maxnode];
    int ch[maxnode][sigma_size];
    multiset<int> val[maxnode];
    int fail[maxnode], last[maxnode];
    int sz;
    int mmax = 0;

    void init() {
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
    }

    int idx(const char &c) { return c - 'a'; }

    int insert(string s, int v) {
        int u = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            int c = idx(s[i]);
            if (!ch[u][c]) {
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz].clear();
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u].insert(v);
        return u;
    }

    void get_fail() {
        queue<int> que;
        fail[0] = 0;
        for (int c = 0; c < sigma_size; c++) {
            int u = ch[0][c];
            if (u) {
                fail[u] = 0;
                que.push(u);
                last[u] = 0;
            }
        }
        while (!que.empty()) {
            int r = que.front();
            que.pop();
            for (int c = 0; c < sigma_size; c++) {
                int u = ch[r][c];
                if (!u) continue;
                que.push(u);
                int v = fail[r];
                while (v && !ch[v][c]) v = fail[v];
                fail[u] = ch[v][c];
                last[u] = val[fail[u]].size() ? fail[u] : last[fail[u]];
            }
        }
    }

    void print(int j) {
        if (j) {
            mmax = max(mmax, *val[j].rbegin());

            print(last[j]);
        }
    }

    void find() {
        mmax = 0;
        int n = strlen(T);
        int j = 0;
        for (int i = 0; i < n; i++) {
            int c = idx(T[i]);
            while (j && !ch[j][c]) j = fail[j];
            j = ch[j][c];
            if (val[j].size())
                print(j);
            else if (j)
                print(last[j]);
        }
    }
} ac;  //??????0??

int num = 0;
int dui[300005];
int pre[300005];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    ac.init();
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        dui[i] = ac.insert(s, 1);
        pre[i] = 1;
    }
    ac.get_fail();
    for (int i = 1; i <= m; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int b, c;
            cin >> b >> c;
            ac.val[dui[b]].erase(ac.val[dui[b]].find(pre[b]));
            ac.val[dui[b]].insert(c + 1);
            pre[b] = c + 1;
        } else {
            cin >> ac.T;
            ac.find();
            cout << ac.mmax - 1 << endl;
        }
    }
}