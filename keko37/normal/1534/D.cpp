#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 2005;

int n, br[2], c;
int col[MAXN], d[MAXN];
bool e[MAXN][MAXN];

void add_edge (int a, int b) {
    e[a][b] = e[b][a] = 1;
}

void pitaj (int x) {
    cout << "? " << x << endl;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    pitaj(1);
    for (int i = 1; i <= n; i++) {
        if (d[i] == 1) add_edge(1, i);
        col[i] = d[i] % 2;
        br[col[i]]++;
    }
    if (br[0] <= br[1]) c = 0; else c = 1;
    for (int i = 2; i <= n; i++) {
        if (col[i] != c) continue;
        pitaj(i);
        for (int j = 1; j <= n; j++) {
            if (d[j] == 1) add_edge(i, j);
        }
    }
    cout << "!" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (e[i][j]) cout << i << " " << j << endl;
        }
    }
    return 0;
}