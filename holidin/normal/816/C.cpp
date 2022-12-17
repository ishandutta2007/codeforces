#include <bits/stdc++.h>
using namespace std;

const int N = 150;

int main() {
    int i, j, m[N][N], st[N], str[N], g[N][N], a[N][N], n1, k1, n, k;
    string s, s1, s2;
    s = "row";
    s1 = "col";
    cin >> n >> k;
    for (i = 1; i <= 120; i++) {
        str[i] = 600;
        st[i] = 600;
    }
    n1 = 0;
    for (i = 1; i <= n; i++)
    for (j = 1; j <= k; j++)
    cin >> g[i][j];
    if (n >= k) {
        s2 = s;
        s = s1;
        s1 = s2;
        for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        a[j][i] = g[i][j];
        i = n;
        n = k;
        k = i;
        for (i = 1; i <= n; i++)
        for (j = 1; j <= k; j++)
        g[i][j] = a[i][j];
    }
    for (i = 1; i <= n; i++) {
    for (j = 1; j <= k; j++) {
        if (str[i] > g[i][j])
            str[i] = g[i][j];
        a[i][j] = 0;
    }
    for (j = 1; j <= k; j++)
        a[i][j] = str[i];
    if (str[i] > 0) n1 += str[i];
    }
    bool b = true;
    for (j = 1; j <= k; j++) {
        for (i = 1; i <= n; i++)
            if (st[j] > g[i][j] - a[i][j])
                st[j] = g[i][j] - a[i][j];
        for (i = 1; i <= n; i++)
            if (g[i][j] - a[i][j] != st[j])
               b = false;
        if (st[j] > 0) n1 += st[j];;
    }
    if (b == false)
        cout << -1;
    else {
        cout << n1 << endl;
        for (i = 1; i <= n; i++)
        for (j = 1; j <= str[i]; j++)
        cout << s << ' ' << i << endl;
        for (j = 1; j <= k; j++)
        for (i = 1; i <= st[j]; i++)
        cout << s1 << ' ' << j << endl;
    }
}