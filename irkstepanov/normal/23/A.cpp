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

vector<int> p_func(const string& s)
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

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = sz(s);

    for (int len = n; len >= 1; --len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            string t = s.substr(i, len);
            t += "#";
            t += s;
            vector<int> p = p_func(t);
            int cnt = 0;
            for (int j = len; j < sz(t); ++j) {
                if (p[j] == len) {
                    ++cnt;
                }
            }
            if (cnt >= 2) {
                cout << len << "\n";
                return 0;
            }
        }
    }
    cout << "0\n";

}