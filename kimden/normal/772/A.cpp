#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    long long p;
    cin >> n >> p;
    vector<pair<double, long long>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].second >> v[i].first;
        v[i].first /= v[i].second;
    }
    sort(v.begin(), v.end());
    double tp = 0;
    long long sum_a = 0;
    for (int i = 1; i < n; ++i) {
        sum_a += v[i - 1].second;
        if ((v[i].first - tp) * p >= sum_a * (v[i].first - v[i - 1].first)) {
            tp += sum_a * (v[i].first - v[i - 1].first) / p;
        } else {
            cout << setprecision(10) << v[i - 1].first + p * (v[i - 1].first - tp) / (sum_a - p)
                 << endl;
            return 0;
        }
    }
    sum_a += v[n - 1].second;
    if (p >= sum_a) {
        cout << -1 << endl;
    } else {
        cout << setprecision(20) << v[n - 1].first + p * (v[n - 1].first - tp) / (sum_a - p);
    }
    return 0;
}