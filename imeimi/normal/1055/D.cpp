#include <iostream>
#include <algorithm>
#include <vector>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n;
char S[3005][3005];
char T[3005][3005];
int st[3004], ed[3005];
int f[3004];
void fail(int i = 0) {
    printf("NO\n");
    exit(0);
}

int find(vector<char> pt, char * str) {
    f[0] = 0;
    for (int i = 1, j = 0; i < pt.size(); ++i) {
        while (j > 0 && pt[i] != pt[j]) j = f[j - 1];
        if (pt[i] == pt[j]) f[i] = ++j;
        else f[i] = 0;
    }
    for (int i = 0, j = 0; str[i]; ++i) {
        while (j > 0 && str[i] != pt[j]) j = f[j - 1];
        if (str[i] == pt[j]) {
            if (j + 1 == pt.size()) return i - pt.size() + 1;
            ++j;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> S[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> T[i];
    }
    vector<pii> A;
    for (int i = 1; i <= n; ++i) {
        st[i] = 1e9, ed[i] = -1;
        for (int j = 0; S[i][j]; ++j) {
            if (S[i][j] != T[i][j]) st[i] = min(st[i], j), ed[i] = max(ed[i], j);
        }
        if (ed[i] == -1) continue;
        if (A.empty()) {
            for (int j = st[i]; j <= ed[i]; ++j) {
                A.emplace_back(S[i][j], T[i][j]);
            }
        }
        else {
            if (ed[i] - st[i] + 1 != A.size()) fail(1);
            for (int j = st[i]; j <= ed[i]; ++j) {
                if (A[j - st[i]] != pii(S[i][j], T[i][j])) fail(2);
            }
        }
    }
    while (1) {
        int pos = 1;
        char c = 0;
        for (int i = 1; i <= n; ++i) {
            if (ed[i] == -1) continue;
            if (st[i] == 0) {
                pos = 0;
                break;
            }
            if (c == 0) c = S[i][st[i] - 1];
            else if (c != S[i][st[i] - 1]) {
                pos = 0;
                break;
            }
        }
        if (!pos) break;
        for (int i = 1; i <= n; ++i) {
            if (ed[i] == -1) continue;
            --st[i];
        }
    }
    while (1) {
        int pos = 1;
        char c = 0;
        for (int i = 1; i <= n; ++i) {
            if (ed[i] == -1) continue;
            if (S[i][ed[i] + 1] == 0) {
                pos = 0;
                break;
            }
            if (c == 0) c = S[i][ed[i] + 1];
            else if (c != S[i][ed[i] + 1]) {
                pos = 0;
                break;
            }
        }
        if (!pos) break;
        for (int i = 1; i <= n; ++i) {
            if (ed[i] == -1) continue;
            ++ed[i];
        }
    }
    vector<char> pt;
    A.clear();
    for (int i = 1; i <= n; ++i) {
        if (ed[i] == -1) continue;
        for (int j = st[i]; j <= ed[i]; ++j) {
            pt.push_back(S[i][j]);
            A.emplace_back(S[i][j], T[i][j]);
        }
        break;
    }
    for (int i = 1; i <= n; ++i) {
        int ret = find(pt, S[i]);
        if (ret == -1) continue;
        if (ed[i] == -1) fail(3);
        if (ret != st[i]) fail(4);
    }
    printf("YES\n");
    for (int i = 0; i < A.size(); ++i) printf("%c", (char)A[i].fs);
    printf("\n");
    for (int i = 0; i < A.size(); ++i) printf("%c", (char)A[i].se);
    printf("\n");
    return 0;
}