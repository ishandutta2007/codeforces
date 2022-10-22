#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <tuple>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, madd = 0;
    int maxVal = -1;
    int ourVal = 0;
    bool isFullZero = true;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of in f
    Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            maxVal = max(l->maxVal, r->maxVal);

        }
        else maxVal = v[lo];
    }

    int query(int L, int R, bool print = false) {
        if (print) {
            cout << L << " " << R << " " << lo << " " << hi << " " << maxVal << "\n";
        }
        if (R <= lo || hi <= L) return -1;
        if (L <= lo && hi <= R) return maxVal;
        push();
        return max(l->query(L, R, print), r->query(L, R, print));
    }

    int findMaxPos() {
        if (hi == lo + 1) {
            if (ourVal > 0) {
                return lo;
            } else {
                return -1;
            }
        }

        if (!r->isFullZero) {
            return r->findMaxPos();
        } else {
            return l->findMaxPos();
        }
    }

    int findOur(int i) {
        if (i < lo || hi <= i) return -1;
        if (hi == lo + 1) {
            return ourVal;
        }
        int mid = lo + (hi - lo) / 2;
        if (i < mid) return l->findOur(i);
        else return r->findOur(i);
    }

    void addOur(int i, int x) {
        if (i < lo || hi <= i) return;
        if (hi == lo + 1) {
            ourVal += x;
            if (ourVal == 0) isFullZero = true;
            else isFullZero = false;
            return;
        }
        int mid = lo + (hi - lo) / 2;
        if (i < mid) {
            l->addOur(i, x);
        } else {
            r->addOur(i, x);
        }
        isFullZero = (l->isFullZero && r->isFullZero);
    }

    void add(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            madd += x;
            maxVal += x;
        }
        else {
            push();
            l->add(L, R, x);
            r->add(L, R, x);
            maxVal = max(l->maxVal, r->maxVal);
        }
    }

    void push() {
        if (madd != 0) {
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
        }
    }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    k--;
    vector<unordered_set<int>> filled(n, unordered_set<int>());
    vector<int> initialValues(n + n - 1);
    for (int i = 0; i < n + n - 1; i++) {
        initialValues[i] = i;
    }
    Node* v = new Node(initialValues, 0, n + n - 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        int pos = y + max(k - x, x - k);
        int toAdd = 1;
        if (filled[x].find(y) == filled[x].end()) {
            filled[x].insert(y);
        } else {
            toAdd = -1;
            filled[x].erase(y);
        }
        v->add(0, pos + 1, toAdd);
        v->addOur(pos, toAdd);
        int maxPos = v->findMaxPos();
        if (maxPos == -1) {
            cout << "0\n";
        } else {
            int res = v->query(0, maxPos + 1);
            cout << max(res - n, 0) << "\n";
        }
    }
}