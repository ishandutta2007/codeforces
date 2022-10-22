#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<int> nums, fi, la, co;
set<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    nums.resize(n); fi.resize(k+1, -1); la.resize(k+1, -1); co.resize(k+1);
    bool sad = false, les = false;
    for(int i = 0; i < n; i++) cin >> nums[i];
    for(int i = 0; i < n; i++) {
        if(nums[i]) {
            if(nums[i] == k) les = true;
            if(fi[nums[i]] == -1) fi[nums[i]] = i;
            la[nums[i]] = i;
        }
    }
    for(int i = 2; i <= k; i++) {
        if(fi[i] == -1) continue;
        nums[la[i]] *= -1;
    }
    s.insert(1);
    for(int i = 0; i < n; i++) {
        if(nums[i] > 0) {
            s.insert(nums[i]);
            auto it = s.find(nums[i]);
            it++;
            if(it != s.end()) sad = true;
        }
        if(nums[i] < 0) {
            s.insert(-nums[i]);
            auto it = s.find(-nums[i]);
            if(it == s.end()) continue;
            int x = (*it);
            it++;
            if(it != s.end()) sad = true;
            s.erase(x);
        }
        if(nums[i] == 0) {
            auto it = s.end();
            it--;
            if(!les) {
                nums[i] = k;
                les = true;
            }
            else nums[i] = (*it);
        }
    }
    if(sad || !les) cout << "NO\n";
    else {
        cout << "YES\n";
        for(int i = 0; i < n; i++) cout << abs(nums[i]) << ' ';
    }
}