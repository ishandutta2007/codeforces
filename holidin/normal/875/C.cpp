#include <bits/stdc++.h>
using namespace std;
const int N = 200000;

int k, t[N], top[N];
bool b[N], can[N];

vector <int> h[N], s, s1, e[N], d[N];

int f(int a) {
   if (b[t[a]])
       return a - k;
   else
       return a;
}

void rec(int u) {
    if (can[u] == false)
        return;
    else {
        if (b[u]) {
            cout << "NO";
            exit(0);
        }
        can[u] = false;
        for (int i = 0; i < d[u].size(); ++i)
            rec(d[u][i]);
    }
}

void rec1(int u) {
    if (b[u])
        return;
    else {
        b[u] = true;
        for (int i = 0; i < e[u].size(); ++i)
            rec1(e[u][i]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    int i, j, n, a1, a2, o;
     ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (i = 1; i <= k; ++i)
        b[i] = false;
    cin >> a2;
    for (i = 0; i < a2; ++i) {
        cin >> j;
        s1.push_back(j);
    }
    for (i = 1; i <= k; ++i) {
        h[i].push_back(i);
        t[i] = i;
        can[i] = true;
        top[i] = 0;
    }
    for (i = 2; i <= n; ++i) {
        a1 = a2;
        s = s1;
        cin >> a2;
        s1.clear();
        for (j = 0; j < a2; ++j) {
            cin >> o;
            s1.push_back(o);
        }
        j = 0;
        while ((j < a1) && (j < a2) && (f(s1[j]) == f(s[j]))) ++j;
        if (j == a2)
            if (a1 == a2)
                continue;
            else {
                cout << "No" << "\n";
                return 0;
            }
        if (j == a1)
            continue;
        if (f(s[j]) < f(s1[j])) {
             if ((f(s[j]) <= 0) && (s1[j] < s[j])) {
                if (!can[t[s1[j]]]) {
                     rec(t[s1[j]]);
                }
             } else if ((f(s[j]) > 0) && (f(s1[j]) > 0)) {
                     e[s1[j]].push_back(s[j]);
                     d[s[j]].push_back(s1[j]);
                     if (can[s1[j]] && !can[s[j]]) {
                        rec(s1[j]);
                        can[s1[j]] = false;
                     }
             }
        }
        if (f(s[j]) > f(s1[j])) {
            if ((f(s[j]) > 0) && (f(s1[j]) > 0) && (can[s[j]]) && (s[j] != s1[j])) {
                rec1(s[j]);
                if (can[s1[j]])
                    rec(s1[j]);
            } else if ((f(s[j]) > 0) && (s[j] < s1[j]) && (f(s1[j]) <= 0) && (can[s[j]]) && (s[j] != s1[j])) {
                rec1(s[j]);
            } else {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    s.clear();
    for (i = 1; i <= k; ++i)
    if (b[t[i]])
        s.push_back(i);
    cout << s.size() << "\n";
    for (i = 0; i < s.size(); ++i)
        cout << s[i] << ' ';
}