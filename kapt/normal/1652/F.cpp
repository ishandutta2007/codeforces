#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 1 <<18;

vector<int> solve(int n, vector<int> arr);

vector<int> get(int n, vector<int> arr) {
    vector<int> all;
    for (int i = 0;i < (1 << (n - 1)); ++i) {
        all.push_back(arr[2 * i] * MAXN + arr[2 * i +1]);
    }
    sort(all.begin(), all.end());
    int k = unique(all.begin(), all.end()) - all.begin();
    unordered_map<int, int> mp;
    for (int i = 0;i < k; ++i) {
        mp[all[i]] = i;
    }
    vector<int> arr1;
    for (int i = 0; i < (1<<(n - 1)); ++i) {
        arr1.push_back(mp[arr[2 * i] *MAXN + arr[2 * i +1]]);
    }
    arr1 = solve(n - 1, arr1);
    vector<int> ans1;
    for (int i = 0; i <(1 <<(n - 1)); ++i) {
        ans1.push_back(all[arr1[i]] / MAXN);
        ans1.push_back(all[arr1[i]] % MAXN);
    }
    return ans1;
}

vector<int> solve(int n, vector<int> arr) {
    if (n == 0) return arr;
    vector<int> ans1 = get(n, arr);
    for (int i = 0; i < (1 <<n); i += 2) {
        swap(arr[i], arr[i +1]);
    }
    vector<int> ans2 = get(n, arr);
    return min(ans1, ans2);
}

main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> arr;
    for (auto ch : s) {
        arr.push_back(ch - 'a');
    }
    arr = solve(n, arr);
    for (int x: arr) {
        cout<<(char)(x+ 'a');
    }
    return 0;
}