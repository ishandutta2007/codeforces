#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    
    int n;
    cin >> n;

    vector<int> a(n);
    int a_max = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a_max = max(a_max, a[i]);
    }
    
    int MAX_SIZE = a_max + 1;
    vector<int> count(MAX_SIZE, 0);
    vector<ll> best_sum(MAX_SIZE, 0);
    ll total_best = 0;

    for (auto a_el : a) {
        count[a_el]++;
    }

    for (int div = 1; div < MAX_SIZE; div++) {
        for (int mult = 2 * div; mult < MAX_SIZE; mult += div) {
            count[div] += count[mult];
        }
    }

    for (int div = 1; div < MAX_SIZE; div++) {
        for (int mult = 2 * div; mult < MAX_SIZE; mult += div) {
            best_sum[mult] = max(best_sum[mult], (ll) (count[div] - count[mult]) * div + best_sum[div]);
        }
    }

    for (ll mult = 1; mult < MAX_SIZE; mult++) {
        total_best = max(total_best, best_sum[mult] + mult * count[mult]);
    }


    cout << total_best << "\n";
}