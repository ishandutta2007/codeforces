#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
const int M = N << 1;

char tmp[N];

int n;
int ls[N], rs[N];
int z[M];

string s[N], t[N];

int read() {
    if (scanf("%d", &n) < 1) return false;
    for (int i = 0; i < n; ++i) scanf("%s", tmp), s[i] = tmp;
    for (int i = 0; i < n; ++i) scanf("%s", tmp), t[i] = tmp;
    return true;
}


void getZ(const string &s) {
    for (int i = 1, l = 0, r = -1; i < s.size(); ++i) {
        if (i + z[i - l] < r) {
            z[i] = z[i - l];
        } else {
            l = i;
            r = max(r, i);
            while (r < s.size() && s[r] == s[r - l]) ++r;
            z[i] = r - l;
        }
    }
}

int getPos(const string &s, const string &t) {
    getZ(t + "#" + s);
    for (int i = 0; i < s.size(); ++i) {
        if (z[t.size() + 1 + i] >= t.size()) return i;
    }
    return -1;
}

void solve() {
    string from, to;
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i] && (ls[i] = rs[i] = -1)) continue;
        auto &l = ls[i], &r = rs[i];
        l = 0, r = s[i].size();
        while (s[i][l] == t[i][l]) ++l;
        while (s[i][r - 1] == t[i][r - 1]) --r;
        string curs = s[i].substr(l, r - l), curt = t[i].substr(l, r - l);
        if (from.empty()) from = curs, to = curt;
        if (from != curs || to != curt) return void(printf("NO\n"));
    }
    while (true) {
        char c = 0;
        bool bad = false;
        for (int i = 0; i < n; ++i) {
            if (ls[i] == -1) continue;
            if (ls[i] == 0 && (bad = true)) break;
            if (!c) c = s[i][ls[i] - 1];
            if (c != s[i][ls[i] - 1] && (bad = true)) break;
        }
        if (bad) break;
        from.insert(from.begin(), c);
        to.insert(to.begin(), c);
        for (int i = 0; i < n; ++i) {
            if (~ls[i]) --ls[i];
        }
    }
    while (true) {
        char c = 0;
        bool bad = false;
        for (int i = 0; i < n; ++i) {
            if (ls[i] == -1) continue;
            if (rs[i] >= s[i].size() && (bad = true)) break;
            if (!c) c = s[i][rs[i]];
            if (c != s[i][rs[i]] && (bad = true)) break;
        }
        if (bad) break;
        from += c;
        to += c;
        for (int i = 0; i < n; ++i) {
            if (ls[i] == -1) continue;
            ++rs[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        int pos = getPos(s[i], from);
        if (ls[i] == -1) {
            if (pos != -1) return void(printf("NO\n"));
        } else {
            if (pos != ls[i]) return void(printf("NO\n"));
        }
    }
    printf("YES\n");
    printf("%s\n%s\n", from.c_str(), to.c_str());
}

int main() {
    while (read()) solve();
    return 0;
}