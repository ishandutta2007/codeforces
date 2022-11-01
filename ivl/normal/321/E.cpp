#include <cstdio>
#include <algorithm>

#define FOR(a,b,c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) for (int _rep = 0, _for = (n); _rep < _for; ++_rep)
#define ll long long
#define pii pair < int, int >
#define x first
#define y second
#define pb push_back

using namespace std;

void ReadInt(int &x){
    x = 0;
    char c = '\0';
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9'){
        x = x * 10 + c - '0';
        c = getchar();
    }
}

const int oo = 1000000000;

int n, k;
int a[4005][4005];

int cost(int x, int y){
    //if (x > y) return 0;
    return a[y + 1][y + 1] - a[x][y + 1] - a[y + 1][x] + a[x][x];
}

int memo[805][4005];

void Solver(int k, int lo, int hi, int slo, int shi){
    if (lo > hi) return;
    int mid = (lo + hi) / 2;
    int best = slo;
    memo[k][mid] = oo;
    FOR(slo, min(shi + 1, mid), i){
        int curr = memo[k - 1][i] + cost(i, mid - 1);
        if (memo[k][mid] > curr) memo[k][mid] = curr, best = i;
    }
    Solver(k, lo, mid - 1, slo, best);
    Solver(k, mid + 1, hi, best, shi);
}

int main(){
    scanf("%d%d", &n, &k);
    FOR(1, n + 1, i) FOR(1, n + 1, j) ReadInt(a[i][j]), a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];

    memo[0][0] = 0;
    FOR(1, n + 1, i) memo[0][i] = oo;

    FOR(1, k + 1, i)
        Solver(i, 0, n, 0, n);

    printf("%d\n", memo[k][n] / 2);

    return 0;
}