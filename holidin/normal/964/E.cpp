#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;

map <long long, long long> m;
vector <pair<long long, long long > > v[N];
int top = 0;
long long a[N];

long long nod(long long a, long long b) {
    if (b > a)
        swap(a, b);
    if (b == 0)
        return a;
    else
        return nod(b, a % b);
}

int cnt = 0;

void pruf(long long u) {
    int i, j;
    for (i = 0; i < v[1].size(); ++i)
        a[i] = v[1][i].second / u;
    for (i = 1; i <= top; ++i) {
        long long q;
        if (v[i][0].second % a[0] != 0)
            return;
    }
    ++cnt;
}

long long w[N], h[N], c[N];

pair <long long, long long> del(long long a, long long b) {
    return {a / nod(a, b), b / nod(a, b)};
}

void ex() {
    cout << 0;
    exit(0);
}

int main() {
    long long i, j, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> w[i] >> h[i] >> c[i];
        if (m[w[i]] == 0) {
            ++top;
            m[w[i]] = top;
        }
        v[m[w[i]]].push_back({h[i], c[i]});
    }
    for (i = 1; i <= top; ++i) {
        sort(v[i].begin(), v[i].end());
        if (v[i].size() != v[1].size())
            ex();
        for (j = 0; j < v[i].size(); ++j) {
            if (v[i][j].first != v[1][j].first)
                ex();
            if (del(v[i][j].second, v[1][j].second) != del(v[i][0].second, v[1][0].second))
                ex();
        }
        vector <int> u;
    }
    long long nd = 0;
    for (i = 0; i < v[1].size(); ++i)
        nd = nod(nd, v[1][i].second);
    for (i = 1; i * i <= nd; ++i)
    if (nd % i == 0) {
        pruf(i);
        if (i != nd / i)
            pruf(nd / i);
    }
    cout << cnt;
}