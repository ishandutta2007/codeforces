#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{

    //ifstream cin("input.txt");

    //ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = sz(s);

    vector<char> dp2(n, false), dp3(n, false);
    dp2[n - 2] = true, dp3[n - 3] = true;
    if (s[n - 4] != s[n - 2] || s[n - 3] != s[n - 1]) {
        dp2[n - 4] = true;
    }

    for (int i = n - 5; i >= 5; --i) {
        if ((s[i + 2] != s[i] || s[i + 3] != s[i + 1]) && dp2[i + 2]) {
            dp2[i] = true;
        }
        if (dp3[i + 2]) {
            dp2[i] = true;
        }
        if (dp2[i + 3]) {
            dp3[i] = true;
        }
        if ((s[i + 3] != s[i] || s[i + 4] != s[i + 1] || s[i + 5] != s[i + 2]) && dp3[i + 3]) {
            dp3[i] = true;
        }
    }

    set<string> m;

    for (int i = 5; i + 1 < n; ++i) {
        if (dp2[i]) {
            string t = "";
            t += s[i];
            t += s[i + 1];
            m.insert(t);
        }
    }
    for (int i = 5; i + 2 < n; ++i) {
        if (dp3[i]) {
            string t = "";
            t += s[i];
            t += s[i + 1];
            t += s[i + 2];
            m.insert(t);
        }
    }

    cout << sz(m) << "\n";
    for (auto& t : m) {
        cout << t << "\n";
    }

}