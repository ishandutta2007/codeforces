#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef unsigned long long ll;
typedef pair <int, int> pii;
typedef long double ld;

void solve(string &s)
{
    string ans = "";
    int i;
    for (i = 0; i < sz(s); i++)
        if (s[i] != '0') break;
    for (; i < sz(s); i++)
        ans += s[i];
    s = ans;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    string code = "CODEFORCES";
    string s;

    cin >> s;

    if (sz(s) < sz(code)) {cout << "NO\n"; return 0;}
    if (sz(s) == sz(code))
    {
        cout << (s == code ? "YES\n" : "NO\n");
        return 0;
    }

    for (int i = 0; i + sz(s) - 1 - sz(code) < sz(s); i++)
    {
        int j = i + sz(s) - 1 - sz(code);
        int pos = 0;
        bool ok = true;
        for (int k = 0; k < sz(s); k++)
            if (k < i || k > j)
        {
            if (s[k] != code[pos]) ok = false;
            ++pos;
        }
        if (ok) {cout << "YES\n"; return 0;}
    }

    cout << "NO\n";

}