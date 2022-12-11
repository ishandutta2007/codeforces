#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> edge;

const int inf = 1e9;

vector<int> p_function(const string& s)
{
    int n = sz(s);
    vector<int> p(n);
    for (int i = 1; i < n; ++i) {
        int j = p[i - 1];
        while (j && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        p[i] = j;
    }
    return p;
}

int f(const string& a, const string& b)
{
    string s = b + "#" + a;
    vector<int> v = p_function(s);
    int x = 0;
    for (int i : v) {
        x = max(x, i);
    }
    if (x == sz(b)) {
        return sz(a);
    }
    x = v.back();
    return sz(a) + sz(b) - x;
}

int f(const string& a, const string& b, const string& c)
{
    string s = b + "#" + a;
    vector<int> v = p_function(s);
    int x = 0;
    for (int i : v) {
        x = max(x, i);
    }
    if (x == sz(b)) {
        return f(a, c);
    }
    return f(b, c) + sz(a) - v.back();
}

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("division.in");
    //ofstream cout("division.out");

    string a, b, c;
    cin >> a >> b >> c;
    int ans = inf;

    ans = min(ans, f(a, b, c));
    ans = min(ans, f(a, c, b));
    ans = min(ans, f(b, a, c));
    ans = min(ans, f(b, c, a));
    ans = min(ans, f(c, a, b));
    ans = min(ans, f(c, b, a));

    cout << ans << "\n";

}