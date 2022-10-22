#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int BIG = 1e6 + 7;
vector<int> badstr = {2, 0, 1, 6};
vector<int> nums, lastSeven, sixCount;

struct SegTree {
    int lx, rx;
    SegTree *ls, *rs;
    int minPrefMove[4][4]; // pref of length i -> pref of length j (and not j+1)
    SegTree(int l, int r) {
        lx = l;
        rx = r;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                minPrefMove[i][j] = BIG;
            }
        }
        if(rx - lx > 1) {
            int mid = (lx + rx) / 2;
            ls = new SegTree(lx, mid);
            rs = new SegTree(mid, rx);
            for(int i = 0; i < 4; i++) {
                for(int j = i; j < 4; j++) {
                    for(int k = i; k <= j; k++) {
                        minPrefMove[i][j] = min(
                            minPrefMove[i][j],
                            ls->minPrefMove[i][k] + rs->minPrefMove[k][j]
                        );
                    }
                }
            }
        }
        else {
            for(int i = 0; i < 4; i++) {
                minPrefMove[i][i] = (nums[lx] == badstr[i]);
            }
            for(int i = 0; i < 3; i++) {
                if(nums[lx] == badstr[i]) minPrefMove[i][i+1] = 0;
            }
        }
    }
    vector<int> combPrefMove(vector<int> v = {0, BIG, BIG, BIG}) {
        vector<int> v2(4, BIG);
        for(int i = 0; i < 4; i++) {
            for(int j = i; j < 4; j++) {
                v2[j] = min(v2[j], v[i] + minPrefMove[i][j]);
            }
        }
        return v2;
    }
    vector<int> queryMove(int l, int r, vector<int> v = {0, BIG, BIG, BIG}) {
        if(r <= lx || rx <= l) return v;
        if(l <= lx && rx <= r) return combPrefMove(v);
        v = ls->queryMove(l, r, v);
        v = rs->queryMove(l, r, v);
        return v;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    int g = 1;
    while(g < n) g *= 2;
    string s;
    cin >> s;
    nums.resize(g, 9);
    lastSeven.resize(n);
    sixCount.resize(n, 0);
    int la = -1;
    for(int i = 0; i < n; i++) {
        if(i) sixCount[i] = sixCount[i-1];
        nums[i] = s[i] - '0';
        if(nums[i] == 6) sixCount[i]++;
        if(nums[i] == 7) la = i;
        lastSeven[i] = la;
    }
    SegTree st(0, g);
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        if(lastSeven[r] < l) {
            cout << "-1\n";
            continue;
        }
        vector<int> v = st.queryMove(l, lastSeven[r]);
        if(v[3] == BIG) {
            cout << "-1\n";
        }
        else {
            cout << v[3] + sixCount[r] - sixCount[lastSeven[r]] << '\n';
        }
    }
}