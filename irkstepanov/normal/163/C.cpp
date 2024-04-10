#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

struct event {
    ll pos;
    char type;
    bool operator<(const event& other) const {
        if (pos != other.pos) {
            return pos < other.pos;
        }
        if (type != other.type) {
            return type == '-';
        }
        return false;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    ll l, v1, v2;
    cin >> n >> l >> v1 >> v2;

    vector<event> events;

    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        if (a * (v1 + v2) >= l * v2) {
            events.pb({(l * 2 - a) * (v1 + v2), '+'});
            events.pb({l * 2 * (v1 + v2) + l * v2 - a * (v1 + v2), '-'});
        } else {
            events.pb({0, '+'});
            events.pb({(l * v2) - a * (v1 + v2), '-'});

            events.pb({(l * 2 - a) * (v1 + v2), '+'});
            events.pb({(l * 2) * (v1 + v2), '-'});
        }
    }

    sort(all(events));
    vector<ld> ans(n + 1);
    ll pr = 0;
    int cnt = 0;
    ld den = ld(l * 2) * (v1 + v2);
    for (event& e : events) {
        if (e.pos == pr) {
            if (e.type == '+') {
                ++cnt;
            } else {
                --cnt;
            }
            continue;
        }
        ll d = e.pos - pr;
        ans[cnt] += ld(d) / den;
        pr = e.pos;
        if (e.type == '+') {
            ++cnt;
        } else {
            --cnt;
        }
    }
    ll d = (l * 2) * (v1 + v2) - pr;
    ans[cnt] += ld(d) / den;

    cout.precision(20);
    cout << fixed;
    for (int i = 0; i <= n; ++i) {
        cout << ans[i] << "\n";
    }

}