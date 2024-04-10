#include <cstdio>
#include <algorithm>
using namespace std;
int a[100][4];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        a[i][0] = i * 2 + 1;
        a[i][3] = i * 2 + 2;
        a[i][1] = n * 2 + i * 2 + 1;
        a[i][2] = n * 2 + i * 2 + 2;
    }
    for(int i = 0; i < n; i++) {
        if(a[i][1] <= m) printf("%d ", a[i][1]);
        if(a[i][0] <= m) printf("%d ", a[i][0]);
        if(a[i][2] <= m) printf("%d ", a[i][2]);
        if(a[i][3] <= m) printf("%d ", a[i][3]);
    }
}