#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

llint n, sol;
string s;
int val[MAXN], fen[MAXN];
vector <int> v[300];

void ubaci (int x, int k) {
    for (x++; x < MAXN; x += x&-x) fen[x] += k;
}

int upit (int x) {
    int res = 0;
    for (x++; x > 0; x -= x&-x) res += fen[x];
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        v[s[i]].push_back(i);
    }
    for (char c = 'a'; c <= 'z'; c++) {
        int siz = v[c].size();
        for (int i = 0; i < siz; i++) {
            val[v[c][i]] = n - 1 - v[c][siz - 1 - i];
        }
    }
    for (int i = 0; i < n; i++) {
        sol += i - upit(val[i]);
        ubaci(val[i], 1);
    }
    cout << sol;
    return 0;
}