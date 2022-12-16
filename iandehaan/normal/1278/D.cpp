#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair
#define MAXN 500010
int par[MAXN];
int getPar(int x) {
    if (par[x] == x) return x;
    return par[x] = getPar(par[x]);
}

void Union(int x, int y) {
    if (getPar(x) == getPar(y)) return;
    par[getPar(x)] = getPar(y);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < MAXN; i++) par[i] = i;

    int n;
    cin >> n;
    pair<int, int> a[n];
    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        events.pb(mp(a[i].first, i));
        events.pb(mp(a[i].second, i));
    }
    sort(all(events));
    set<pair<int, int>> active;
    int numedges = 0;
    for (pair<int, int> event : events) {
        int pos = event.first;
        int ind = event.second;
        if (pos == a[ind].first) {
            // start event
            active.insert(mp(pos, ind));
        } else {
            // end event
            int startpos = a[ind].first;
            active.erase(mp(startpos, ind));

            for (auto iter = active.rbegin(); iter != active.rend(); iter++) {
                int ind2 = iter->second;
                if (a[ind2].first > startpos) {
                    numedges++;
                    if (getPar(ind) == getPar(ind2)) {
                        cout << "NO" << endl;
                        return 0;
                    }
                    Union(ind, ind2);
                } else {
                    break;
                }
            }
        }
    }

    if (numedges == n-1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}