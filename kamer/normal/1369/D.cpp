#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll NUM = 2 * 1e6 + 1;

int main(void) {
    vector<ll> nums(NUM + 2);
    vector<bool> root(NUM + 2);

    nums[1] = 0;
    nums[2] = 0;
    nums[3] = 1;
    root[1] = true;
    root[2] = true;
    root[3] = false;
    for (int i = 4; i < NUM; i++) {
        nums[i] = (2 * nums[i - 2] + nums[i - 1]) % MOD;
        if (root[i - 2] && root[i - 1]) {
            nums[i]++;
            root[i] = false;
        } else {
            root[i] = true;
        }
    }

    for (int i = 1; i < NUM; i++) {
        nums[i] = (4 * nums[i]) % MOD;
    }
    
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << nums[n] << "\n";
    }
}