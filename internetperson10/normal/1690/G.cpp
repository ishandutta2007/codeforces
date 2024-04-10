#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> nums(n);
        set<int> s;
        int ma = 1e9 + 7;
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            if(ma > nums[i]) {
                ma = nums[i];
                s.insert(i);
            }
        }
        while(m--) {
            int k, d;
            cin >> k >> d;
            k--;
            nums[k] -= d;
            auto it = s.lower_bound(k);
            if(s.count(k)) {
                it++;
                while(it != s.end()) {
                    if(nums[(*it)] >= nums[k]) {
                        int g = (*it);
                        it++;
                        s.erase(g);
                    }
                    else break;
                }
            }
            else {
                it--;
                if(nums[(*it)] > nums[k]) {
                    s.insert(k);
                    it++;
                    it++;
                    while(it != s.end()) {
                        if(nums[(*it)] >= nums[k]) {
                            int g = (*it);
                            it++;
                            s.erase(g);
                        }
                        else break;
                    }
                }
            }
            cout << s.size() << ' ';
        }
        cout << '\n';
    }
}