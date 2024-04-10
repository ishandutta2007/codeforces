#include <bits/stdc++.h>

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
using namespace std;

#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;


//mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

const int maxn = (int) 3e5 + 25;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-9;
const ld PI = acos(-1.);
const ll llinf = 1e18;
const int inf = 2e9;

int main() {
    // freopen("input.txt", "r", stdin);

    vector<string> a, b, g;

    string s;
    while (1) {
        getline(cin, s);

        for (int i = 0; i + 8 < s.size(); i++) {
            if (s.substr(i, 6) == "\\cite{") {
                int j = i + 6;
                while (j < s.size() && s[j] != '}')
                    j++;
                assert(j < s.size());

                // [i + 6, j]
                string name = s.substr(i + 6, j - (i + 6));
                a.pb(name);
            }
        }

        if (s == "\\begin{thebibliography}{99}") {
            break;
        }
    }

    for (int k = 0; k < a.size(); k++) {
        string s;
        getline(cin, s);

        while (s.empty()) {
            getline(cin, s);
        }

        int i = 9;
        int j = i;
        while (j < s.size() && s[j] != '}')
            j++;
        assert(j < s.size());

        string name = s.substr(i, j - i);
        // cout << name << endl;
        b.pb(name);
        g.pb(s);
    }

    if (a == b) {
        cout << "Correct";
    } else {
        cout << "Incorrect\n";
        cout << "\\begin{thebibliography}{99}\n";

        for (int i = 0; i < a.size(); i++) {
            string res;
            for (int j = 0; j < b.size(); j++)
                if (a[i] == b[j])
                    res = g[j];
            cout << res << endl;
        }

        cout << "\\end{thebibliography}";
    }
    return 0;
}