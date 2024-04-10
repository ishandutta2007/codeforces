#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <assert.h>
#include <stack>
#include <unistd.h>
#include <bitset>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second
#define ll long long
#define TRACE(x) cerr << #x << " = " << x << endl

using namespace std;

int n, m;
char in[505][505];

bitset < 505 > B[12][505][505];

void BuildDiv(int lo, int hi, int dep = 0){
    if (lo > hi) return;
    int mid = (lo + hi) / 2;
    REP(m,i) if (in[mid][i] == '.') B[dep][mid][i] [i] = 1;
    for (int i = mid; i >= lo; --i)
        for (int j = m - 1; j + 1; --j)
            if (in[i][j] == '.'){
                if (i != lo) B[dep][i - 1][j] |= B[dep][i][j];
                if (j) B[dep][i][j - 1] |= B[dep][i][j];
            }
    REP(m,i) if (in[mid][i] == '.') B[dep][mid][i].reset(), B[dep][mid][i] [i] = 1;
    FOR(mid,hi+1,i) FOR(0,m,j) if (in[i][j] == '.'){
        if (i != hi) B[dep][i + 1][j] |= B[dep][i][j];
        if (j != m - 1) B[dep][i][j + 1] |= B[dep][i][j];
    }
    //REP(m,i) if (in[mid][i] == '.') B[dep][mid][i].reset(), B[dep][mid][i] [i] = 1;
    BuildDiv(lo, mid - 1, dep + 1);
    BuildDiv(mid + 1, hi, dep + 1);
}

bool Find(int lo, int hi, int dep, pii a, pii b){
    int mid = (lo + hi) / 2;
    if (a.x <= mid && mid <= b.x){
        //cout << lo << " " << hi << " " << mid << endl;
        //cout << B[dep][a.x][a.y] << endl << B[dep][b.x][b.y] << endl;
        if (a.x != mid && b.x != mid || a.x == mid && b.x == mid) return (B[dep][a.x][a.y] & B[dep][b.x][b.y]).count();
        if (b.x == mid) swap(a, b);
        return B[dep][b.x][b.y] [a.y];
    }
    if (a.x <= mid && b.x < mid){
        return Find(lo, mid - 1, dep + 1, a, b);
    }
    if (mid < a.x && mid <= b.x){
        return Find(mid + 1, hi, dep + 1, a, b);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    REP(n,i) scanf("%s", in[i]);
    BuildDiv(0, n - 1);
    int q;
    scanf("%d", &q);
    REP(q,t){
        pii a, b;
        scanf("%d%d%d%d", &a.x, &a.y, &b.x, &b.y), --a.x, --a.y, --b.x, --b.y;
        if (in[a.x][a.y] == '.' && in[b.x][b.y] == '.' && Find(0, n - 1, 0, a, b)) printf("Yes\n"); else printf("No\n");
    }
    return 0;
}