#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 111;
const long long INF = 1e9 + 19;

int a[N][N];
int b[N][N];
int n, m, q;


void read() {
    scanf("%d%d%d", &n, &m, &q);
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            a[i][j] = i * m + j;
    }

    for (int i = 0; i < q; i++) {
        int type; 
        scanf("%d", &type);
        if (type == 1) {
            int x;
            scanf("%d", &x); x--;
            for (int j = 0; j + 1 < m; j++)
                swap(a[x][j], a[x][j + 1]);
        }
        if (type == 2) {
            int x;
            scanf("%d", &x); x--;
            for (int i = 0; i + 1 < n; i++)
                swap(a[i][x], a[i + 1][x]);
        }
        if (type == 3) {
            int x, y, val;
            scanf("%d%d%d", &x, &y, &val); x--; y--;
            int id = a[x][y];
            int x1 = id / m;
            int y1 = id % m;
            b[x1][y1] = val;
        }
    }
    for (int i = 0; i < n; i++, puts(""))
        for (int j = 0; j < m; j++)
            printf("%d ", b[i][j]);
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}