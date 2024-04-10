#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct SegTreeZero {
    int lx, rx;
    bool zero = false;
    SegTreeZero *ls = nullptr, *rs;
    SegTreeZero(int l, int r) {
        lx = l;
        rx = r;
        if(r - l > 1) {
            int mid = (l + r) / 2;
            ls = new SegTreeZero(l, mid);
            rs = new SegTreeZero(mid, r);
        }
    }
    ~SegTreeZero() {
        if(ls != nullptr) {
            delete ls;
            delete rs;
        }
    }
    void prop() {
        if(ls != nullptr) {
            if(!zero) return;
            ls->zero = true;
            rs->zero = true;
        }
    }
    void makeZero(int l, int r) {
        prop();
        if(zero) return;
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r) {
            zero = true;
            return;
        }
        ls->makeZero(l, r);
        rs->makeZero(l, r);
        if(ls->zero && rs->zero) zero = true;
    }
    bool allZero(int l, int r) {
        prop();
        if(rx <= l || r <= lx) return true;
        if(l <= lx && rx <= r) return zero;
        return (ls->allZero(l, r)) && (rs->allZero(l, r));
    }
};

const ll BIG = 1234567890;

struct SegTreeMin { // Solving the problem: given a set of intervals, does this interval "host" any of them?
    int lx, rx;
    ll val = BIG, lazy = BIG;
    SegTreeMin *ls = nullptr, *rs;
    SegTreeMin(int l, int r) {
        lx = l;
        rx = r;
        if(r - l > 1) {
            int mid = (l + r) / 2;
            ls = new SegTreeMin(l, mid);
            rs = new SegTreeMin(mid, r);
        }
    }
    ~SegTreeMin() {
        if(ls != nullptr) {
            delete ls;
            delete rs;
        }
    }
    void prop() {
        if(ls != nullptr) {
            ls->val = min(ls->val, lazy);
            rs->val = min(rs->val, lazy);
            ls->lazy = min(ls->lazy, lazy);
            rs->lazy = min(rs->lazy, lazy);
            lazy = BIG;
        }
    }
    void setMin(int l, int r, ll x) {
        prop();
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r) {
            lazy = min(lazy, x);
            val = min(val, x); 
            return;
        }
        ls->setMin(l, r, x);
        rs->setMin(l, r, x);
        val = min(ls->val, rs->val);
    }
    int getVal(int x) {
        prop();
        if(rx <= x || x+1 <= lx) return BIG;
        if(x == lx && x+1 == rx) return val;
        return min(ls->getVal(x), rs->getVal(x));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    int siz = 1;
    while(siz <= n+5) siz *= 2;
    SegTreeZero stz = SegTreeZero(0, siz);
    SegTreeMin stm = SegTreeMin(0, siz);
    while(q--) {
        int t;
        cin >> t;
        if(t == 0) {
            int l, r, x;
            cin >> l >> r >> x;
            if(x == 0) {
                stz.makeZero(l, r+1);
            }
            else {
                stm.setMin(0, l+1, r);
            }
        }
        else {
            int x;
            cin >> x;
            if(stz.allZero(x, x+1)) {
                cout << "NO\n";
                continue;
            }
            int leftZero, rightZero; 
            int l = -1, r = x;
            while(l != r - 1) {
                int mid = (l + r) / 2;
                if(stz.allZero(mid, x)) r = mid;
                else l = mid;
            }
            leftZero = r;
            l = x; r = n+1;
            while(l != r - 1) {
                int mid = (l + r) / 2;
                if(stz.allZero(x+1, mid+1)) l = mid;
                else r = mid;
            }
            rightZero = l;
            assert(stm.getVal(x+1) > rightZero);
            if(stm.getVal(leftZero) <= rightZero) cout << "YES\n";
            else cout << "N/A\n";
        }
    }
}