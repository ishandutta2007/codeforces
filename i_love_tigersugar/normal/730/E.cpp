#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); i++)
typedef pair<int, int> ii;
#define X first
#define Y second
typedef long long ll;

const int N = 128;

int n;
vector<ii> Inc, Dec;
set<int> s;

int main() {
    //freopen("input.txt", "r", stdin);

    cin >> n;
    rep(i, n) {
        int a, d;
        cin >> a >> d;
        s.insert(a * 1000 - i);
        if (d >= 0) Inc.push_back({a * 1000 - i, (a+d) * 1000 - i});
        else        Dec.push_back({a * 1000 - i, (a+d) * 1000 - i});
    }
    sort(Inc.begin(), Inc.end());
    sort(Dec.begin(), Dec.end()); reverse(Dec.begin(), Dec.end());

    vector<ii> all;
    for (auto v : Inc) all.push_back(v);
    for (auto v : Dec) all.push_back(v);

    int ans = 0;
    for (auto v : all) {
        for (auto x : s) if (1LL*(x - v.X) * (x - v.Y) < 0) ans++;
        s.erase(v.X);
        s.insert(v.Y);
    }
    cout << ans << endl;
    return 0;
}