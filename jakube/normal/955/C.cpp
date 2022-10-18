#include <bits/stdc++.h>
using namespace std;

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

long long f(long long x, vector<long long>::iterator begin, vector<long long>::iterator end) {
    long long L = 0;
    long long R = 1'000'000'001;
    while (L + 1 < R) {
        long long M = (L + R) / 2;
        if (M * M <= x)
            L = M;
        else
            R = M;
    }
    long long cnt = L;
    cnt += upper_bound(begin, end, x) - begin;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> v;
    set<long long> squares;
    for (int i = 1; i <= 1000; i++) {
        squares.insert(i * i);
    }
    for (long long i = 1; i <= 1'000'000; i++) {
        if (squares.count(i))
            continue;
        long long w = i;
        int idx = 1;
        long long m = 1'000'000'000'000'000'000LL / w;
        for (int mult = 2; w <= m && idx < 25; mult++) {
            w *= i;
            if (primes[idx] == mult) {
                v.push_back(w);
                idx++;
            }
        }
    }
    sort(v.begin(), v.end());
    auto end = unique(v.begin(), v.end());
    auto begin = v.begin();

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        long long L, R;
        cin >> L >> R;
        cout << f(R, begin, end) - f(L - 1, begin, end) << '\n';
    }
}