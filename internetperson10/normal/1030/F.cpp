#include <vector>
#include <ios>
#include <algorithm>
#include <iostream>
#include <cassert>
typedef __int128 ll;

using namespace std;

const int SIZ = 263000;
long long pos[SIZ], nums[SIZ];
int geets[SIZ], vals[SIZ];
ll BIG = 1e9;

struct ArraySegTree {
    long long segmentSum[2*SIZ];
    ll leftWeighted[2*SIZ], rightWeighted[2*SIZ];
    int lx[2*SIZ], rx[2*SIZ];
    int siz = 1;
    void updateVal(int n) {
        if(n >= siz - 1) {
            int l = n - (siz - 1);
            segmentSum[n] = nums[l];
            leftWeighted[n] = nums[l] * (pos[l] + 1);
            rightWeighted[n] = nums[l] * (-pos[l] + 1);
        }
        else {
            segmentSum[n] = segmentSum[2*n+1] + segmentSum[2*n+2];
            leftWeighted[n] = leftWeighted[2*n+1] + leftWeighted[2*n+2] + (rx[n] - lx[n]) / 2 * segmentSum[2*n+1];
            rightWeighted[n] = rightWeighted[2*n+1] + rightWeighted[2*n+2] + (rx[n] - lx[n]) / 2 * segmentSum[2*n+2];
        }
    }
    ArraySegTree(int n) {
        while(siz < n) siz *= 2;
        lx[0] = 0; rx[0] = siz;
        for(int i = 0; i < siz - 1; i++) {
            lx[2*i+1] = lx[i];
            lx[2*i+2] = (lx[i] + rx[i]) / 2;
            rx[2*i+1] = (lx[i] + rx[i]) / 2;
            rx[2*i+2] = rx[i];
        }
        for(int i = 2 * siz - 2; i >= 0; i--) {
            updateVal(i);
        }
    }
    void changeVal(int n, int x) {
        if(rx[n] <= x || x+1 <= lx[n]) return;
        if(x <= lx[n] && rx[n] <= x+1) {
            updateVal(n);
            return;
        }
        if(2 * x < lx[n] + rx[n]) changeVal(2*n+1, x);
        else changeVal(2*n+2, x);
        updateVal(n);
    }
    ll gravitateLeft(int n, int l, int r) {
        if(rx[n] <= l || r <= lx[n]) return 0;
        if(l <= lx[n] && rx[n] <= r) return -(ll)segmentSum[n] * (pos[l-1] - l + lx[n]) - rightWeighted[n];
        if(2 * r < lx[n] + rx[n]) return gravitateLeft(2*n+1, l, r);
        if(2 * l > lx[n] + rx[n]) return gravitateLeft(2*n+2, l, r);
        return gravitateLeft(2*n+1, l, r) + gravitateLeft(2*n+2, l, r);
    }
    ll gravitateRight(int n, int l, int r) {
        if(rx[n] <= l || r <= lx[n]) return 0;
        if(l <= lx[n] && rx[n] <= r) return (ll)segmentSum[n] * (pos[r] - r + rx[n]) - leftWeighted[n];
        if(2 * r < lx[n] + rx[n]) return gravitateRight(2*n+1, l, r);
        if(2 * l > lx[n] + rx[n]) return gravitateRight(2*n+2, l, r);
        return gravitateRight(2*n+1, l, r) + gravitateRight(2*n+2, l, r);
    }
    ll gravitate(int l, int r, int n) {
        return gravitateRight(0, l, n) + gravitateLeft(0, n+1, r);
    }
    long long getSegmentSum(int n, int l, int r) {
        if(rx[n] <= l || r <= lx[n]) return 0;
        if(l <= lx[n] && rx[n] <= r) return segmentSum[n];
        if(2 * r < lx[n] + rx[n]) return getSegmentSum(2*n+1, l, r);
        if(2 * l > lx[n] + rx[n]) return getSegmentSum(2*n+2, l, r);
        return getSegmentSum(2*n+1, l, r) + getSegmentSum(2*n+2, l, r);
    }
    ll ternarySearch(int l, int r) {
        ll ans = BIG;
        int le = l, ri = r;
        long long getWholeSum = getSegmentSum(0, l, r);
        while(ri - le >= 3) {
            int mid = (le + ri) / 2;
            long long ans1 = getSegmentSum(0, l, mid);
            long long ans2 = getWholeSum - ans1;
            if(ans1 <= ans2) {
                le = mid;
            }
            else {
                ri = mid + 1;
            }
        }
        for(int x = le; x < ri; x++) {
            ans = min(ans, gravitate(l, r, x));
        }
        return ans;
    }
};

const ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    BIG *= BIG;
    BIG *= BIG;
    int n, q;
    cin >> n >> q;
    int g = 1;
    while(g < n) g *= 2;
    for(int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    geets[0] = 0;
    int vc = 1;
    vals[0] = 0;
    for(int i = 1; i < n; i++) {
        if(pos[i] - 1 != pos[i-1]) {
            geets[i] = geets[i-1] + 1;
            vals[vc] = i;
            vc++;
        }
        else {
            geets[i] = geets[i-1];
        }
    }
    geets[n] = geets[n-1];
    for(int i = n; i < g; i++) {
        pos[i] = pos[n-1];
    }
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    ArraySegTree st(g);
    while(q--) {
        int x, y;
        cin >> x >> y;
        if(x < 0) {
            nums[-x-1] = y;
            st.changeVal(0, -x-1);
        }
        else {
            ll ans = st.ternarySearch(x-1, y);
            cout << (long long)((__int128)ans % (__int128)MOD) << '\n';
        }
    }
}