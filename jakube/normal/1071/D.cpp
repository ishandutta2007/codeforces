#include <bits/stdc++.h>
using namespace std;


std::vector<int> largest;

void computePrimesLargest(int n) {
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

std::vector<int> divisors(int x) {
    std::vector<int> d;

    while (x > 1) {
        int p = largest[x];
        int c = 0;
        while (largest[x] == p) {
            c++;
            x /= p;
        }
        d.push_back(c);
    }
    sort(d.begin(), d.end());
    return d;
}

vector<int> primes = {2, 3, 5, 7, 11, 13, 17};
set<long long> divs;
vector<vector<int>> arrs;

long long f(vector<int> a, long long cur, int idx=0, int max=100, long long div=1) {
    long long cnt = 1;
    divs.insert(div);
    arrs.push_back(a);
    if (idx == (int)primes.size())
        return cnt;
    
    for (int j = 1; j <= max; j++) {
        cur *= primes[idx];
        if (cur > 300'000'000LL)
            break;
        a[idx]++;
        cnt += f(a, cur, idx+1, j, div * (j + 1));
    }
    return cnt;
}


void Floyd_Warshall(std::vector<std::vector<int>> &cost) {
    int n = cost.size();

    for (int i = 0; i < n; i++) {
        cost[i][i] = 0;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cost[i][j] = std::min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    computePrimesLargest(1'000'000);
    // set<vector<int>> s;
    // for (int i = 1; i < 1'000'000; i++) {
    //     auto v = divisors(i);
    //     s.insert(v);
    // }



    // set<int> t;
    // for (auto x : s) {
    //     int p = 1;
    //     for (int y : x)
    //         p *= y;
    //     t.insert(p);
    // }
    // cout << (int)s.size() << '\n';
    // cout << (int)t.size() << '\n';

    vector<int> arr = {0, 0, 0, 0, 0, 0, 0};
    f(arr, 1);
    // cout << f(arr, 1) << '\n';
    // cout << divs.size() << '\n';
    // cout << endl;

    int n = arrs.size();
    // cout << n << '\n';
    
    sort(arrs.begin(), arrs.end());
    vector<vector<int>> costs(n, vector<int>(n, 10000));
    for (int i = 0; i < n; i++) {
        auto a = arrs[i];
        for (int idx = 0; idx < 7; idx++) {
            auto b = a;
            b[idx]++;
            sort(b.begin(), b.end());
            reverse(b.begin(), b.end());
            auto it = lower_bound(arrs.begin(), arrs.end(), b);
            if (*it == b)
                costs[i][it - arrs.begin()] = 1;

            b = a;
            if (b[idx] == 0)
                continue;
            b[idx]--;
            sort(b.begin(), b.end());
            reverse(b.begin(), b.end());
            it = lower_bound(arrs.begin(), arrs.end(), b);
            if (*it == b)
                costs[i][it - arrs.begin()] = 1;
        }
    }
    Floyd_Warshall(costs);
    vector<int> DIVS(divs.begin(), divs.end());
    vector<vector<int>> answers(n, vector<int>(divs.size(), 1000));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long prod = 1;
            for (int x : arrs[j])
                prod *= x + 1;
            int IDX = lower_bound(DIVS.begin(), DIVS.end(), prod) - DIVS.begin();
            answers[i][IDX] = min(answers[i][IDX], costs[i][j]);
        }
    }

    int T;
    cin >> T;
    while (T --> 0) {
        int x, y;
        cin >> x >> y;
        auto v1 = divisors(x);
        while (v1.size() < 7)
            v1.push_back(0);
        sort(v1.begin(), v1.end());
        reverse(v1.begin(), v1.end());
        int idx1 = lower_bound(arrs.begin(), arrs.end(), v1) - arrs.begin();
        
        auto v2 = divisors(y);
        while (v2.size() < 7)
            v2.push_back(0);
        sort(v2.begin(), v2.end());
        reverse(v2.begin(), v2.end());
        int idx2 = lower_bound(arrs.begin(), arrs.end(), v2) - arrs.begin();

        int best = 1000;
        for (int IDX = 0; IDX < (int)DIVS.size(); IDX++) {
            best = min(best, answers[idx1][IDX] + answers[idx2][IDX]);
        }

        // cout << costs[idx1][idx2];
        cout << best << '\n';
    }
}