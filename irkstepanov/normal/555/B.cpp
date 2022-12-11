#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

struct segment
{
    ll l, r;
    int id;
    bool operator<(const segment& other) const
    {
        if (r != other.r) {
            return r < other.r;
        }
        if (l != other.r) {
            return l < other.l;
        }
        if (id != other.id) {
            return id < other.id;
        }
        return false;
    }
};

struct event
{
    ll x;
    int type, id;
    bool operator<(const event& other) const
    {
        if (x != other.x) {
            return x < other.x;
        }
        if (type != other.type) {
            return type < other.type;
        }
        if (id != other.id) {
            return id < other.id;
        }
        return false;
    }
};

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("output.txt", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    vector<pll> init(n);

    forn(i, n) {
        scanf("%I64d%I64d", &init[i].first, &init[i].second);
    }

    vector<segment> v(n - 1);
    vector<event> events;
    for (int i = 0; i < n - 1; ++i) {
        v[i] = {init[i + 1].first - init[i].second, init[i + 1].second - init[i].first, i};
        events.pb({v[i].l, -1, i});
        events.pb({v[i].r, 1, i});
    }

    forn(i, m) {
        ll x;
        scanf("%I64d", &x);
        events.pb({x, 0, i});
    }

    sort(all(events));
    set<segment> s;
    vector<int> ans(n - 1);

    for (event e : events) {
        //cout << e.x << " " << e.type << "\n";
        if (e.type == -1) {
            s.insert(v[e.id]);
            continue;
        }
        if (e.type == 1) {
            if (s.count(v[e.id])) {
                printf("No\n");
                return 0;
            }
            continue;
        }
        if (s.empty()) {
            continue;
        }
        set<segment>::iterator it = s.begin();
        ans[it->id] = e.id;
        s.erase(it);
    }

    printf("Yes\n");
    forn(i, n - 1) {
        printf("%d ", ans[i] + 1);
    }

}