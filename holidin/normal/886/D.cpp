#include <bits/stdc++.h>
using namespace std;
const int N = 300;


bool b[N], d[N];
int c[N];

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int i,j, n;
    set <char> se[N];
    set <int> p;
    vector <char> e[N];
    cin >> n;
    string s1, s;
    s1 = "";
    for (i = 0; i < n; ++i) {
        cin >> s;
        p.clear();
        for (j = 0; j < s.size(); ++j) {
        if (p.find(s[j]) != p.end()) {
            cout << "NO";
            return 0;
        } else
            p.insert(s[j]);
            d[s[j]] = true;
        }
        for (j = 0; j < s.size() - 1; ++j) {
            if (se[s[j]].find(s[j + 1]) == se[s[j]].end())
                e[s[j]].push_back(s[j + 1]);
            se[s[j]].insert(s[j + 1]);
        }
    }
    for (i = 0; i < 256; ++i)
    if (e[i].size() > 1) {
        cout << "NO";
        return 0;
    } else {
        for (j = 0; j < e[i].size(); ++j)
            c[e[i][j]]++;
    }
    int tf = 0;
    s1 = "";
    for (i = 0; i < 256; ++i) {
        if (c[i] > 1) {
            cout << "NO";
            return 0;
        }
    }
    for (i = 0; i < 256; ++i)
    if ((c[i] == 0) && (!b[i]) && (d[i])) {
        b[i] = true;
        s1 += (char) i;
        j = i;
        while (e[j].size() == 1) {
            j = e[j][0];
            s1 += char(j);
            b[j] = true;
        }
    }
    for (i = 0; i < 256; ++i)
    if ((d[i]) && (!b[i])) {
        cout << "NO";
        return 0;
    }
    cout << s1;
}