#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    string s;
    cin >> s;
    int dot = -1;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == '.') {
            dot = i;
        }
    }

    int deg = 0;
    if (dot == -1) {
        deg = sz(s);
        string t = "0." + s;
        s = t;
    } else {
        deg = dot;
        string t = "0.";
        for (int i = 0; i < sz(s); ++i) {
            if (s[i] != '.') {
                t += s[i];
            }
        }
        s = t;
    }

    int lst = sz(s) - 1;
    while (s[lst] == '0') {
        --lst;
    }

    s = s.substr(0, lst + 1);

    if (s == "0.") {
        cout << "0\n";
        return 0;
    }

    int fst = 2;
    while (s[fst] == '0') {
        ++fst;
    }

    s = s.substr(fst);
    deg -= fst - 1;
    cout << s[0];
    if (sz(s) > 1) {
        cout << '.';
        for (int i = 1; i < sz(s); ++i) {
            cout << s[i];
        }
    }
    if (deg) {
        cout << 'E' << deg;
    }
    cout << "\n";

}