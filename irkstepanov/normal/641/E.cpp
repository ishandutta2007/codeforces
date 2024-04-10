#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

struct query
{
    int type;
    int time;
    int val;
};

vector<query> queries;
vector<int> times, vals;
int c;
vector<vector<int> > interesting;
vector<vector<int> > t;

void update(int tree, int l, int r, int val)
{
    for (l += sz(t[tree]) / 2, r += sz(t[tree]) / 2; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
        if (l & 1) {
            t[tree][l] += val;
        }
        if (!(r & 1)) {
            t[tree][r] += val;
        }
    }
}

int get(int tree, int pos)
{
    pos += sz(t[tree]) / 2;
    int ans = t[tree][pos];
    for (pos >>= 1; pos; pos >>= 1) {
        ans += t[tree][pos];
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    queries.resize(n);
    for (int i = 0; i < n; ++i) {
        int type, timer, val;
        cin >> type >> timer >> val;
        queries[i] = {type, timer, val};
        times.pb(timer);
        vals.pb(val);
    }

    sort(all(times));
    sort(all(vals));
    vals.resize(unique(all(vals)) - vals.begin());
    c = sz(vals);
    for (int i = 0; i < n; ++i) {
        queries[i].val = lower_bound(all(vals), queries[i].val) - vals.begin();
        queries[i].time = lower_bound(all(times), queries[i].time) - times.begin();
        //cout << queries[i].val << " " << queries[i].time << "\n";
    }

    interesting.resize(c);
    for (int i = 0; i < n; ++i) {
        if (queries[i].type == 3) {
            interesting[queries[i].val].pb(queries[i].time);
        }
    }
    t.resize(c);
    for (int i = 0; i < c; ++i) {
        if (!interesting[i].empty()) {
            sort(all(interesting[i]));
            //cout << interesting[i][0] << " " << interesting[i][2] << "\n";
            t[i].resize(2 * sz(interesting[i]));
        }
    }

    for (int i = 0; i < n; ++i) {
        if (queries[i].type == 1) {
            int val = queries[i].val;
            if (interesting[val].empty()) {
                continue;
            }
            int pos = lower_bound(all(interesting[val]), queries[i].time) - interesting[val].begin();
            update(val, pos, sz(t[val]) / 2 - 1, 1);
        } else if (queries[i].type == 2) {
            int val = queries[i].val;
            if (interesting[val].empty()) {
                continue;
            }
            int pos = lower_bound(all(interesting[val]), queries[i].time) - interesting[val].begin();
            update(val, pos, sz(t[val]) / 2 - 1, -1);
        } else {
            int val = queries[i].val;
            int timer = lower_bound(all(interesting[val]), queries[i].time) - interesting[val].begin();
            cout << get(val, timer) << "\n";
        }
    }

}