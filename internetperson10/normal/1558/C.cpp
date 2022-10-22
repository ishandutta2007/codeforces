#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<int> nums;
vector<int> ops;

void rev(int n) {
    ops.push_back(n);
    for(int i = 0; i < n/2; i++) swap(nums[i], nums[n-i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        bool sad = false;
        int n;
        cin >> n;
        nums.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            if(nums[i]%2 == i%2) sad = true;
        }
        if(sad) cout << -1 << '\n';
        else {
            int m = n;
            while(m > 1) {
                for(int i = 0; i < n; i++) {
                    if(nums[i] == m) {
                        rev(i);
                        break;
                    }
                }
                for(int i = 0; i < n; i++) {
                    if(nums[i] == m-1) {
                        rev(i-1);
                        rev(i+1);
                        rev(2);
                        rev(m-1);
                        break;
                    }
                }
                m -= 2;
            }
            cout << ops.size() << '\n';
            for(int i = 0; i < ops.size(); i++) cout << ops[i]+1 << ' ';
            cout << '\n';
        }
        vector<int>().swap(nums);
        vector<int>().swap(ops);
    }
}