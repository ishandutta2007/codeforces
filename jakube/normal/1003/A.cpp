#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> cnt(101, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    cout << *max_element(cnt.begin(), cnt.end()) << '\n';
}