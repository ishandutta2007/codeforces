#include <bits/stdc++.h>
using namespace std;

#define N 111111

vector<int> adj[N];

double solve(int i, int p = -1) {
    double total = 0;
    int size = 0;
    for (int j : adj[i]) {
        if (j == p) continue;
        total += solve(j, i);
        size++;
    }
    return size ? 1 + total / size : 0;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    printf("%.11lf\n", solve(0));
}