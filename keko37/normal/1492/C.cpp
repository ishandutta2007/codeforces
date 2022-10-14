#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int n, m, sol;
int prf[MAXN], suf[MAXN];
string s, t;

void precompute () {
    int curr = 0;
    for (int i = 0; i < m; i++) {
        while (s[curr] != t[i]) curr++;
        prf[i] = curr;
        curr++;
    }
    curr = n - 1;
    for (int i = m - 1; i >= 0; i--) {
        while (s[curr] != t[i]) curr--;
        suf[i] = curr;
        curr--;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s >> t;
    precompute();
    for (int i = 0; i < m-1; i++) {
        sol = max(sol, suf[i + 1] - prf[i]);
    }
    cout << sol;
    return 0;
}