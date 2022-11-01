#include <cstdio>

using namespace std;

int loga[2005];
void add(int pos, int val){
     while (pos < 2004){
           loga[pos] += val;
           pos += (pos & -pos);
     }
}
int sum(int pos){
    int r = 0;
    while (pos){
          r += loga[pos];
          pos -= (pos & -pos);
    }
    return r;
}
void inc(int a, int b){add(a, 1); add(b + 1, -1);}

int m, t, r;
int a[305];

int main(){
    scanf("%d%d%d", &m, &t, &r);
    for (int i = 0; i < m; ++i) scanf("%d", a + i), a[i] += 500;
    if (t < r){printf("-1\n"); return 0;}
    int sol = 0;
    for (int i = 0; i < m; ++i){
        int x = a[i];
        int y = sum(x);
        for (int j = 0; j < r - y; ++j)
            inc(x - j, x + t - 1 - j);
        sol += r - y;
    }
    printf("%d\n", sol);
    return 0;
}