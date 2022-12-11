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

string s;

int get_word(int pos)
{
    while (pos < sz(s) && (isalpha(s[pos]) || isdigit(s[pos]) || s[pos] == '_')) {
        ++pos;
    }
    return pos;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    getline(cin, s);

    int a = get_word(0);
    if (a < 1 || a > 16) {
        cout << "NO\n";
        return 0;
    }

    if (a == sz(s)) {
        cout << "NO\n";
        return 0;
    }

    if (s[a] != '@') {
        cout << "NO\n";
        return 0;
    }
    int a_start = a;
    int b;

    while (true) {
        b = get_word(a + 1);
        if (b - a - 1 < 1 || b - a - 1 > 16) {
            cout << "NO\n";
            return 0;
        }
        if (b == sz(s)) {
            break;
        }
        if (s[b] != '.') {
            break;
        }
        a = b;
    }

    if (b - a_start - 1 < 1 || b - a_start - 1 > 32) {
        cout << "NO\n";
        return 0;
    }

    if (b == sz(s)) {
        cout << "YES\n";
        return 0;
    }

    if (s[b] != '/') {
        cout << "NO\n";
        return 0;
    }

    a = get_word(b + 1);
    if (a - b - 1 < 1 || a - b - 1 > 16) {
        cout << "NO\n";
        return 0;
    }
    if (a != sz(s)) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

}