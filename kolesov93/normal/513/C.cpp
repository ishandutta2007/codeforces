#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <memory.h>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int, int> pii;
const ld PI = acos(-1.);
const int N = 5;
int l[N], r[N];
int bits[1 << N];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }

    int lim = 1 << n;
    ld ans = 0;
    for (int i = 1; i < lim; ++i) bits[i] = bits[i & (i - 1)] + 1;
    for (int cost = 0; cost <= 10000; ++cost) {
        for (int msk = 0; msk < lim; ++msk)
            if (bits[msk] > 1) {
                ld prob = cost;
                for (int i = 0; i < n; ++i)
                    if (msk & (1 << i)) {
                        if (l[i] <= cost && cost <= r[i]) {
                            prob /= ld(r[i] - l[i] + 1);
                        } else {
                            prob = 0;
                            break;
                        }
                    } else {
                        if (l[i] < cost) {
                            prob *= ld(min(cost - 1, r[i]) - l[i] + 1) / ld(r[i] - l[i] + 1);
                        } else {
                            prob = 0;
                        }
                    }
                ans += prob;
            }

        for (int msk = 1; msk < lim; ++msk) {
            ld prob = cost;
            for (int j = 0; j < n; ++j)
                if (msk & (1 << j)) {
                    if (l[j] <= cost && cost <= r[j]) {
                        prob /= ld(r[j] - l[j] + 1);
                    } else {
                        prob = 0;
                    }
                }

            vector<int> who;
            for (int i = 0; i < n; ++i)
                if (!(msk & (1 << i)))
                    who.push_back(i);

            for (int x : who) {
                ld cur = prob; 

                if (r[x] > cost) {
                    cur *= ld(r[x] - max(l[x], cost + 1) + 1) / ld(r[x] - l[x] + 1);
                } else {
                    cur = 0;
                }
                for (int y : who)
                    if (y != x) {
                        if (l[y] < cost) {
                            cur *= ld(min(cost - 1, r[y]) - l[y] + 1) / ld(r[y] - l[y] + 1);
                        } else {
                            cur = 0;
                        }
                    }
                ans += cur;
            }
        }
    }
    cout.precision(20);
    cout << fixed;
    cout << double(ans) << endl;

    return 0;
}