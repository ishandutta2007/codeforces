#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 200005;

int n;
int par[MAXN], f[30][MAXN];
string s[MAXN];
vector <int> v;

int nadi (int x) {
    if (x == par[x]) return x;
    return par[x] = nadi(par[x]);
}

void spoji (int x, int y) {
    par[nadi(y)] = nadi(x);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        cin >> s[i];
        for (auto c : s[i]) f[c - 'a'][i]++;
    }
    for (char c = 'a'; c <= 'z'; c++) {
        v.clear();
        for (int i = 1; i <= n; i++) {
            if (f[c - 'a'][i] > 0) v.push_back(i);
        }
        for (int i = 1; i < v.size(); i++) spoji(v[i - 1], v[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (par[i] == i) cnt++;
    }
    cout << cnt;
    return 0;
}