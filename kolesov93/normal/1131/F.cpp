#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

const int N = 150111;
int w[N + N], who[N + N];
int ls[N + N], rs[N + N];
int n;

int fath(int x) {
    if (x == w[x]) return w[x];
    w[x] = fath(w[x]);
    return w[x];
}

void un(int a, int b){
    w[fath(a)] = fath(b);
}

void dfs(int x) {
    if (x < n) {
        printf("%d ", x + 1);
        return;
    }
    dfs(ls[x]); dfs(rs[x]);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n + n; ++i) {
        w[i] = i;
    }
    for (int i = 0; i + 1 < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        a -= 1; b -= 1;
        int father = n + i;
        ls[father] = fath(a);
        rs[father] = fath(b);
        un(a, b);
        un(a, father);
    }

    dfs(n + n - 2);
    cout << endl;

    return 0;
}