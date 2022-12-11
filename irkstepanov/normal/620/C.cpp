#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main()
{

    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");

    int n;
    scanf("%d", &n);
    vector<pii> ans;

    int prev = 0;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        if (s.count(a)) {
            ans.pb(mp(prev, i));
            prev = i + 1;
            s.clear();
            continue;
        } else {
            s.insert(a);
        }
    }

    if (ans.empty()) {
        cout << "-1\n";
        return 0;
    }

    if (ans.back().second != n - 1) {
        ans.back().second = n - 1;
    }
    printf("%d\n", sz(ans));
    for (pii p : ans) {
        printf("%d %d\n", p.first + 1, p.second + 1);
    }

}