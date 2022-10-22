#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD = (ll)1000000007;
vector<int> nums;
bool taken[200020];
int boop[26][5] = {
    {1, 0, 0, 1, 0},
    {1, 1, 0, 2, 0},
    {2, 0, 0, 1, 1},
    {2, 1, 0, 1, 2},
    {1, 1, 0, 1, 1},
    {2, 1, 0, 2, 1},
    {2, 2, 0, 2, 2},
    {1, 2, 0, 2, 1},
    {1, 1, 0, 1, 1},
    {1, 2, 0, 1, 2},
    {1, 0, 1, 2, 0},
    {1, 1, 1, 3, 0},
    {2, 0, 1, 2, 1},
    {2, 1, 1, 2, 2},
    {1, 1, 1, 2, 1},
    {2, 1, 1, 3, 1},
    {2, 2, 1, 3, 2},
    {1, 2, 1, 3, 1},
    {1, 1, 1, 2, 1},
    {1, 2, 1, 2, 2},
    {1, 0, 2, 2, 1},
    {1, 1, 2, 3, 1},
    {1, 2, 1, 1, 3},
    {2, 0, 2, 2, 2},
    {2, 1, 2, 2, 3},
    {1, 1, 2, 2, 2}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, m, n;
    ll k, ans = 0;
    string s1, s2;
    bool sad = false;
    cin >> t;
    while(t--) {
        vector<int>().swap(nums);
        nums.resize(5);
        for(int i = 0; i < 5; i++) cin >> nums[i];
        for(int i = 0; i < 26; i++) {
            sad = false;
            for(int j = 0; j < 5; j++) {
                if(nums[j] != boop[i][j]) sad = true;
            }
            if(!sad) {
                cout << (char)('a' + i);
                break;
            }
        }
    }
    cout << '\n';
}