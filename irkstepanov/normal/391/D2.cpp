#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

struct segment
{
    int x, y, l;
};

struct event
{
    int x, type, id;
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

vector<int> t;

void update(int pos, int val, int n)
{
    pos += n;
    t[pos] = val;
    for (pos >>= 1; pos; pos >>= 1) {
        t[pos] = t[pos * 2] + t[pos * 2 + 1];
    }
}

int get(int l, int r, int n)
{
    int ans = 0;
    for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
        if (l & 1) {
            ans += t[l];
        }
        if (!(r & 1)) {
            ans += t[r];
        }
    }
    return ans;
}

bool check(vector<segment>& hor, vector<segment>& ver)
{
    int n = sz(hor);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = hor[i].y;
    }
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    int N = sz(v);
    t.assign(2 * N, 0);
    vector<event> events;
    for (int i = 0; i < n; ++i) {
        hor[i].y = lower_bound(all(v), hor[i].y) - v.begin();
        event e = {hor[i].x, 0, i};
        events.pb(e);
        e = {hor[i].x + hor[i].l, 2, i};
        events.pb(e);
    }
    for (int i = 0; i < sz(ver); ++i) {
        event e = {ver[i].x, 1, i};
        events.pb(e);
    }
    sort(all(events));
    for (event &e : events) {
        if (e.type == 0) {
            update(hor[e.id].y, 1, N);
        } else if (e.type == 2) {
            update(hor[e.id].y, 0, N);
        } else {
            int l = lower_bound(all(v), ver[e.id].y) - v.begin();
            int r = upper_bound(all(v), ver[e.id].y + ver[e.id].l) - v.begin() - 1;
            if (l == N || l > r) {
                continue;
            }
            int ans = get(l, r, N);
            if (ans) {
                return true;
            }
        }
    }
    return false;
}

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");

    int n, m;
    cin >> n >> m;

    vector<segment> hor(m), ver(n);
    for (int i = 0; i < n; ++i) {
        cin >> ver[i].x >> ver[i].y >> ver[i].l;
    }
    for (int i = 0; i < m; ++i) {
        cin >> hor[i].x >> hor[i].y >> hor[i].l;
    }

    int l = 0, r = 1e8 + 100;
    while (l != r - 1) {
        int middle = (l + r) >> 1;
        vector<segment> v, h;
        for (int i = 0; i < n; ++i) {
            if (ver[i].l >= 2 * middle) {
                segment tmp = {ver[i].x, ver[i].y + middle, ver[i].l - 2 * middle};
                v.pb(tmp);
                //cout << "V" << tmp.x << " " << tmp.y << " " << tmp.l << "\n";
            }
        }
        for (int i = 0; i < m; ++i) {
            if (hor[i].l >= 2 * middle) {
                segment tmp = {hor[i].x + middle, hor[i].y, hor[i].l - 2 * middle};
                h.pb(tmp);
                //cout << "H" << tmp.x << " " << tmp.y << " " << tmp.l << "\n";
            }
        }
        if (check(h, v)) {
            l = middle;
        } else {
            r = middle;
        }
    }

    cout << l << "\n";

}