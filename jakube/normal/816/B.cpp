#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, q;
    cin >> n >> k >> q;

    vector<int> diffs(200'002, 0);

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        diffs[l]++;
        diffs[r+1]--;
    }

    vector<int> nums(diffs.size());
    nums[0] = diffs[0];
    for (int i = 1; i < diffs.size(); i++) {
        nums[i] = nums[i-1] + diffs[i];
    }

    vector<int> greater_k(diffs.size());
    for (int i = 0; i < diffs.size(); i++) {
        greater_k[i] = nums[i] >= k;
    }

    vector<int> psums(diffs.size());
    psums[0] = 0;
    for (int i = 1; i < diffs.size(); i++) {
        psums[i] = psums[i-1] + greater_k[i];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << psums[r] - psums[l-1] << '\n';
    }
}