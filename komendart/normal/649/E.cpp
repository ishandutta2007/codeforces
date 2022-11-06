#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

#define left ifejdgoire
#define right ijvioefjg

int n, A;
int left[maxn];
int right[maxn];
int number[maxn];

bool check(int x, vector<int> &ans) {
    ans.clear();
    set< pair<int, int> > d;
    for (int i = 0; i < n; i++) {
        while (!d.empty() && d.begin()->first <= left[i]) {
            ans.push_back(d.begin()->second);
            d.erase(d.begin());
        }
        if (d.size() == x) {
            if (d.rbegin()->first > right[i]) {
                d.erase(*d.rbegin());
                d.insert({right[i], number[i]});
            }
        } else {
            d.insert({right[i], number[i]});
        }
    }
    for (auto i: d) {
        ans.push_back(i.second);
    }
    return ans.size() >= A;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> A;
    vector< pair< pair<int, int>, int> > arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first.first >> arr[i].first.second;
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        left[i] = arr[i].first.first;
        right[i] = left[i] + arr[i].first.second;
        number[i] = arr[i].second;
    }

    vector<int> ans;
    int left = 0, right = n + 1;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (check(mid, ans)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    check(right, ans);
    cout << right << '\n';
    for (int i = 0; i < A; i++) {
        cout << ans[i] << ' ';
    }
}