#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int n, sol;
vector < pair <pi, int> > v;
vector <pi> r[2];
int lo[MAXN], hi[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int mn = 1e9, mx = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mn = min(mn, max(a, b));
        mx = max(mx, min(a, b));
        v.push_back({{min(a, b), max(a, b)}, (a > b)});
    }
    if (mn <= mx) {
        cout << "-1";
        return 0;
    }
    sort(v.begin(), v.end());
    int p = 0;
    for (int i = 0; i < v.size(); i++) {
        int x = v[i].first.first;
        int y = v[i].first.second;
        int col = v[i].second;
        if (r[0].empty() || r[0].back().first > y) {
            r[0].push_back({y, col});
        } else if (r[1].empty() || r[1].back().first > y) {
            int ind = r[1].size();
            while (p < r[0].size() && r[0][p].first > y) p++;
            if (p < r[0].size()) {
                lo[ind] = p;
                hi[ind] = (int) r[0].size() - 1;
            } else {
                lo[ind] = hi[ind] = -1;
            }
            r[1].push_back({y, col});
        } else {
            cout << "-1";
            return 0;
        }
    }
    for (int i = 0; i < r[1].size(); i++) {
        int lim = i;
        for (int j = i + 1; j < r[1].size(); j++) {
            if (hi[j - 1] < lo[j]) break;
            lim = j;
        }
        int siz = 0, cnt = 0;
        for (int j = i; j <= lim; j++) {
            siz++;
            if (r[1][j].second == 1) cnt++;
        }
        for (int j = lo[i]; j <= hi[lim]; j++) {
            siz++;
            if (r[0][j].second == 0) cnt++;
        }
        sol += min(cnt, siz - cnt);
        i = lim;
    }
    cout << sol;
    return 0;
}