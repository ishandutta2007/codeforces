#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<pair<ll, ll>> q;
    ll diff = 0;
    ll n, h;
    cin >> n >> h;
    ll lasty = -1;
    ll out = 0;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        if (lasty == -1) {
            q.push(mp(h, x));
        } else {
            diff += x-lasty;
            while ((!q.empty()) && q.front().first <= diff) {
                ll travelled = (x - (diff-q.front().first)) - q.front().second;
                out = max(out, travelled);
                q.pop();
            }
            q.push(mp(h+diff, x));
        }
        lasty = y;
    }
    while (!q.empty()) {
        //cout << diff << ' ' << lasty << ' ' << q.front().first << ' ' << q.front().second << endl;
        ll travelled = (lasty + q.front().first - diff) - q.front().second;
        out = max(out, travelled);
        q.pop();
    }
    cout << out << endl;
}