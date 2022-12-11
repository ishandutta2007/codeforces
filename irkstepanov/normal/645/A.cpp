#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

void dfs(string s, set<string>& m)
{
    if (s[0] == 'X') {
        string t = s;
        swap(t[0], t[2]);
        if (!m.count(t)) {
            m.insert(t);
            dfs(t, m);
        }
        swap(t[0], t[2]);
        swap(t[0], t[1]);
        if (!m.count(t)) {
            m.insert(t);
            dfs(t, m);
        }
    } else if (s[1] == 'X') {
        string t = s;
        swap(t[0], t[1]);
        if (!m.count(t)) {
            m.insert(t);
            dfs(t, m);
        }
        swap(t[0], t[1]);
        swap(t[1], t[3]);
        if (!m.count(t)) {
            m.insert(t);
            dfs(t, m);
        }
    } else if (s[2] == 'X') {
        string t = s;
        swap(t[0], t[2]);
        if (!m.count(t)) {
            m.insert(t);
            dfs(t, m);
        }
        swap(t[0], t[2]);
        swap(t[2], t[3]);
        if (!m.count(t)) {
            m.insert(t);
            dfs(t, m);
        }
    } else {
        string t = s;
        swap(t[3], t[1]);
        if (!m.count(t)) {
            m.insert(t);
            dfs(t, m);
        }
        swap(t[3], t[1]);
        swap(t[3], t[2]);
        if (!m.count(t)) {
            m.insert(t);
            dfs(t, m);
        }
    }
}

int main()
{

    string a = "", b = "";
    char c;
    for (int i = 0; i < 4; ++i) {
        cin >> c;
        a += c;
    }
    for (int i = 0; i < 4; ++i) {
        cin >> c;
        b += c;
    }

    set<string> x, y;
    dfs(a, x);
    dfs(b, y);

    for (auto& s : x) {
        if (y.count(s)) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

}