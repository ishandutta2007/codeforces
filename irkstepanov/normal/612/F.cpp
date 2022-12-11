#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;

const int inf = static_cast<int>(1e9);

struct data
{
    int val;
    vector<int> steps;
};

int n, s;

int cw(int from, int to)
{
    return (to - from + n) % n;
}

int ccw(int from, int to)
{
    return (from - to + n) % n;
}

int f(int x, int y)
{
    int ans1 = cw(x, y);
    int ans2 = ccw(x, y);
    if (ans1 < ans2) {
        return ans1;
    } else {
        return -ans2;
    }
}

int prev(int x, int p)
{
    --x;
    if (x == -1) {
        x += p;
    }
    return x;
}

int next(int x, int p)
{
    ++x;
    if (x == p) {
        x = 0;
    }
    return x;
}

int visited = 0;
vector<char> used;

void out(int x)
{
    ++visited;
    if (x >= 0) {
        cout << '+';
    }
    cout << x << "\n";
}

vector<int> a;

void go(int x, int val)
{
    int dist = 0;
    for (int i = 0; i < abs(x); ++i) {
        if (x < 0) {
            --dist;
            s = prev(s, n);
        } else {
            ++dist;
            s = next(s, n);
        }
        if (!used[s] && val == a[s]) {
            out(dist);
            used[s] = true;
            dist = 0;
        }
    }
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("output.txt", "w", stdout);

    cin >> n >> s;
    --s;
    a.resize(n);
    vector<int> sorted;

    forn(i, n) {
        cin >> a[i];
    }
    sorted = a;
    sort(all(sorted));
    sorted.resize(unique(all(sorted)) - sorted.begin());
    int k = sz(sorted);
    forn(i, n) {
        a[i] = lower_bound(all(sorted), a[i]) - sorted.begin();
    }

    vector<vector<int> > pos(k);
    forn(i, n) {
        pos[a[i]].pb(i);
    }

    vector<data> dp1(n), dp2(n);

    for (int color = k - 1; color >= 0; --color) {
        if (color == k - 1) {
            for (int x : pos[color]) {
                dp2[x].val = 0;
            }
        } else {
            for (int x : pos[color]) {
                dp2[x].val = inf;
                for (int y : pos[color + 1]) {
                    int d = f(x, y);
                    if (dp2[x].val > dp1[y].val + abs(d)) {
                        dp2[x].val = dp1[y].val + abs(d);
                        dp2[x].steps = {d};
                    }
                }
            }
        }
        if (sz(pos[color]) == 1) {
            int x = pos[color][0];
            dp1[x].val = dp2[x].val;
        } else {
            int p = sz(pos[color]);
            for (int i = 0; i < p; ++i) {
                int x = pos[color][i];
                dp1[x].val = cw(x, pos[color][prev(i, p)]) + dp2[pos[color][prev(i, p)]].val;
                dp1[x].steps = {cw(x, pos[color][prev(i, p)])};
                int t = ccw(x, pos[color][next(i, p)]) + dp2[pos[color][next(i, p)]].val;
                if (dp1[x].val > t) {
                    dp1[x].val = t;
                    dp1[x].steps = {-ccw(x, pos[color][next(i, p)])};
                }
                /*if (p == 2) {
                    continue;
                }
                for (int j = 0; j < p; ++j) {
                    if (i == j) {
                        continue;
                    }
                    int y = pos[color][j];
                    if (next(j, p) != i) {
                        t = 2 * cw(x, y) + ccw(x, pos[color][next(j, p)]) + dp2[pos[color][next(j, p)]].val;
                        if (t < dp1[x].val) {
                            dp1[x].val = t;
                            dp1[x].steps = {cw(x, y), -cw(x, y) - ccw(x, pos[color][next(j, p)])};
                        }
                    }
                    if (prev(j, p) != i) {
                        t = 2 * ccw(x, y) + cw(x, pos[color][prev(j, p)]) + dp2[pos[color][prev(j, p)]].val;
                        if (t < dp1[x].val) {
                            dp1[x].val = t;
                            dp1[x].steps = {-ccw(x, y), ccw(x, y) + cw(x, pos[color][prev(j, p)])};
                        }
                    }
                }*/
            }
        }
    }

    int ans = inf;
    int r = 0;
    for (int x : pos[0]) {
        if (ans > abs(f(s, x)) + dp1[x].val) {
            ans = abs(f(s, x)) + dp1[x].val;
            r = f(s, x);
        }
    }
    cout << ans << "\n";
    used.assign(n, false);

    out(r);
    s = (s + r + n) % n;
    used[s] = true;
    int color = 0;

    while (visited != n) {
        for (int d : dp1[s].steps) {
            go(d, color);
        }
        if (!dp2[s].steps.empty()) {
            out(dp2[s].steps[0]);
            s = (s + dp2[s].steps[0] + n) % n;
            used[s] = true;
        }
        ++color;
    }

}