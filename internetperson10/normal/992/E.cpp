#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct FTree {
    vector<ll> nums;
    int siz = 1;
    FTree(int n) {
        while(siz < n) siz <<= 1;
        nums.resize(siz+1);
    }
    void add(int n, int x) {
        while(n <= siz) {
            nums[n] += x;
            n += (n & (-n));
        }
    }
    ll get(int n) {
        ll sum = 0;
        while(n) {
            sum += nums[n];
            n -= (n & (-n));
        }
        return sum;
    }
};

vector<int> sha;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // Wait it would be so funny if this worked lmao
    int n, q;
    cin >> n >> q;
    FTree ft(n+2);
    sha.resize(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> sha[i];
        ft.add(i, sha[i]);
    }
    while(q--) {
        int i;
        cin >> i;
        ft.add(i, -sha[i]);
        cin >> sha[i];
        ft.add(i, sha[i]);
        if(ft.get(1) == 0) {
            cout << "1\n";
            continue;
        }
        int x = 1;
        int ans = -1;
        while(x <= n) {
            int l = x, r = n + 1;
            ll tar = 2 * ft.get(x);
            while(l != r - 1) {
                int mid = (l + r) / 2;
                if(ft.get(mid) < tar) l = mid;
                else r = mid;
            }
            if(r == n + 1) break;
            if((ft.get(l) << 1) == ft.get(r)) {
                ans = r;
                break;
            }
            x = r;
        }
        cout << ans << '\n';
    }
}