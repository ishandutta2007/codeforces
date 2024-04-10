#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct Trie {
    int l = 0;
    int best[2][2] = {{0, 0}, {0, 0}};
    Trie* chil[2] = {nullptr, nullptr};
    Trie(int l) : l(l) {}
    void add(int a, int b, int c) {
        bool x = a & (1 << l);
        bool y = b & (1 << l);
        best[x][y] = max(best[x][y], c);
        if(l > 0) {
            if(chil[x^y] == nullptr) chil[x^y] = new Trie(l-1);
            chil[x^y]->add(a, b, c);
        }
    }
    int get(int a, int b) {
        bool x = a & (1 << l);
        bool y = b & (1 << l);
        if(l == 0) return best[y][x^1];
        if(chil[x^y] == nullptr) chil[x^y] = new Trie(l-1);
        return max(best[y][x^1], chil[x^y]->get(a, b));
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    Trie t(29);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        int x = t.get(nums[i], i);
        ans = max(ans, x+1);
        t.add(nums[i], i, x+1);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}