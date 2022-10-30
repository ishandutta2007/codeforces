#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}

int main(){
    iostream_init();
    int n;
    cin >> n;
    vector<pair<int, int>> ps;
    set<pair<int, int>> ps_set;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ps.push_back( make_pair(x, y));
        ps_set.insert(make_pair(x, y));
    }
    vector<pair<int, int>> as;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        as.push_back( make_pair(x, y));
    }
    for (int i = 0; i < n; i++) {
        pair<int, int> t = make_pair(as[0].first + ps[i].first, as[0].second + ps[i].second);
        bool ok = true;
        for (int j = 1; j < n; j++) {
            pair<int, int> y = make_pair(t.first - as[j].first, t.second - as[j].second);
            if (!ps_set.count(y)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << t.first << " " << t.second << endl;
            break;
        }
    }
    return 0;
}