#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef pair<int, int> pii;

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

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");

    string s, t;
    cin >> s >> t;
    string sr = s;
    reverse(all(sr));

    vector<pii> ans;

    while (sz(t)) {
        string a = t + "#" + s;
        string b = t + "#" + sr;
        vector<int> p1 = p_function(a), p2 = p_function(b);
        int posA = -1;
        for (int i = sz(t) + 1; i < sz(a); ++i) {
            if (p1[i] && (posA == -1 || p1[posA] < p1[i])) {
                posA = i;
            }
        }
        int posB = -1;
        for (int i = sz(t) + 1; i < sz(b); ++i) {
            if (p2[i] && (posB == -1 || p2[posB] < p2[i])) {
                posB = i;
            }
        }
        if (posB == -1 && posA == -1) {
            cout << "-1\n";
            return 0;
        }
        if (p1[posA] < p2[posB]) {
            int x = p2[posB];
            posB -= (sz(t) + 1);
            ans.pb(mp(sz(s) - posB + x - 2, sz(s) - posB - 1));
            string newT = "";
            for (int i = x; i < sz(t); ++i) {
                newT += t[i];
            }
            t = newT;
        } else {
            int x = p1[posA];
            posA -= (sz(t) + 1);
            ans.pb(mp(posA - x + 1, posA));
            string newT = "";
            for (int i = x; i < sz(t); ++i) {
                newT += t[i];
            }
            t = newT;
        }
    }

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }

}