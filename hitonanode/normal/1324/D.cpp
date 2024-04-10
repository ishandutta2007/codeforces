#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    vector<int> diff;
    for (int i = 0; i < N; i++) diff.emplace_back(A[i] - B[i]);
    sort(diff.begin(), diff.end());
    long long int ret = 0;
    for (int i = 0; i < N; i++) {
        auto itr = upper_bound(diff.begin() + i + 1, diff.end(), -diff[i]);
        ret += diff.end() - itr;
    }
    cout << ret << endl;
}