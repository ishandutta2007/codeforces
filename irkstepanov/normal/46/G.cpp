#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct pt {
    ll x, y;
    pt operator+(const pt& other) const {
        return {x + other.x, y + other.y};
    }
    int halfplane() const {
        if (y > 0) {
            return 0;
        }
        if (y == 0 && x > 0) {
            return 0;
        }
        return 1;
    }
};

ll cross(const pt& p, const pt& q) {
    return p.x * q.y - p.y * q.x;
}

bool operator<(const pt& p, const pt& q) {
    if (p.halfplane() != q.halfplane()) {
        return p.halfplane() < q.halfplane();
    }
    return cross(p, q) > 0;
}

struct datum {
    ll c;
    ll x, y;
    bool operator<(const datum& other) const {
        return c < other.c;
    }
    bool operator==(const datum& other) const {
        return c == other.c;
    }
};

ll len2(const pt& p) {
    return p.x * p.x + p.y * p.y;
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<datum> vct;
    for (ll d = 1; sz(vct) <= n + 30; ++d) {
        for (ll x = 0; x * x <= d; ++x) {
            ll y = sqrt(d - x * x);
            if (x * x + y * y == d) {
                vct.pb({d, x, y});
                break;
            }
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (vct[i].c & 1) {
            ++cnt;
        }
    }
    if (cnt & 1) {
        vector<datum> res;
        vector<int> rem;
        if (vct[n].c & 1) {
            rem = {1, 0};
        } else {
            rem = {0, 1};
        }
        for (int r : rem) {
            for (int i = 0; i <= n; ++i) {
                if (vct[i].c % 2 == r && sz(res) < n) {
                    res.pb(vct[i]);
                }
            }
        }
        vct.swap(res);
    } else {
        while (sz(vct) > n) {
            vct.pop_back();
        }
    }
    sort(all(vct));

    assert(sz(vct) == n);
    cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (vct[i].c & 1) {
            ++cnt;
        }
    }
    assert(cnt % 2 == 0);

    const ll inf = 1e9;

    pt curr = {0, 0};
    reverse(all(vct));
    vector<pt> dir;
    vector<bool> used(n, false);
    for (int i = 0; i < n; ++i) {
        pt opt = {inf, inf};
        {
            ll x = vct[i].x, y = vct[i].y;
            for (int sw = 0; sw < 2; ++sw) {
                for (int a = -1; a <= 1; a += 2) {
                    for (int b = -1; b <= 1; b += 2) {
                        pt p = {a * x, b * y};
                        if (sw) {
                            swap(p.x, p.y);
                        }
                        if (len2(curr + p) < len2(curr + opt)) {
                            opt = p;
                        }
                    }
                }
            }
            dir.pb(opt);
            curr = curr + opt;
        }
        
    }
    sort(all(dir));
    //cout << curr.x << " " << curr.y << endl;

    curr = {0, 0};
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << curr.x << " " << curr.y << "\n";
        curr = curr + dir[i];
    }

}