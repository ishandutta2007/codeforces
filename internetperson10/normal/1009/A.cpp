#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<int> nums, bills;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    nums.resize(n); bills.resize(k);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for(int i = 0; i < k; i++) {
        cin >> bills[i];
    }
    bills.push_back(0);
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(nums[i] <= bills[j]) j++;
    }
    cout << j << '\n';
}