#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int ask(int x, int y) {
    int a, o;
    cout << "and " << x << ' ' << y << endl;
    cin >> a;
    cout << "or " << x << ' ' << y << endl;
    cin >> o;
    return a+o;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    int a1 = ask(2, 3);
    int a2 = ask(1, 3);
    int a3 = ask(1, 2);
    nums[0] = ((ll)a2 + a3 - a1)/2;
    nums[1] = ((ll)a1 + a3 - a2)/2;
    nums[2] = ((ll)a1 + a2 - a3)/2;
    for(int i = 3; i < n; i++) {
        nums[i] = ask(1, i+1) - nums[0];
    }
    sort(nums.begin(), nums.end());
    cout << "finish " << nums[k-1] << endl;
}