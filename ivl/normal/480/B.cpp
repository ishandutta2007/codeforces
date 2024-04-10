#include <cstdio>

using namespace std;

int n, l, x, y;
int a[100005];

int find(int d, int limit = -1){
    int p = 0;
    for (int i = 0; i < n; ++i){
        while (a[i] - a[p] > d) ++p;
        if (a[i] - a[p] == d){
           if (limit == -1) return p;
           if (a[p] >= limit || l - a[i] >= limit) return p;
        }
    }
    return -1;
}

int main(){
    scanf("%d%d%d%d", &n, &l, &x, &y);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    int b1 = find(x), b2 = find(y);
    if (b1 != -1 && b2 != -1){printf("0\n"); return 0;}
    if (b1 != -1 || b2 != -1){printf("1\n%d\n", (b1 == -1) * x + (b2 == -1) * y); return 0;}
    int b = find(y - x, x);
    if (b != -1){
       if (a[b] >= x) printf("1\n%d\n", a[b] - x);
       else printf("1\n%d\n", a[b] + y);
       return 0;
    }
    b = find(x + y);
    if (b == -1){printf("2\n%d %d\n", x, y); return 0;}
    printf("1\n%d\n", a[b] + x);
    return 0;
}