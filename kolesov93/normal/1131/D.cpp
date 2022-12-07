#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

const int N = 2222;
int w[N];
int mark[N], d[N];
char a[N][N];
vector<int> edges[N];

int fath(int x) {
    if (w[x] == x) return x;
    w[x] = fath(w[x]);
    return w[x];
}
void un(int a, int b) {
    w[fath(a)] = fath(b);
}

int main() {
    int n, m;
    cin >> n >> m;
    scanf("\n");
    for (int i = 0; i < n + m; ++i) w[i] = i;

    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '=') {
                un(i, n + j);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != '=') {
                int A = fath(i), B = fath(n + j);
                if (a[i][j] == '<') {
                    edges[A].push_back(B);
                    d[B]++;
                } else {
                    edges[B].push_back(A);
                    d[A]++;
                }
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < n + m; ++i) {
        if (d[i] == 0) {
            q.push(i);
            mark[i] = 1;
        }
    }

    int processed = 0;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        ++processed;

        for (int e: edges[x]) {
            d[e]--;
            if (d[e] == 0) {
                q.push(e);
                mark[e] = max(mark[e], mark[x] + 1);
            }
        }
    }

    if (processed != n + m) {
        puts("No");
        return 0;
    }

    puts("Yes");
    for (int i = 0; i < n; ++i) printf("%d ", mark[fath(i)]);
    cout << endl;
    for (int i = 0; i < m; ++i) printf("%d ", mark[fath(n + i)]);
    cout << endl;
    return 0;
}