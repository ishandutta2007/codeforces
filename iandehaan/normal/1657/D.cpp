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

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n >> c;

    ll bestamt[c+1];
    for (int i = 0; i <= c; i++) bestamt[i] = 0;


    pair<ll, pair<ll, ll>> units[n];
    for (int i = 0; i < n; i++) {
        cin >> units[i].first >> units[i].second.first >> units[i].second.second;
    }
    sort(units, units+n);
    ll currbest = 0;
    for (int i = 0; i < n; i++) {
        currbest = max(currbest, units[i].second.first * units[i].second.second);
        ll stepamt = currbest;
        if (i < n-1 && units[i].first == units[i+1].first) {
            continue;
        } else {
            currbest = 0;
        }

        ll currval = stepamt;

        for (int j = units[i].first; j <= c; j += units[i].first) {
            bestamt[j] = max(bestamt[j], currval);
            currval += stepamt;
        }
    }
    for (int i = 1; i <= c; i++) {
        bestamt[i] = max(bestamt[i], bestamt[i-1]);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        ll dmg, health;
        cin >> dmg >> health;
        ll threshold = dmg*health;
        int hi = c+1;
        int lo = 0;
        while (abs(hi-lo) > 2) {
            int mid = (lo+hi)/2;
            if (bestamt[mid] > threshold) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        int out = -1;
        for (int tst = lo-5; tst <= hi+5; tst++) {
            if (tst < 0 || tst > c) continue;
            if (bestamt[tst] > threshold) {
                out = tst;
                break;
            }
        }

        cout << out << ' ';
    }
    cout << endl;
}