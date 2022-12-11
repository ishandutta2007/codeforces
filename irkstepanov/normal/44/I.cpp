#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

vector<int> cycles[11];

void build(int n) {
    if (n == 1) {
        cycles[n] = {0, 1};
        return;
    }
    build(n - 1);
    for (int x : cycles[n - 1]) {
        cycles[n].pb(x << 1);
    }
    vector<int> t = cycles[n - 1];
    reverse(all(t));
    for (int x : t) {
        cycles[n].pb((x << 1) + 1);
    }
}

void sor(vector<int>& a) {
    sort(all(a), [&] (int x, int y) {
        for (int i = 0; ; ++i) {
            if (bit(x, i)) {
                return true;
            }
            if (bit(y, i)) {
                return false;
            }
        }
        return false;
    });
}

void del(vector<int>& rem, int pos) {
    vector<int> ans = {rem[0]};
    for (int i = 1; i < sz(rem); ++i) {
        int val = rem[i];
        if (bit(val, pos)) {
            val ^= (1 << pos);
        }
        if (val) {
            ans.pb(val);
        }
    }
    sor(ans);
    rem.swap(ans);
}

void shift(vector<int>& a, int p) {
    vector<int> b;
    for (int i = p; i < sz(a); ++i) {
        b.pb(a[i]);
    }
    for (int i = 0; i < p; ++i) {
        b.pb(a[i]);
    }
    a.swap(b);
}

vector<vector<int> > rec(vector<int> a, vector<int> rem) {
    int n = sz(a);
    if (n == 0) {
        return {{}};
    }
    int start = rem[0];
    if (n == 1) {
        return {{1 << a[0]}};
    }
    vector<int> c = cycles[n - 1];
    for (int i = 0; i < sz(c); ++i) {
        c[i] = (c[i] << 1) + 1;
    }
    int s = -1;
    for (int i = 0; i < sz(c); ++i) {
        if (c[i] == start) {
            s = i;
        }
    }
    assert(s != -1);
    shift(c, s);
    vector<vector<int> > ans;
    for (int i = 0; i < sz(c); ++i) {
        /*cout << "N = " << n << " !!!" << i << " " << sz(c) << " " << c[i] << endl;
        for (int z : rem) {
            cout << "!!" << z << " ";
        }
        cout << endl;*/
        vector<int> newId(n, -1);
        vector<int> alive;
        int z = 0;
        //cout << "?" << rem[0] << " " << c[i] << endl;
        assert(rem[0] == c[i]);
        for (int j = 0; j < n; ++j) {
            if (bit(c[i], j)) {
                continue;
            }
            newId[j] = z++;
            alive.pb(j);
        }
        vector<int> tmp;
        for (int j = 1; j < sz(rem); ++j) {
            int val = 0;
            for (int k = 0; k < n; ++k) {
                if (bit(rem[j], k)) {
                    val |= (1 << newId[k]);
                }
            }
            tmp.pb(val);
        }
        vector<vector<int> > vct = rec(alive, tmp);
        /*if (i == 1) {
            cout << "? " << sz(tmp) << " " << tmp[0] << endl;
            cout << "SZ" << sz(vct) << " " << vct[0][0] << endl;
        }*/
        
        for (int j = 0; j < sz(vct); ++j) {
            vector<int> v = {c[i]};
            for (int val : vct[j]) {
                v.pb(val);
            }
            ans.pb(v);
        }
        rem = ans.back();
        if (i + 1 < sz(c)) {
            int pos;
            for (int j = 0; j < n; ++j) {
                if (bit(c[i + 1], j) != bit(c[i], j)) {
                    pos = j;
                }
            }
            if ((c[i + 1] & c[i]) == c[i]) {
                rem[0] = c[i + 1];
                del(rem, pos);
            } else {
                rem[0] = c[i + 1];
                rem.pb(1 << pos);
                sor(rem);
            }
        }
        //cout << "DINE" << endl;
        //cout << "!" << sz(rem) << endl;
    }
    for (int i = 0; i < sz(ans); ++i) {
        for (int j = 0; j < sz(ans[i]); ++j) {
            int val = 0;
            for (int k = 0; k < n; ++k) {
                if (bit(ans[i][j], k)) {
                    val |= (1 << a[k]);
                }
            }
            ans[i][j] = val;
        }
    }
    return ans;
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    build(n);
    vector<int> rem;
    int start = 0;
    vector<int> alive;
    for (int i = 0; i < n; ++i) {
        start |= (1 << i);
        alive.pb(i);
    }
    rem.pb(start);

    vector<vector<int> > ans = rec(alive, rem);
    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i) {
        for (int j = 0; j < sz(ans[i]); ++j) {
            if (j) {
                cout << ',';
            }
            cout << '{';
            bool out = false;
            for (int k = 0; k < n; ++k) {
                if (bit(ans[i][j], k)) {
                    if (out) {
                        cout << ',';
                    }
                    cout << k + 1;
                    
                    out = true;
                }
            }
            cout << '}';
        }
        cout << "\n";
    }

}