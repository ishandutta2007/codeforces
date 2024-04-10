#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int par[100001];

int find(int x) {
    if (par[x]) return par[x] = find(par[x]);
    return x;
}

int n, m;
int A[1000001];
int B[1000001];
int E[1000001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vector<int> ord;
    for (int i = 1; i <= m; ++i) {
        cin >> A[i] >> B[i] >> E[i];
        if (i > 1) ord.push_back(i);
    }
    sort(ord.begin(), ord.end(), [&](int a, int b) {
        return E[a] < E[b];
    });
    for (int i : ord) {
        int x = find(A[i]);
        int y = find(B[i]);
        if (x != y) par[y] = x;
        if (find(A[1]) == find(B[1])) {
            printf("%d\n", E[i]);
            return 0;
        }
    }
    printf("%d\n", (int)1e9);
    return 0;
}