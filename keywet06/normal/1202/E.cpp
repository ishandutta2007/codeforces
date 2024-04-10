#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

template <class T>
void chkmin(T &x, const T &y) {
    if (y < x) {
        x = y;
    }
}

template <class T>
void chkmax(T &x, const T &y) {
    if (y > x) {
        x = y;
    }
}

template <class T>
void sort(vector<T> &a) {
    sort(a.begin(), a.end());
}

template <class T>
void reverse(vector<T> &a) {
    reverse(a.begin(), a.end());
}

void reverse(string &a) { reverse(a.begin(), a.end()); }

template <class T, class Cmp>
void sort(vector<T> &a, Cmp cmp) {
    sort(a.begin(), a.end(), cmp);
}

template <class T>
void unique(vector<T> &a) {
    a.resize(unique(a.begin(), a.end()) - a.begin());
}

int readInt() {
    int x = 0;
    char c = getchar();
    while (!isdigit(c)) {
        c = getchar();
    }
    while (isdigit(c)) {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return x;
}

string readString() {
    string s;
    char c = getchar();
    while (isspace(c)) {
        c = getchar();
    }
    while (!isspace(c)) {
        s += c;
        c = getchar();
    }
    return s;
}

class SAM {
   private:
    void dfs(int u) {
        if (t[u].endp != -1) {
            x[t[u].endp] = cnt[u];
        }
        for (int v : e[u]) {
            cnt[v] += cnt[u];
            dfs(v);
        }
    }

   public:
    struct node {
        int len, link, endp;
        int next[26];
        node() : len(0), link(0), endp(-1), next{} {}
    };
    int last;
    vector<node> t;
    vector<int> cnt;
    vector<vector<int>> e;
    vector<int> x;
    SAM() : last(1) {
        t.emplace_back();
        t[0].len = -1;
        t[0].link = -1;
        for (int i = 0; i < 26; ++i) {
            t[0].next[i] = 1;
        }
        t.emplace_back();
    }
    void extend(int c) {
        int p = last;
        int cur = t.size();
        t.emplace_back();
        t[cur].len = t[p].len + 1;
        t[cur].endp = t[p].len;
        last = cur;
        while (t[p].next[c] == 0) {
            t[p].next[c] = cur;
            p = t[p].link;
        }
        int q = t[p].next[c];
        if (t[q].len == t[p].len + 1) {
            t[cur].link = q;
        } else {
            int r = t.size();
            t.push_back(t[q]);
            t[r].len = t[p].len + 1;
            t[r].endp = -1;
            t[q].link = r;
            t[cur].link = r;
            while (t[p].next[c] == q) {
                t[p].next[c] = r;
                p = t[p].link;
            }
        }
    }
    void work() { cnt.resize(t.size()); }
    void work2() {
        e.resize(t.size());
        x.resize(t[last].len);
        for (int i = 1; i < t.size(); ++i) {
            e[t[i].link].push_back(i);
        }
        dfs(1);
    }
    void read(const string &s) {
        int p = 1;
        for (char c : s) {
            c -= 'a';
            if (t[p].next[c] == 0) {
                return;
            }
            p = t[p].next[c];
        }
        ++cnt[p];
    }
};

void solve_single_test(int test_id = 1) {
    string t = readString();
    int L = t.length();
    int n = readInt();
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        s[i] = readString();
    }
    SAM T1, T2;
    for (int i = 0; i < L; ++i) {
        T1.extend(t[i] - 'a');
    }
    for (int i = L - 1; i >= 0; --i) {
        T2.extend(t[i] - 'a');
    }
    T1.work();
    T2.work();
    for (int i = 0; i < n; ++i) {
        T1.read(s[i]);
        reverse(s[i]);
        T2.read(s[i]);
    }
    T1.work2();
    T2.work2();
    reverse(T2.x);
    int64 ans = 0;
    for (int i = 0; i < L - 1; ++i) {
        ans += 1ll * T1.x[i] * T2.x[i + 1];
    }
    printf("%I64d\n", ans);
}

void solve_multiple_tests() {
    int n_tests = readInt();
    for (int i = 1; i <= n_tests; ++i) {
        solve_single_test(i);
    }
}

int main() {
    solve_single_test();
    return 0;
}