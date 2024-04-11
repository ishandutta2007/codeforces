#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);
const int N = 1000111;

int a[N], t[N], x[N], d[N];
unordered_map<int, int> q;
int sz = 0;
vector<int> sums[N];
vector<int> times[N];

inline int prev(int x) {
    return x & (x - 1);
}
inline int next(int x) {
    return x + x - prev(x);
}

void modify(vector<int>& a, size_t pos, int value) {
    ++pos;
    while (pos < a.size()) {
        a[pos] += value;
        pos = next(pos);
    }
}

int findsum(vector<int>& a, size_t pos) {
    ++pos;
    int result = 0;
    while (pos) {
        result += a[pos];
        pos = prev(pos);
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", a + i, t + i, x + i);

        auto it = q.find(x[i]);
        if (it == q.end()) {
            q[x[i]] = sz++;
            x[i] = sz - 1;
        } else {
            x[i] = it->second;
        }

        d[x[i]]++;
    }

    for (int i = 0; i < sz; ++i) {
        sums[i].resize(d[i] + 3);
        times[i].reserve(d[i] + 3);
    }
    for (int i = 0; i < n; ++i) {
        times[x[i]].push_back(t[i]);
    }
    for (int i = 0; i < sz; ++i) {
        sort(begin(times[i]), end(times[i]));
    }

    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(begin(times[x[i]]), end(times[x[i]]), t[i]) - begin(times[x[i]]);
        if (a[i] == 1) {
            modify(sums[x[i]], pos, 1); 
        } else if (a[i] == 2) {
            modify(sums[x[i]], pos, -1); 
        } else {
            printf("%d\n", findsum(sums[x[i]], pos));
        }
    }

    return 0;
}