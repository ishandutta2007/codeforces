#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAX_NUM = 200001;
vector<bool> is_prime(MAX_NUM, true);
vector<int> mobius(MAX_NUM, 1);

void compute_mobius(void) {
    for (int i = 2; i < MAX_NUM; i++) {
        if (is_prime[i]) {
            mobius[i] = -1;
            for (int j = 2; j <= (MAX_NUM - 1) / i; j++) {
                is_prime[j * i] = false;
                if (j % i == 0) {
                    mobius[j * i] = 0;
                } else {
                    mobius[j * i] = - mobius[j * i];
                }
            }
        }
    }
}

ll absx(ll x) {
    if (x >= ((ll) 0)) return x;
    else return -x;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    compute_mobius();
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) b[i] -= a[i];

    vector<ll> c = b;
    vector<ll> val(n + 1);
    c[1] = 0;
    for (int i = 2; i <= n; i++) {
        val[i] = c[i];
        for (int j = 2 * i; j <= n; j += i) {
            c[j] -= c[i];
        }
    }

    const ll mill = 1000000;
    vector<ll> sums(2000001, 0);
    sums[0] = mill;
    for (int i = 2; i <= n; i++) {
        sums[0] += absx(- mobius[i] * mill + val[i]);
    }

    vector<ll> num_breaks(2000001, 0);
    int count_inc = 0;
    int count_dec = 1;
    for (int i = 2; i <= n; i++) {
        if (mobius[i] == 1) {
            if (val[i] < -mill) {
                count_dec++;
            } else if (val[i] >= mill) {
                count_inc++;
            } else {
                count_dec++;
                num_breaks[mill - val[i]]++;
            }
        } else if (mobius[i] == -1) {
            if (val[i] <= -mill) {
                count_inc++;
            } else if (val[i] > mill) {
                count_dec++;
            } else {
                count_dec++;
                num_breaks[mill + val[i]]++;
            }
        }
    }
    num_breaks[mill]++;

    for (int i = -mill + 1; i <= mill; i++) {
        sums[i + mill] = sums[i + mill - 1] + count_inc - count_dec;
        count_inc += num_breaks[i + mill];
        count_dec -= num_breaks[i + mill];
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        x = x - a[1] + mill;
        cout << sums[x] << "\n";
    }
}