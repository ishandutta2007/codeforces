#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

struct Node {
    Node *l = 0, *r = 0;
    const int inf = 100000000;
    int lo, hi, mset = inf, madd = 0, val = -inf;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of in f
    Node(vector<int>& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = l->val + r->val;
        }
        else val = v[lo];
    }
    int query(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return val;
        push();
        return l->query(L, R) + r->query(L, R);
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = x, val = x * (hi - lo), madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = l->val + r->val;
        }
    }
    void add(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != inf) mset += x;
            else madd += x;
            val += x;
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != inf)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
            else if (madd)
                l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
    }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> s(n, 0);
        vector<int> t(n, 0);
        string S, T;
        cin >> S >> T;
        for (int i = 0; i < n; i++) {
            if (S[i] == '1') s[i] = 1;
            if (T[i] == '1') t[i] = 1;
        }

        Node *seg_tree = new Node(t, 0, n);

        vector<int> l(q);
        vector<int> r(q);
        for (int i = 0; i < q; i++) cin >> l[i] >> r[i];

        bool imposs = false;
        for (int i = q - 1; i >= 0; i--) {
            int count = seg_tree->query(l[i] - 1, r[i]);
            // cout << "TTT" << " " << l[i] << " " << r[i] << " " << count << "\n";
            if (2 * count == (r[i] - l[i] + 1)) {
                imposs = true;
                break;
            } else if (2 * count < (r[i] - l[i] + 1)) {
                seg_tree->set(l[i] - 1, r[i], 0);
            } else {
                seg_tree->set(l[i] - 1, r[i], 1);
            }
        }

        if (imposs) {
            cout << "NO\n";
        } else {
            vector<int> st(n, 0);
            for (int i = 0; i < n; i++) {
                st[i] = seg_tree->query(i, i + 1);
            }
            bool equal = true;
            for (int i = 0; i < n; i++) {
                if (s[i] != st[i]) {
                    equal = false;
                    break;
                }

            }


            if (equal) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}