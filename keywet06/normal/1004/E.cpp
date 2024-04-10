#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int isNotPath(int pqs, int m) {
    if (pqs > 2) return 1;
    return 0;
}

int n, k, u, v, d, temp, done, res;
int A[N], L[N], numC[N];

map<int, int> B[N];

priority_queue<pair<int, int>> pq;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v >> d;
        B[u - 1][v - 1] = d;
        B[v - 1][u - 1] = d;
        A[i] = 0;
    }
    A[n - 1] = 0;
    for (int i = 0; i < n; ++i) {
        if (B[i].size() == 1) {
            auto x = B[i].begin();
            pq.emplace(-x->second, i);
        }
    }
    int m = n;
    while (m > k || pq.size() > 2) {
        pair<int, int> z = pq.top();
        pq.pop();
        int d = -z.first;
        int i = z.second;
        res = d;
        --m;
        int x = B[i].begin()->first;
        B[i].clear();
        B[x].erase(i);
        i = x;
        if (B[i].size() == 1) {
            auto x = B[i].begin();
            pq.emplace(-x->second - d, i);
        }
    }
    cout << res << endl;
    return 0;
}