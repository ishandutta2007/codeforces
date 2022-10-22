#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct FTree {
    int siz = 1;
    vector<int> nums;
    FTree(int n) {
        while(siz <= n) siz *= 2;
        nums.resize(siz+1);
    }
    void add(int n, int x) {
        n++;
        while(n <= siz) {
            nums[n] += x;
            n += (n & (-n));
        }
    }
    int get(int n) {
        n++;
        int tot = 0;
        while(n > 0) {
            tot += nums[n];
            n -= (n & (-n));
        }
        return tot;
    }
    int getval(int n) {
        return get(n) - get(n-1);
    }
    int upperbound(int x) {
        int l = 0, r = siz - 1;
        while(l != r - 1) {
            int mid = (l + r) / 2;
            int g = get(mid);
            if(g == x) {
                return mid;
            }
            if(g > x) r = mid;
            else l = mid;
        }
        return l;
    }
    void debug() {
        for(int i = 0; i < siz; i++) cout << getval(i) << ' ';
        cout << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        map<int, int> ma;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ma[x]++;
        }
        int g = n + 2;
        int lim = 2 * n + 4;
        vector<int> nums(2 * n + 4);
        FTree ftsum(n + 10), ftct(n + 10);
        multiset<int> s;
        for(auto p : ma) {
            int x, y;
            tie(x, y) = p;
            if(x > n) {
                x = g;
                g++;
            }
            nums[x] = y;
            if(y) s.insert(y);
        }
        int a = 0;
        vector<int> mums(n + 10, -1);
        for(int num : s) {
            ftsum.add(a, num);
            ftct.add(a, 1);
            if(mums[num] == -1) mums[num] = a;
            a++;
        }
        if(k == 0) {
            for(int i = 0; i <= n; i++) {
                if(nums[i] == 0) {
                    cout << (int)ma.size() - i << '\n';
                    break;
                }
            }
            continue;
        }
        int ans = 999999, zeroes = 0, totRight = n;
        for(int i = 0; i <= n; i++) {
            totRight -= nums[i];
            if(nums[i] > k || zeroes > k) {
                if(nums[i] == 0) zeroes++;
                else {
                    int g = mums[nums[i]];
                    mums[nums[i]]++;
                    ftsum.add(g, -nums[i]);
                    ftct.add(g, -1);
                }
                continue;
            }
            int opsLeft = k - nums[i];
            if(ftsum.get(0) > opsLeft) {
                ans = min(ans, ftct.get(n + 5));
            }
            else {
                ans = min(ans, ftct.get(n + 5) - ftct.get(ftsum.upperbound(opsLeft)));
            }
            if(nums[i] == 0) zeroes++;
            else {
                int g = mums[nums[i]];
                mums[nums[i]]++;
                ftsum.add(g, -nums[i]);
                ftct.add(g, -1);
            }
        }
        cout << ans << '\n';
    }
}