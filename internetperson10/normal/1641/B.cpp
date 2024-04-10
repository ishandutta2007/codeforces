#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        map<int, int> odd;
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            if(odd.count(nums[i])) {
                odd[nums[i]]++;
            }
            else odd[nums[i]] = 1;
        }
        bool ok = true;
        for(auto p : odd) {
            if(p.second%2) ok = false;
        }
        if(!ok) {
            cout << "-1\n";
            continue;
        }
        vector<int> nums2;
        vector<ll> qs, adds, ops; // q: add number, op: division
        ll sumq = 0, sumop = 0;
        while(nums.size()) {
            for(int i = 1; i < nums.size(); i++) {
                if(nums[i] == nums[0]) {
                    sumq += (i+1);
                    for(int j = 1; j < i; j++) {
                        qs.push_back(sumq);
                        adds.push_back(nums[j]);
                        sumq++;
                    }
                    for(int j = i-1; j > 0; j--) {
                        nums2.push_back(nums[j]);
                    }
                    for(int j = i+1; j < nums.size(); j++) {
                        nums2.push_back(nums[j]);
                    }
                    nums2.swap(nums);
                    vector<int>().swap(nums2);
                    ops.push_back(2*i);
                    break;
                }
            }
        }
        cout << qs.size() << '\n';
        for(int i = 0; i < qs.size(); i++) {
            cout << qs[i] << ' ' << adds[i] << '\n';
        }
        cout << ops.size() << '\n';
        for(int g : ops) cout << g << ' ';
        cout << '\n';
    }
}