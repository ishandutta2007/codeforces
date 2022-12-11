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
typedef long double ld;
typedef pair<ll, ll> pll;

const ld pi = 4 * atan(1.0);

struct pt {
    ld x, y;
    pt() {}
    pt(ld x, ld y) : x(x), y(y) {}
    pt operator-(const pt& other) const {
        return {x - other.x, y - other.y};
    }
    pt operator+(const pt& other) const {
        return {x + other.x, y + other.y};
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
    cin >> n;

    vector<pt> p;
    ld R = 5.0 / sin(pi / 5);
    pt shift = {0, 0};
    vector<vector<int> > st;
    for (int i = 0; i < n; ++i) {
        pt d = {0, 0};
        st.pb(vector<int>());
        for (int j = 0; j < 5; ++j) {
            ld a = 2 * j * pi / 5;
            pt q = {R * cos(a), R * sin(a)};
            if (j == 2) {
                d = d - q;
            }
            if (j == 4) {
                d = d + q;
            }
            if (i > 0 && j == 2) {
                st.back().pb(sz(p) - 3);
                continue;
            }
            st.back().pb(sz(p));
            p.pb(q + shift);
        }
        shift = shift + d;
    }

    cout << sz(p) << "\n";
    cout << fixed;
    cout.precision(20);
    for (int i = 0; i < sz(p); ++i) {
        cout << p[i].x << " " << p[i].y << "\n";
    }

    for (int i = 0; i < n; ++i) {
        for (int x : st[i]) {
            cout << x + 1 << " ";
        }
        cout << "\n";
    }

    cout << "3 ";
    for (int i = 4; i < sz(p); i += 4) {
        cout << i + 1 << " ";
    }
    for (int i = n - 1; i >= 0; --i) {
        cout << st[i][1] + 1 << " " << st[i][3] + 1 << " " << st[i][0] + 1 << " " << st[i][2] + 1 << " ";
    }
    cout << "\n";

}