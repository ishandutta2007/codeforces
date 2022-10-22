#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> nums;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1, n;
    long long int w=0, x=0, y=0, z=0, ans=0;
    int a=0, b=0, c=0, d=0, e=0;
    cin >> t;
    while(t--) {
        cin >> n >> w;
        for(int i = 0; i < n; i++) {
            cin >> x;
            nums.push_back(x);
        }
        sort(nums.begin(), nums.end());
        if(nums[n-1] <= w) cout << "YES\n";
        else if(nums[0] + nums[1] <= w) cout << "YES\n";
        else cout << "NO\n";
        vector<ll>().swap(nums);
    }
}