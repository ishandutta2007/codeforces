#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> dist(n, 0), cnt(n, 0);
    cnt[0] = 1;
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        dist[i] = dist[p-1] + 1;
        cnt[dist[i]] ^= 1;
    }
    cout << accumulate(cnt.begin(), cnt.end(), 0) << endl;
}