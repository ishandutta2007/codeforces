#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

vector<int> p_function(const string& s)
{
    int n = sz(s);
    vector<int> p(n);
    for (int i = 1; i < n; ++i) {
        int j  = p[i - 1];
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

int main()
{

    ios::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");

    string s, t;
    cin >> s >> t;
    string a = t + "#" + s;
    vector<int> p = p_function(a);

    int ans = 0;
    for (int i = 0; i < sz(s);) {
        if (p[sz(t) + 1 + i] == sz(t)) {
            ++ans;
            i += sz(t);
        } else {
            ++i;
        }
    }

    cout << ans << "\n";

}