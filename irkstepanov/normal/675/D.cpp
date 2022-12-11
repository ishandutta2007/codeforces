#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pll;

const int inf = 1e9 + 10;

struct seg
{
    int l, r;
    int root;
    bool operator<(const seg& other) const
    {
        return l < other.l;
    }
};

int main()
{

    //freopen("input.txt", "r", stdin);

    int n;
    ios_base::sync_with_stdio(false);
    cin >> n;

    set<seg> s;
    int a;
    cin >> a;
    s.insert({-inf, a, 2});
    s.insert({a, inf, 1});

    for (int i = 0; i < n - 1; ++i) {
        cin >> a;
        set<seg>::iterator it = s.lower_bound({a, a, 0});
        --it;
        if (it->l == -inf) {
            int x = it->r;
            cout << x << " ";
            s.erase(it);
            s.insert({a, x, 2});
            s.insert({-inf, a, 2});
            continue;
        }
        if (it->r == inf) {
            int x = it->l;
            cout << x << " ";
            s.erase(it);
            s.insert({x, a, 1});
            s.insert({a, inf, 1});
            continue;
        }
        if (it->root == 1) {
            int x = it->l, y = it->r;
            cout << y << " ";
            s.erase(it);
            s.insert({x, a, 1});
            s.insert({a, y, 2});
        } else {
            int x = it->l, y = it->r;
            cout << x << " ";
            s.erase(it);
            s.insert({x, a, 1});
            s.insert({a, y, 2});
        }
    }

}