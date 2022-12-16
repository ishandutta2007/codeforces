#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

#define pb push_back
#define mp make_pair

#define MAXN 200'010

struct RageTree {
	ll n;
    ll t[4*MAXN];
    bool marked[4*MAXN];
    ll action[4*MAXN];
    ll numzeroes[4*MAXN];

    ll combine(ll x, ll y) {
        return x + y;
    }

    void init(ll N) { // all zeroes
        n = N;
        memset(t, 0, sizeof t);
        memset(marked, false, sizeof marked);
        build(1, 0, n - 1);
    }

    void build(ll v, ll tl, ll tr) {
        if (tl == tr) {
            // we are at a leaf
            t[v] = 0;
            numzeroes[v] = 1;
        } else {
            ll tm = (tl + tr) / 2;
            build(v*2, tl, tm);
            build(v*2+1, tm+1, tr);
            t[v] = combine(t[v*2], t[v*2+1]);
            numzeroes[v] = numzeroes[v*2] + numzeroes[v*2+1];
        }
    }

    void turnOff(ll pos, ll v = 1, ll tl = 0, ll tr = -1) {
        if (tr == -1) tr = n-1;
        pushAction(v, tl, tr);
        if (tl == tr) {
            t[v] = 0;
            numzeroes[v] = 1;
        } else {
            ll tm = (tl + tr) / 2;
            if (pos <= tm) {
                turnOff(pos, v*2, tl, tm);
            } else {
                turnOff(pos, v*2+1, tm+1, tr);
            }
            t[v] = t[v*2] + t[v*2+1];
            numzeroes[v] = numzeroes[v*2] + numzeroes[v*2+1];
        }
    }

    void turnOn(ll pos, ll val, ll v = 1, ll tl = 0, ll tr = -1) {
        if (tr == -1) tr = n-1;
        pushAction(v, tl, tr);
        if (tl == tr) {
            t[v] = val;
            numzeroes[v] = 0;
        } else {
            ll tm = (tl + tr) / 2;
            if (pos <= tm) {
                turnOn(pos, val, v*2, tl, tm);
            } else {
                turnOn(pos, val, v*2+1, tm+1, tr);
            }
            t[v] = t[v*2] + t[v*2+1];
            numzeroes[v] = numzeroes[v*2] + numzeroes[v*2+1];
        }
    }

    void pushAction(ll v, ll tl, ll tr) {
        //cout << "pushing at " << v << endl;
        if (!marked[v]) return;
        marked[v] = false;
        if (tl == tr) return; // at leaf

        // action is to add action[v] to everything underneath
        ll tm = (tl + tr) / 2;
        t[v*2] += action[v]*(tm+1-tl - numzeroes[v*2]);
        t[v*2+1] += action[v]*(tr-tm - numzeroes[v*2+1]);
        marked[v*2] = true;
        marked[v*2+1] = true;
        action[v*2] += action[v];
        action[v*2+1] += action[v];
        action[v] = 0;
    }

    void update(ll l, ll r, ll new_val, ll v = 1, ll tl = 0, ll tr = -1) {
        if (l < 0) l = 0;
        if (r >= n) r = n-1;
        if (tr == -1) tr = n - 1;

        if (l > r) {
            return;
        }

        if (tl == l && tr == r) {
            // exactly this vertex
            t[v] += new_val*(r-l+1 - numzeroes[v]);
            marked[v] = true;
            action[v] += new_val;
        } else {
            pushAction(v, tl, tr);
            ll tm = (tl + tr) / 2;
            update(l, min(r, tm), new_val, v*2, tl, tm);
            update(max(l, tm+1), r, new_val, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }

    ll sum(ll l, ll r, ll v = 1, ll tl = 0, ll tr = -1) {
        if (l < 0) l = 0;
        if (r >= n) r = n-1;
        if (tr == -1) tr = n - 1;
        if (l > r) {
            return 0; // nothing to get
        }
        if (l == tl && r == tr) {
            return t[v]; // we're exactly this node
        }
        ll tm = (tl + tr) / 2;
        pushAction(v, tl, tr);
        return sum(l, min(r, tm), v*2, tl, tm) + sum(max(l, tm+1), r, v*2+1, tm+1, tr);
    }

    void prllStuff() {
        for (ll i = 0; i < 4*MAXN; i++) cout << t[i] << ' ';
        cout << endl;
    }
};

struct Tree {
	typedef ll T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a + b; } // (any associative fn)
	vector<T> s; ll n;
	Tree(ll n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(ll pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(ll b, ll e) { // query [b, e)
        if (b < 0) b = 0;
        if (e > n) e = n;
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

RageTree rt;

Tree rt2(200'010);

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll q, d;
    cin >> q >> d;
    ll out = 0;

    rt.init(200'010);
    set<ll> active;
    while (q--) {
        ll pos;
        cin >> pos;
        if (active.count(pos) == 0) {
            // add poll
            ll numright = rt2.query(pos, pos+d+1);
            if (numright >= 2) {
                out += (numright * (numright-1)) / 2;
            }

            ll numleft = rt.sum(pos-d, pos);
            out += numleft;
            rt.update(pos-d, pos, 1);
            



            rt.turnOn(pos, numright);
            rt2.update(pos, 1);
            active.insert(pos);
        } else {
            // remove poll
            ll numright = rt2.query(pos+1, pos+d+1);
            //cout << "to right " << numright << endl;
            if (numright >= 2) {
                out -= (numright * (numright-1)) / 2;
            }

            rt.update(pos-d, pos-1, -1);
            ll numleft = rt.sum(pos-d, pos-1);
            //cout << "to left " << numleft << endl;
            out -= numleft;
            
            



            rt.turnOff(pos);
            rt2.update(pos, 0);
            active.erase(pos);
        }
        cout << out << '\n';
    }





    /*set<ll> active; // stores negated
    while (q--) {
        ll pos;
        cin >> pos;

        if (rt.query(pos, pos+1) == 0) {
            // add poll

            ll toright = rt.query(pos, pos+d+1);
            out += max(0, toright-1);

            ll toleft = rt.query(max(0, pos-d), pos+1);
            if (toleft > 0) {
                out += toleft-1;

                // maybe add another
                auto it = active.lower_bound(-1*pos);

                ll pos2 = -1*(*it);
                ll pos2right = rt.query(pos2+1, pos2+d+1);
                if (pos2right != 0) out++; // we win!

            }

            active.insert(-1*pos);
            rt.update(pos, 1);

        } else {
            // remove poll

        }
        cout << out << '\n';
    }*/
}