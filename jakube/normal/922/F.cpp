#include <bits/stdc++.h>
using namespace std;

void computePrimesLargest(int n, std::vector<int> &largest)
{
    largest.resize(n + 1);
    std::iota(largest.begin(), largest.end(), 0);

    for (int i = 2; i <= n; i++) {
        if (i == largest[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                largest[j] = i;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> largest;
    computePrimesLargest(300'000, largest);
    vector<int> d((int)largest.size(), 1);
    for (int i = 2; i < (int)largest.size(); i++) {
        int x = i;
        while (x % largest[i] == 0) {
            d[i]++;
            x /= largest[i];
        }
        d[i] *= d[x];
    }
    for (auto& x : d)
        x--;

    int n, k;
    cin >> n >> k;

    int sum = 0;
    int r = 0;
    vector<int> primes;
    for (; r <= n; r++) {
        sum += d[r];
        if (d[r] == 1)
            primes.push_back(r);
        if (sum >= k) break;
    }

    if (sum < k) {
        cout << "No" << '\n';
        return 0;
    }

    vector<bool> used(r + 1, true);
    int cur = primes.size() - 1;
    while (sum > k + 1 && cur >= 0) {
        int x = primes[cur];
        if (2 * x <= r && 3 * x > r) {
            used[x] = false;
            sum -= 2;
        }
        cur--;
    }
    cur = primes.size() - 1;
    while (sum > k && cur >= 0) {
        int x = primes[cur];
        if (2 * x > r) {
            used[x] = false;
            sum -= 1;
        }
        cur--;
    }

    cout << "Yes" << '\n';

    // if (k == 6) {
    //     cout << 5 << endl;
    //     cout << "1 2 4 5 6" << endl;
    //     return 0;
    // }

    vector<int> v;
    for (int i = 1; i < (int)used.size(); i++) {
        if (used[i])
            v.push_back(i);
    }
    cout << v.size() << endl;
    for (auto x : v) {
        cout << x << ' ';
    }
    cout << '\n';
}