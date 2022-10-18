#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    set<long long> results;
    set<int> divisors;
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            divisors.insert(i);
            divisors.insert(n/i);
        }
    }

    for (int i : divisors) {
        results.insert((n + 2 - i) * (long long)(n / i) / 2);
        // int cur = 0;
        // long long sum = 0;
        // do {
        //     sum += cur + 1;
        //     cur = (cur + i) % n;
        // } while (cur != 0);
        // results.insert(sum);
    }
    for (auto x : results)
        cout << x << ' ';
    cout << '\n';
}