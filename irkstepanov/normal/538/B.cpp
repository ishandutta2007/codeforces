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

    string s;
    cin >> s;

    vector <string> v;
    for (int i = 0; i < 100; i++)
    {
        string d = "";
        for (int j = 0; j < sz(s); j++)
            d += "0";
        for (int j = 0; j < sz(s); j++)
            if (s[j] > '0')
        {
            d[j] = '1';
            --s[j];
        }
        v.pb(d);
    }

    for (int i = 0; i < 100; i++)
        solve(v[i]);

    vector <string> ans;
    for (int i = 0; i < 100; i++)
        if (v[i] != "") ans.pb(v[i]);

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); i++)
        cout << ans[i] << " ";

}