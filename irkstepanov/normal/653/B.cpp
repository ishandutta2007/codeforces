#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<string> v;

void build(string s, int n)
{
    if (n == 0) {
        v.pb(s);
        return;
    }
    string t = s + "?";
    for (char c = 'a'; c <= 'f'; ++c) {
        t[sz(t) - 1] = c;
        build(t, n - 1);
    }
}

int main()
{

    //ifstream cin("input.txt");

    int n;
    cin >> n;

    vector<vector<char> > t(6, vector<char>(6, '?'));
    int q;
    cin >> q;

    while (q--) {
        char a, b, c;
        cin >> a >> b >> c;
        t[a - 'a'][b - 'a'] = c;
    }

    build("", n);
    int ans = 0;

    for (string& s : v) {
        //cout << s << "\n";
        int pos = 0;
        while (pos < n - 1) {
            if (t[s[pos] - 'a'][s[pos + 1] - 'a'] != '?') {
                s[pos + 1] = t[s[pos] - 'a'][s[pos + 1] - 'a'];
                ++pos;
            } else {
                break;
            }
        }
        if (pos == n - 1 && s[n - 1] == 'a') {
            ++ans;
        }
    }

    cout << ans << "\n";

}