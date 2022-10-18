#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, T;
    cin >> n >> T;
    vector<long long> a(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        t[i] -= T;
    }

    long long sum = 0;
    long long result = 0;
    vector<pair<long long, long long>> colder, hotter;
    for (int i = 0; i < n; i++) {
        sum += a[i] * t[i];
        result += a[i];
        if (t[i] < 0)
            colder.emplace_back(-t[i], a[i]);
        if (t[i] > 0)
            hotter.emplace_back(t[i], a[i]);
    }

    auto make_zero = [](auto vec, auto sum, auto& result) {
        sort(vec.begin(), vec.end());
        while (sum > 0) {
            auto b = vec.back();
            if (sum >= b.first * b.second) {
                sum -= b.first * b.second;
                result -= b.second;
                vec.pop_back();
            } else {
                return result - sum / (long double)b.first;
            }
        }
        return (long double)result;
    };

    cout << fixed << setprecision(15);
    cout << make_zero(sum > 0 ? hotter : colder, abs(sum), result) << endl;
}