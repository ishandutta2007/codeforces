#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto& x : v)
        cin >> x.first >> x.second;
    
    map<int, vector<pair<int, int>>> keys;
    for (auto x : v) {
        keys[max(x.first, x.second)].push_back(x);
    }

    pair<int, int> most_left(0, 0), most_right(0, 0);
    long long dl = 0, dr = 0;

    auto cmp = [](auto a, auto b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    };
    auto dist = [](auto a, auto b) {
        return (long long)(abs(a.first - b.first) + abs(a.second - b.second));
    };
    for (auto [x, v] : keys) {
        sort(v.begin(), v.end(), cmp);

        pair<int, int> nml = v.front(), nmr = v.back();
        long long ndl = std::numeric_limits<long long>::max();
        long long ndr = std::numeric_limits<long long>::max();


        long long d;
        // from l to l to r
        d = dl + (long long)dist(most_left, nml) + dist(nml, nmr);
        if (d < ndr)
            ndr = d;
        // from l to r to l
        d = dl + (long long)dist(most_left, nmr) + dist(nml, nmr);
        if (d < ndl)
            ndl = d;
        // from r to l to r
        d = dr + (long long)dist(most_right, nml) + dist(nml, nmr);
        if (d < ndr)
            ndr = d;
        // from r to r to l
        d = dr + (long long)dist(most_right, nmr) + dist(nml, nmr);
        if (d < ndl)
            ndl = d;
        most_left = nml;
        most_right = nmr;
        dl = ndl;
        dr = ndr;
    }
    cout << min(dl, dr) << endl;
}