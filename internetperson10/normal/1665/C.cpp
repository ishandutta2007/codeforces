#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n+1);
        nums[0] = 1;
        for(int i = 1; i < n; i++) {
            int x;
            cin >> x;
            nums[x]++;
        }
        sort(nums.rbegin(), nums.rend());
        while(nums.back() == 0) nums.pop_back();
        reverse(nums.begin(), nums.end());
        int turn = 0;
        int ans = 0;
        vector<int> extras;
        bool sorted = false;
        while(true) {
            turn++;
            if(nums.size()) {
                extras.push_back(nums.back() + turn - 1);
                nums.pop_back();
            }
            if (!nums.size() && !sorted) {
                sorted = true;
                sort(extras.begin(), extras.end());
            }
            else if(!nums.size()) {
                int i = extras.size() - 1;
                while(i) {
                    if(extras[i] == extras[i-1]) i--;
                    else break;
                }
                extras[i]--;
            }
            if(turn >= extras.back() && (nums.size() == 0)) break;
        }
        cout << turn << '\n';
    }
}