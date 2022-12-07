#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;

int gcd(int x, int y) {
    while (x && y)
        if (x > y) x %= y;
        else y %= x;
    return x + y;
}

const int M = 60;
const int N = 111;
const int K = 17;
bool seive[M];
int masks[N];
int a[N];
int n;
vector<int> primes;
short f[N][1 << K];
pair<int, char> prev[N][1 << K];

inline int myabs(int x) {
    if (x < 0) return -x;
    return x;
}

int main() {
    for (int i = 2; i < M; ++i)
        if (!seive[i]) {
            for (int j = i + i; j < M; j += i) seive[j] = true;
            primes.push_back(i);
        }
    for (int i = 1; i < M; ++i) {
        for (int j = 0; j < primes.size(); ++j)
            if (!(i % primes[j])) {
                masks[i] |= (1 << j);
            }
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    memset(prev, -1, sizeof(prev));
    memset(f, 63, sizeof(f));

    f[0][0] = 0;
    int lim = 1 << primes.size();
    for (int i = 0; i < n; ++i) {
        for (int msk = 0; msk < lim; ++msk)
            if (f[i][msk] < 5000) {
                for (int j = 1; j < 60; ++j)
                    if (!(masks[j] & msk)) {
                        int nmsk = (msk | masks[j]);
                        int nres = f[i][msk] + myabs(j - a[i]);
                        if (f[i + 1][nmsk] > nres) {
                            f[i + 1][nmsk] = nres;
                            prev[i + 1][nmsk].first = msk;
                            prev[i + 1][nmsk].second = j;
                        }
                    }
            }
    }

    int best = 0;
    for (int i = 0; i < lim; ++i)
        if (f[n][i] < f[n][best]) {
            best = i;
        }

    int x = n;
    int y = best;
    vector<int> ans;
    while (x) {
        ans.push_back(prev[x][y].second);
        y = prev[x][y].first;
        --x;
    }
    reverse(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
    cout << endl;

    return 0;
}