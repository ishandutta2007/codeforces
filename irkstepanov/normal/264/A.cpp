#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;

const int nmax = 1e6 + 5;

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");
    //freopen("mine.txt", "w", stdout);

    vector<int> l, r;

    char s[nmax];
    scanf("%s", s);

    for (int i = 0; s[i]; ++i) {
        if (s[i] == 'l') {
            r.pb(i + 1);
        } else {
            l.pb(i + 1);
        }
    }

    for (int i = 0; i < sz(l); ++i) {
        printf("%d\n", l[i]);
    }
    for (int i = sz(r) - 1; i >= 0; --i) {
        printf("%d\n", r[i]);
    }

}