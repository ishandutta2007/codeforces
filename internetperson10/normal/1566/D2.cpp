#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<ll, ll>> nums(n*m);
        map<ll, priority_queue<int, vector<int>, greater<int>>> ma;
        vector<vector<bool>> count(n);
        for(int i = 0; i < n; i++) {
            count[i].resize(m);
            for(int j = 0; j < m; j++) {
                cin >> nums[i*m+j].first;
                nums[i*m+j].second = i*m+j; 
            }
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(ma.find(nums[i*m+j].first) == ma.end()) {
                    ma[nums[i*m+j].first] = priority_queue<int, vector<int>, greater<int>>();
                }
                ma[nums[i*m+j].first].push((i+1)*m-j);
                swap(nums[i*m+j].first, nums[i*m+j].second);
            }
        }
        sort(nums.begin(), nums.end());
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ll g = ma[nums[i*m+j].second].top();
                ma[nums[i*m+j].second].pop();
                ll mo = g % m;
                if(!mo) mo = m;
                mo = m - mo;
                g += 2*mo;
                g -= m;
                ll x = g / m;
                ll y = g % m;
                for(int k = 0; k < y; k++) {
                    ans += count[x][k];
                }
                count[x][y] = true;
            }
        }
        cout << ans << '\n';
        map<ll, priority_queue<int, vector<int>, greater<int>>>().swap(ma);
        vector<pair<ll, ll>>().swap(nums);
        vector<vector<bool>>().swap(count);
    }
}