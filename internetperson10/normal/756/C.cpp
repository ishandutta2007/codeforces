#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct SegTree {
    int lx, rx;
    int valMinus = 0, valPlus = 0; // Each node has a bunch of pops left, and pushes right
    int val = -1;
    SegTree *ls = nullptr, *rs = nullptr;
    SegTree(int l, int r) {
        lx = l;
        rx = r;
        if(rx - lx > 1) {
            int mid = (lx + rx) / 2;
            ls = new SegTree(lx, mid);
            rs = new SegTree(mid, rx);
        }
    }
    ~SegTree() {
        delete ls;
        delete rs;
    }
    void push(int i, int v) {
        if(rx <= i || i+1 <= lx) return;
        if(i <= lx && rx <= i+1) {
            val = v;
            valPlus++;
            return;
        }
        ls->push(i, v);
        rs->push(i, v);
        valMinus = ls->valMinus;
        valPlus = rs->valPlus;
        int g = ls->valPlus - rs->valMinus;
        if(g > 0) valPlus += g;
        else valMinus -= g;
    }
    void pop(int i) {
        if(rx <= i || i+1 <= lx) return;
        if(i <= lx && rx <= i+1) {
            valMinus++;
            return;
        }
        ls->pop(i);
        rs->pop(i);
        valMinus = ls->valMinus;
        valPlus = rs->valPlus;
        int g = ls->valPlus - rs->valMinus;
        if(g > 0) valPlus += g;
        else valMinus -= g;
    }
    int getTop(int x) { // Find the xth one in the stack!
        if(val != -1) {
            assert(x == 0);
            return val;
        }
        if(valPlus <= x) return -1;
        if(ls == nullptr) assert(false); // this shouldn't happen :(
        if(rs->valPlus > x) return rs->getTop(x);
        return ls->getTop(x - rs->valPlus + rs->valMinus);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int g = 1;
    while(g < n) g *= 2;
    SegTree st(0, g);
    while(n--) {
        int p, t;
        cin >> p >> t;
        p--;
        if(t == 0) {
            st.pop(p);
        }
        else {
            int val;
            cin >> val;
            st.push(p, val);
        }
        cout << st.getTop(0) << '\n';
    }
}