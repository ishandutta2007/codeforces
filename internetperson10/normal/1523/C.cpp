#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<int> nums;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(x == 1) {
                nums.push_back(1);
            }
            else {
                while(nums.back() != x-1) nums.pop_back();
                nums.back()++;
            }
            for(int j = 0; j < nums.size(); j++) {
                if(j > 0) cout << ".";
                cout << nums[j];
            }
            cout << '\n';
        }
        vector<int>().swap(nums);
    }
}