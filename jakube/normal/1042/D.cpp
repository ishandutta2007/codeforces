#include <bits/stdc++.h>
using namespace std;

long long t;

long long f(vector<int> v) {
    int n = (int)v.size();
    if (n == 1) return v[0] < t;
    if (n == 0) return 0;

    int mid = n / 2;
    vector<long long> pre1, pre2;
    pre1.push_back(v[mid]);
    for (int i = mid - 1; i >= 0; i--)
        pre1.push_back(pre1.back() + v[i]);
    pre2.push_back(0);
    for (int i = mid + 1; i < n; i++)
        pre2.push_back(pre2.back() + v[i]);

    sort(pre1.begin(), pre1.end());
    sort(pre2.begin(), pre2.end());
    int cnt2 = pre2.size();
    long long total = 0;
    for (long long p : pre1) {
        while (cnt2 > 0 && p + pre2[cnt2-1] >= t)
            cnt2--;
        total += cnt2;
    }
    total += f({v.begin(), v.begin() + mid});
    total += f({v.begin() + mid + 1, v.end()});
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n >> t;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;
    cout << f(v) << endl;
}