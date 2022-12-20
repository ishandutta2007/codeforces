#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e4 + 1;

bool b[N][N];
int a[N];

int main() {
    string s, t, sres;
    int i, j, n, k, m, l;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    n = t.size();
    s = t;
    for (i = 0; i < 25; ++i) {
        for (j = 0; j * 25 + i < t.size(); ++j)
            s[i + j * 25] = 'a' + i;
    }
    for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j)
        b[i][j] = 1;
    cout << "? " << s << endl;
    cin >> sres;
    for (i = 0; i < n; ++i) {
        s[i] -= 'a';
        sres[i] -= 'a';
    }
    for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j)
    if (s[i] != sres[j])
        b[i][j] = 0;
    for (i = 0; i < 25; ++i) {
        for (j = 0; j * 625 + i * 25 < n; ++j)
        for (l = 0; l < 25 && l + i * 25 + j * 625 < n; ++l)
            s[l + i * 25 +  j * 625] = 'a' + i;
    }
    cout << "? " << s << endl;
    cin >> sres;
    for (i = 0; i < n; ++i) {
        s[i] -= 'a';
        sres[i] -= 'a';
    }
    for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j)
    if (s[i] != sres[j])
        b[i][j] = 0;
    for (i = 0; i < 25; ++i) {
        for (l = 0; l < 625 && i * 625 + l < n;++l)
            s[i * 625 + l] = 'a' + i;
    }
    cout << "? " << s << endl;
    cin >> sres;
    for (i = 0; i < n; ++i) {
        s[i] -= 'a';
        sres[i] -= 'a';
    }
    for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j)
    if (s[i] != sres[j])
        b[i][j] = 0;
    else if (b[i][j]) {
            a[j] = i;
    }
    for (i = 0; i < n; ++i)
        s[a[i]] = t[i];
    cout << "! " << s;
}