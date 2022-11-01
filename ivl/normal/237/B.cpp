#include <cstdio>
#include <vector>
#define x first
#define y second
#include <algorithm>

using namespace std;

int n;
int c[55];
int a[55][55];

pair < int, int > inv[2505];

vector < pair < pair < int, int >, pair < int, int > > > OUT;

void swap_my(int a, int b){
     pair < int, int > x = inv[a], y = inv[b];
     OUT.push_back(make_pair(x, y));
     swap(::a[x.x][x.y], ::a[y.x][y.y]);
     swap(inv[a], inv[b]);
}

int main(){
    scanf("%d", &n);
    int s = 0;
    for (int i = 0; i < n; ++i){
        scanf("%d", c + i);
        s += c[i];
    }
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < c[i]; ++j){
        int x;
        scanf("%d", &x);
        a[i][j] = x;
        inv[x] = make_pair(i, j);
    }
    int p = 1;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < c[i]; ++j, ++p)
    if (a[i][j] != p)
    swap_my(a[i][j], p);
    printf("%d\n", OUT.size());
    for (int i = 0; i < OUT.size(); ++i) printf("%d %d %d %d\n", OUT[i].x.x + 1, OUT[i].x.y + 1, OUT[i].y.x + 1, OUT[i].y.y + 1);
    return 0;
}