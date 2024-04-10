#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

unordered_map<int, ll> gcdTotal;
unordered_map<int, ll> gcdPrev;
unordered_map<int, int> storeGcd;
map<int, int> storeVals;

vector<int> nums;

struct SegTree {
    int val = 0;
    int lx, rx;
    SegTree *ls = nullptr, *rs = nullptr;
    SegTree(int l, int r) {
        lx = l;
        rx = r;
        int mid = (lx + rx + 1) / 2;
        if(rx - lx > 1) {
            int mid = (lx + rx) / 2;
            ls = new SegTree(lx, mid);
            rs = new SegTree(mid, rx);
            val = __gcd(ls->val, rs->val);
        }
        else {
            val = nums[lx];
        }
    }
    ~SegTree() {
        if(ls != nullptr) delete ls;
        if(rs != nullptr) delete rs;
    }
    int calcGcd(int l, int r) {
        if(l <= lx && rx <= r) return val;
        if(rx <= l || r <= lx) return 0;
        return __gcd(ls->calcGcd(l, r), rs->calcGcd(l, r));
    }
    int getGcd(int l, int r) {
        if(storeGcd.count(r)) return storeGcd[r];
        return storeGcd[r] = calcGcd(l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int g = 1;
    while(g < n) g *= 2;
    nums.resize(g);
    // Wait i swear if i didn't have to write segtree lol
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        vector<pair<int, int>> updates = {{nums[i], 1}};
        for(auto pa : gcdPrev) {
            updates.push_back({__gcd(pa.first, nums[i]), pa.second});
        }
        gcdPrev.clear();
        for(auto pa : updates) {
            gcdPrev[pa.first] += pa.second;
            gcdTotal[pa.first] += pa.second;
        }
        updates.clear();
    }
    int q;
    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        cout << gcdTotal[x] << '\n';
    }
}