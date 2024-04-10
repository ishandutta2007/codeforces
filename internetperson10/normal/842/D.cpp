#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct FTree {
    int siz = (1 << 20);
    vector<int> nums;
    FTree(int n) {
        while(siz < n) siz *= 2;
        nums.resize(siz+1);
    }
    void add(int x) {
        x++;
        while(x <= siz) {
            nums[x]++;
            x += (x & (-x));
        }
    }
    int get(int x) {
        x++;
        int ans = 0;
        while(x) {
            ans += nums[x];
            x -= (x & (-x));
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    FTree ft(2*n+1);
    vector<int> taken(300001, 0);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(!taken[x]) {
            taken[x] = true;
            ft.add(x);
        }
    }
    int currXor = 0;
    while(q--) {
        int x;
        cin >> x;
        currXor ^= x;
        int ans = 0, i = 19;
        while(i--) {
            int leftLim = (((ans ^ currXor) >> i) << i) - 1;
            int rightLim = leftLim + (1 << i);
            if(ft.get(rightLim) - ft.get(leftLim) == (1 << i)) ans += (1 << i);
        }
        cout << ans << '\n';
    }
}