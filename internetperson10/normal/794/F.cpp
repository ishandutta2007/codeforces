#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll n1[10], n2[10], s1[10], s2[10];

struct segTree {
    int size = 1, n;
    vector<ll> nums[10], ops[10];
    void init(int num, vector<ll> v) {
        n = num;
        while(size < n) size *= 2;
        for(int i = 0; i < 10; i++) {
            nums[i].resize(2*size);
            ops[i].resize(2*size, -1);
        }
        for(int i = 0; i < n; i++) {
            ll k = 1;
            while(v[i]) {
                nums[v[i]%10][size-1+i] += k;
                v[i] /= 10;
                k *= 10;
            }
        }
        for(int i = size-2; i >= 0; i--) {
            for(int j = 0; j < 10; j++) {
                nums[j][i] = nums[j][2*i+1] + nums[j][2*i+2];
            }
        }
    }
    void prop(int n) {
        for(int i = 0; i < 10; i++) {
            n1[i] = n2[i] = -1;
            s1[i] = s2[i] = 0;
        }
        //cout << "nums2 " << 2*n+2 << ' ';
        //for(int i = 0; i < 10; i++) cout << nums[i][2*n+2] << ' ';
        //cout << '\n';
        //cout << n << ' ';
        for(int i = 0; i < 10; i++) {
            if(ops[i][n] == -1) ops[i][n] = i;
            //cout << ops[i][n];
        }
        //cout << '\n';
        for(int i = 0; i < 10; i++) {
            s1[ops[i][n]] += nums[i][n];
        }
        for(int i = 0; i < 10; i++) {
            nums[i][n] = s1[i];
        }
        if(n >= size-1) {
            for(int i = 0; i < 10; i++) {
                ops[i][n] = -1;
            }
            return;
        }
        for(int i = 0; i < 10; i++) {
            if(ops[i][2*n+1] == -1) ops[i][2*n+1] = i;
            if(ops[i][2*n+2] == -1) ops[i][2*n+2] = i;
        }
        for(int i = 0; i < 10; i++) {
            n1[i] = ops[ops[i][2*n+1]][n];
            n2[i] = ops[ops[i][2*n+2]][n];
        }
        for(int i = 0; i < 10; i++) {
            ops[i][2*n+1] = n1[i];
            ops[i][2*n+2] = n2[i];
        }
        for(int i = 0; i < 10; i++) {
            ops[i][n] = -1;
        }
        //cout << "ops " << 2*n+1 << ' ';
        //for(int i = 0; i < 10; i++) cout << ops[i][2*n+1] << ' ';
        //cout << '\n';
        //cout << "ops " << 2*n+2 << ' ';
        //for(int i = 0; i < 10; i++) cout << ops[i][2*n+2] << ' ';
        //cout << '\n';
        //cout << 2*n+1 << ' ';
        //for(int i = 0; i < 10; i++) cout << nums[i][2*n+1] << ' ';
        //cout << '\n';
    }
    void add(int l, int r, int x, int y, int n, int lx, int rx) {
        prop(n);
        if(l >= rx || lx >= r) return;
        if(l <= lx && rx <= r) {
            //cout << x << ' ' << n << ' ' << y << '\n';
            ops[x][n] = y;
            nums[y][n] += nums[x][n];
            nums[x][n] = 0;
            return;
        }
        int mid = (lx + rx)/2;
        add(l, r, x, y, 2*n+1, lx, mid);
        add(l, r, x, y, 2*n+2, mid, rx);
        for(int i = 0; i < 10; i++) nums[i][n] = nums[i][2*n+1] + nums[i][2*n+2];
        return;
    }
    void add(int l, int r, int x, int y) {
        if(x == y) return;
        add(l, r, x, y, 0, 0, size);
    }
    ll tot(int n) {
        ll ans = 0;
        for(int i = 0; i < 10; i++) {
            ans += nums[i][n] * (ll)i;
        }
        //cout << n << ' ' << ans << '\n';
        return ans;
    }
    ll sum(int l, int r, int n, int lx, int rx) {
        prop(n);
        if(l >= rx || lx >= r) return 0;
        if(l <= lx && rx <= r) return tot(n);
        int mid = (lx + rx)/2;
        ll sum1 = sum(l, r, 2*n+1, lx, mid);
        ll sum2 = sum(l, r, 2*n+2, mid, rx);
        return sum1 + sum2;
    }
    ll sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

vector<ll> nums;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    nums.resize(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    segTree st;
    st.init(n, nums);
    while(q--) {
        int c;
        cin >> c;
        if(c == 1) {
            int l, r, x, y;
            cin >> l >> r >> x >> y;
            l--;
            st.add(l, r, x, y);
        }
        else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << st.sum(l, r) << '\n';
        }
    }
}