#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef unsigned int uuint;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

struct event
{
    int x;
    char c;
    bool operator<(const event& other) const
    {
        if (x != other.x) {
            return x < other.x;
        }
        if (c != other.c) {
            return c == 'o';
        }
        return false;
    }
};

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n, k;
    scanf("%d%d", &n, &k);

    vector<pii> v(n);
    forn(i, n) {
        scanf("%d%d", &v[i].first, &v[i].second);
    }

    vector<event> e;
    forn(i, n) {
        e.pb({v[i].first, 'o'});
        e.pb({v[i].second, 'c'});
    }

    sort(all(e));

    int balance = 0;
    vector<pii> ans;
    int curr;

    forn(i, 2 * n) {
        if (e[i].c == 'o') {
            ++balance;
            if (balance == k) {
                curr = e[i].x;
            }
            continue;
        }
        --balance;
        if (balance == k - 1) {
            ans.pb(mp(curr, e[i].x));
        }
    }

    printf("%d\n", sz(ans));
    forn(i, sz(ans)) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }

}