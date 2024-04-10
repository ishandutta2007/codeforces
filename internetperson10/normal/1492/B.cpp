#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD = (ll)1000000007;
vector<ll> nums;
vector<bool> taken;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, m, n;
    ll k, ans = 0, a, b, c, j;
    string s1, s2;
    bool sad = false;
    cin >> t;
    while(t--) {
        cin >> n;
        nums.resize(n);
        taken.resize(n+1);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        k = n; j = n;
        for(int i = n-1; i >= 0; i--) {
            taken[nums[i]] = true;
            if(nums[i] == k) {
                for(int z = i; z < j; z++) cout << nums[z] << ' ';
                j = i;
            }
            for(k; k > 0; k--) {
                if(!taken[k]) break;
            }
        }
        cout << '\n';
        vector<ll>().swap(nums);
        vector<bool>().swap(taken);
    }
}