#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef unsigned int uuint;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

vector<int> p_function(const string& s)
{
    int n = sz(s);
    vector<int> p(n);
    for (int i = 1; i < n; ++i) {
        int j = p[i - 1];
        while (j && s[j] != s[i]) {
            j = p[j - 1];
        }
        if (s[j] == s[i]) {
            ++j;
        }
        p[i] = j;
    }
    return p;
}

void change(string& s)
{
    string ans = "";
    for (int i = sz(s) - 1; i >= 0; --i) {
        if (s[i] == 'W') {
            ans += 'E';
        }
        if (s[i] == 'E') {
            ans += 'W';
        }
        if (s[i] == 'N') {
            ans += 'S';
        }
        if (s[i] == 'S') {
            ans += 'N';
        }
    }
    s = ans;
}

int main()
{

    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;
    --n;

    change(a);

    string s = a + "#" + b;
    vector<int> p = p_function(s);
    if (p.back()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

}