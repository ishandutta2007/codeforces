#include <bits/stdc++.h>
using namespace std;
const int N = 200000;

string s1[N], s;
char c1[N], c;

int main() {
    int i, j, n, k;
    bool b[500], b1[500];
    char ans;
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (j = 'a'; j <= 'z'; ++j)
        b[j] = true;
    for (i = 1; i <= n; ++i) {
        cin >> c1[i];
        cin >> s1[i];
    }
    ans = s1[n][0];
    int cnt = 0;
    bool found = false;
    for (i = 1; i <= n; ++i) {
        c = c1[i];
        s = s1[i];
        if (c == '.') {
            for (j = 'a'; j <= 'z'; ++j)
                b1[j] = false;
            for (j = 0; j < s.size(); ++j)
                b1[s[j]] = true;
            for (j = 'a'; j <= 'z'; ++j)
            if (b1[j])
                b[j] = false;
        }
        if (c == '!') {
            for (j = 'a'; j <= 'z'; ++j)
                b1[j] = false;
            for (j = 0; j < s.size(); ++j)
                b1[s[j]] = true;
            for (j = 'a'; j <= 'z'; ++j)
            if (!b1[j])
                b[j] = false;
            if (found)
                ++cnt;
        }
        if (c == '?') {
            if (s[0] != ans && found)
                ++cnt;
            if (s[0] != ans)
                b[s[0]] = false;
        }
        int p = 0;
        for (j = 'a'; j <= 'z'; ++j)
        if (b[j])
            ++p;
        if (p < 2)
            found = true;
    }
    cout << cnt << endl;
}