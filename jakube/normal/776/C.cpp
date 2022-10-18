#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<long long> powers;
    powers.push_back(1);
    for (int i = 0; i < 50; i++) {
        long long tmp = powers.back() * k;
        if (find(powers.begin(), powers.end(), tmp) == powers.end() && tmp < 1e15)
            powers.push_back(powers.back() * k);
    }

    vector<long long> psum(n + 1, 0);
    for (int i = 0; i < n; i++)
        psum[i+1] = psum[i] + v[i];

    map<long long, int> m;
    m[0] = 1;

    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        for (long long p : powers) {
            // psum[i+1] - psum[j] == p
            // psum[j] = psum[i + 1] - p
            cnt += m[psum[i+1] - p];
        }
        m[psum[i+1]]++;
    }

    cout << cnt << endl;
}