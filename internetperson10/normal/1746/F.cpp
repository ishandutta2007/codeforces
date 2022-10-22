#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const int H = 23;
// Oh no

map<int, int> comp;

struct FTree {
    ll nums[(1 << 19) + 1];
    FTree() {
        for(int i = 0; i <= (1 << 19); i++) {
            nums[i] = 0;
        }
    }
    void add(int i, int x) {
        i++;
        while(i <= (1 << 19)) {
            nums[i] += x;
            i += (i & (-i));
        }
    }
    ll sum(int i) {
        ll ans = 0;
        while(i != 0) {
            ans += nums[i];
            i -= (i & (-i));
        }
        return ans;
    }
};

FTree ft[H];
int rnd[H][600000];
int nums[300000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < 600000; j++) {
            rnd[i][j] = uniform_int_distribution<int>(1, 1000000000)(rng);
        }
    }
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        if(!comp.count(nums[i])) {
            int x = comp.size();
            comp[nums[i]] = x;
        }
        for(int j = 0; j < H; j++) {
            ft[j].add(i, rnd[j][comp[nums[i]]]);
        }
    }
    while(q--) {
        int c;
        cin >> c;
        if(c == 1) {
            int i;
            cin >> i;
            i--;
            int d = comp[nums[i]];
            cin >> nums[i];
            if(!comp.count(nums[i])) {
                int x = comp.size();
                comp[nums[i]] = x;
            }
            int e = comp[nums[i]];
            for(int j = 0; j < H; j++) {
                ft[j].add(i, rnd[j][e] - rnd[j][d]);
            }
        }
        if(c == 2) {
            int l, r, k;
            cin >> l >> r >> k;
            l--;
            bool ok = true;
            if(k == 1) {
                ok = true;
            }
            else if((r - l) % k) {
                ok = false;
            }
            else {
                for(int j = 0; j < H; j++) {
                    if((ft[j].sum(r) - ft[j].sum(l)) % k) {
                        ok = false;
                    }
                }
            }
            cout << (ok ? "YES\n" : "NO\n");
        }
    }
}