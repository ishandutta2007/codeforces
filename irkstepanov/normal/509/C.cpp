#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

string f(int b)
{
    if (!b) {
        return "0";
    }
    string s = "";
    while (b >= 10) {
        s += "9";
        b -= 9;
    }
    if (b) {
        s += (char)(b + '0');
    }
    reverse(all(s));
    return s;
}

bool exist(int sum, int cnt)
{
    if (sum < 0) {
        return false;
    }
    if (cnt * 9 < sum) {
        return false;
    }
    return true;
}

int main()
{

    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    string s = f(b[0]);
    cout << s << "\n";

    for (int i = 1; i < n; ++i) {
        int l = sz(s);
        int sum = b[i - 1];
        bool found = false;
        for (int j = l - 1; j >= 0; --j) {
            for (int d = s[j] - '0' + 1; d <= 9; ++d) {
                if (exist(b[i] - (sum - (s[j] - '0') + d), l - j - 1)) {
                    string tmp = f(b[i] - (sum - (s[j] - '0') + d));
                    string t = "";
                    for (int p = 0; p < j; ++p) {
                        t += s[p];
                    }
                    t += (char)(d + '0');
                    while (sz(t) + sz(tmp) < l) {
                        t += "0";
                    }
                    if (sz(t) < l) {
                        t += tmp;
                    }
                    cout << t << "\n";
                    s = t;
                    found = true;
                    break;
                }
            }
            sum -= (s[j] - '0');
            if (found) {
                break;
            }
        }
        if (found) {
            continue;
        }
        string t = f(b[i]);
        if (sz(t) > l) {
            cout << t << "\n";
            s = t;
            continue;
        }
        t = f(b[i] - 1);
        string ans = "1";
        while (sz(ans) + sz(t) < l + 1) {
            ans += "0";
        }
        if (sz(ans) < l + 1) {
            ans += t;
        }
        cout << ans << "\n";
        s = ans;
    }

}