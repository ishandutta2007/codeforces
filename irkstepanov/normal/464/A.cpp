#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("correct.txt");

    int n, p;
    cin >> n >> p;

    string s;
    cin >> s;
    if (p == 1) {
        cout << "NO\n";
        return 0;
    }

    if (p == 2) {
        if (n == 1) {
            if (s == "a") {
                cout << "b\n";
            } else {
                cout << "NO\n";
            }
        } else {
            if (s == "ab") {
                cout << "ba\n";
            } else {
                cout << "NO\n";
            }
        }
        return 0;
    }

    int r;
    bool ok = false;
    for (r = n - 1; r >= 0; --r) {
        char x = '?', y = '?';
        if (r >= 1) {
            x = s[r - 1];
        }
        if (r >= 2) {
            y = s[r - 2];
        }
        for (char c = (char)(s[r] + 1); c <= (char)(p - 1 + 'a'); ++c) {
            if (x != c && y != c) {
                s[r] = c;
                //cout << "IDIOT " << c << "\n";
                ok = true;
                break;
            }
        }
        if (ok) {
            break;
        }
    }

    if (!ok) {
        cout << "NO\n";
        return 0;
    }

    for (int i = r + 1; i < n; ++i) {
        char x = '?', y = '?';
        if (i >= 1) {
            x = s[i - 1];
        }
        if (i >= 2) {
            y = s[i - 2];
        }
        s[i] = 'a';
        while (s[i] == x || s[i] == y) {
            ++s[i];
        }
    }
    cout << s << "\n";

}