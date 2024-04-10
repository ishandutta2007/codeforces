#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        unordered_map<int, int> m;
        ll ans = 0;
        vector<int> sads;
        vector<pair<int, int>> upds;
        for(int i = n-1; i >= 0; i--) {
            for(auto p : m) {
                ll x = p.first, y = p.second;
                if(x == nums[i]) continue;
                if(x > nums[i]) {
                    m[nums[i]] += m[x];
                    m[x] = 0;
                    continue;
                }
                int moves = (nums[i]-1)/x;
                ans += (y * moves * (i+1));
                ans %= MOD;
                upds.push_back({nums[i]/(moves+1), y});
                m[x] = 0;
            }
            m[nums[i]]++;
            for(auto p : upds) {
                m[p.first] += p.second;
            }
            for(auto p : m) {
                if(p.second == 0) sads.push_back(p.first); 
            }
            for(auto g : sads) m.erase(g);
            vector<int>().swap(sads);
            vector<pair<int, int>>().swap(upds);
        }
        unordered_map<int, int>().swap(m);
        vector<ll>().swap(nums);
        cout << ans << '\n';
    }
}