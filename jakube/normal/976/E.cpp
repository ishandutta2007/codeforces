#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n >> a >> b;
    vector<pair<long long, long long>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    if (b == 0) {
        long long sum = 0;
        for (auto p : v)
            sum += p.second;
        cout << sum << '\n';
        return 0;
    }
    
    sort(v.begin(), v.end(), [](auto p, auto q) {
        int a = p.first - p.second;
        int b = q.first - q.second;
        if (a > b)
            return true;
        if (a < b)
            return false;
        return p.first > q.first;
    });

    vector<pair<long long, long long>> bs;
    vector<pair<long long, long long>> as;

    // sort(v.begin(), v.end());
    // reverse(v.begin(), v.end());
    for (auto p : v) {
        if (p.first > p.second && (int)bs.size() < b)
            bs.push_back(p);
        else
            as.push_back(p);
    }

    long long result = 0;
    long long sum = 0;
    for (auto p : bs) {
        sum += p.first;
    }
    for (auto p : as) {
        sum += p.second;
    }
    result = sum;

    if (b == 0) {
        cout << b << '\n';
        return 0;
    }

    for (auto p : bs) {
        long long tmp = (p.first << a) - p.first;
        result = max(result, sum + tmp);
    }

    if ((int)bs.size() == b) {
        long long minus = std::numeric_limits<long long>::min();
        for (auto p : bs) {
            minus = max(minus, p.second - p.first);
        }
        sum += minus;
    }

    for (auto p : as) {
        long long tmp = max(p.second, (p.first << a)) - p.second;
        result = max(result, sum + tmp);
    }

    cout << result << '\n';
    
}