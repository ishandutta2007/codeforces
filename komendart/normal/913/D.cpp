#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

int n, T;

int solve(vector< tuple<int, int, int> > arr) {
    set< pair<int, int>, greater<pair<int, int> > > d;
    int sum = 0;
    int best = -1;
    int step = -1;
    for (auto it: arr) {
        int a, t, id;
        tie(a, t, id) = it;
        sum += t;
        d.insert({t, id});
        while (sz(d) > a || sum > T) {
            sum -= d.begin()->first;
            d.erase(d.begin());
        }
        if (sz(d) > best) {
            best = sz(d);
            step = id;
        }
    }
    return step;
}

void restore(vector< tuple<int, int, int> > arr, int beststep) {
    set< pair<int, int>, greater<pair<int, int> > > d;
    int sum = 0;
    for (auto it: arr) {
        int a, t, id;
        tie(a, t, id) = it;
        sum += t;
        d.insert({t, id});
        while (sz(d) > a || sum > T) {
            sum -= d.begin()->first;
            d.erase(d.begin());
        }
        if (id == beststep) {
            cout << sz(d) << '\n';
            cout << sz(d) << '\n';
            for (auto i: d) {
                cout << i.second << ' ';
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> T;
    vector< tuple<int, int, int> > arr(n);
    for (int i = 0; i < n; ++i) {
        int a, t;
        cin >> a >> t;
        arr[i] = make_tuple(a, t, i + 1);
    }
    sort(arr.rbegin(), arr.rend());
    int step = solve(arr);
    restore(arr, step);

}