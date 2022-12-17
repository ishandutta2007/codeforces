#include <bits/stdc++.h>
using namespace std;

bool b[500];


int main() {
   //freopen("input.txt", "r", stdin);
   ios_base::sync_with_stdio(false);
   string s, s1;
   long long n, k, i, j, x;
   cin >> s;
   for (i = 0; i < s.size(); ++i)
       b[s[i]] = true;
    cin >> s;
    x = -1;
    for (i = 0; i < s.size(); ++i)
    if (s[i] == '*')
        x = i;
    cin >> k;
    for (i = 1; i <= k; ++i) {
        cin >> s1;
        if (((s1.size() > s.size()) && (x == -1)) || (s1.size() + 1 < s.size())) {
            cout << "NO\n";
            continue;
        }
        bool men = true;
        for (j = 0; j < x; ++j)
        if ((s[j] >= 'a') && (s[j] <= 'z'))
            if (s1[j] != s[j])
                 men = false;
            else
                k = k;
        else if (!b[s1[j]])
            men = false;
        for (j = 1; (int) s.size() - j > x; ++j)
        if ((s[s.size() - j] >= 'a') && (s[s.size() - j] <= 'z'))
            if (s1[s1.size() - j] != s[s.size() - j])
                 men = false;
            else
                k = k;
        else if (!b[s1[s1.size() - j]])
            men = false;
        if (x != -1)
        for (j = 0; j <= (int) s1.size() - (int) s.size(); ++j)
        if (b[s1[x + j]])
            men = false;
        if (men)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}