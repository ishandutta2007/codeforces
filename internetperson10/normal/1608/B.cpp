#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t-- ){
        int n, a, b;
        cin >> n >> a >> b;
        if(max(a, b) > (n-1)/2) {
            cout << "-1\n";
        }
        else if(a+b > (n-2)) {
            cout << "-1\n";
        }
        else if(abs(a-b) > 1) {
            cout << "-1\n";
        }
        else {
            vector<int> nums;
            int k = n-1-b-a;
            for(int i = 1; i <= k; i++) nums.push_back(i);
            for(int i = k+1; i <= n; i+=2) {
                if(i < n) {
                    nums.push_back(i+1);
                }
                nums.push_back(i);
            }
            if(a >= b) {
                for(int g : nums) cout << g << ' ';
            }
            else {
                for(int g : nums) cout << n+1-g << ' ';
            }
            cout << '\n';
            vector<int>().swap(nums);
        }
    }
}