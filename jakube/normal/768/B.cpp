#include <bits/stdc++.h>
using namespace std;

map<long long, long long> lengths;
map<long long, long long> cnts;

pair<long long, long long> precompute_lengths(long long n) {
    if (n <= 1) {
        lengths[n] = 1;
        cnts[n] = n;
    } else {
        auto p = precompute_lengths(n / 2);
        lengths[n] = 2*p.first + 1;
        cnts[n] = 2*p.second + (n % 2);
    }
    return {lengths[n], cnts[n]};
};

long long compute_interval(long long start_idx, long long n, long long left, long long right) {
    if (left <= start_idx && right >= start_idx + lengths[n]) 
        return cnts[n];

    if (left >= start_idx + lengths[n])
        return 0;

    if (right <= start_idx)
        return 0;

    long long sum = 0;
    sum += compute_interval(start_idx, n / 2, left, right);
    start_idx += lengths[n / 2];
    if (left <= start_idx && start_idx < right)
        sum += n % 2;
    sum += compute_interval(start_idx + 1, n / 2, left, right);
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    long long n, l, r;
    cin >> n >> l >> r;
    
    precompute_lengths(n);

    cout << compute_interval(0, n, l - 1, r) << endl;


    return 0;
}