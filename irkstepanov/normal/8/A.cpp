#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int posA, posB;

bool match(const string& s, const string& a, int pos)
{
    if (sz(a) + pos > sz(s)) {
        return false;
    }
    for (int i = 0; i < sz(a); ++i) {
        if (s[i + pos] != a[i]) {
            return false;
        }
    }
    return true;
}

void f(const string& s, const string& a, const string& b)
{
    for (int i = 0; i < sz(s); ++i) {
        if (match(s, a, i)) {
            posA = i;
            break;
        }
    }
    for (int i = sz(s) - 1; i >= 0; --i) {
        if (match(s, b, i)) {
            posB = i;
            break;
        }
    }
}

int main()
{

    string s, a, b;
    cin >> s >> a >> b;
    posA = posB = -1;

    f(s, a, b);

    bool ans1 = false;
    if (posA != -1 && posB != -1 && posB >= posA + sz(a)) {
        ans1 = true;
    }

    posA = posB = -1;
    reverse(all(s));
    f(s, a, b);

    bool ans2 = false;
    if (posA != -1 && posB != -1 && posB >= posA + sz(a)) {
        ans2 = true;
    }

    if (ans1 && ans2) {
        cout << "both\n";
    } else if (ans1) {
        cout << "forward\n";
    } else if (ans2) {
        cout << "backward\n";
    } else {
        cout << "fantasy\n";
    }

}