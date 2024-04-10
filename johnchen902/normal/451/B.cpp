#include <cstdio>
#include <algorithm>
using namespace std;
int a[100000];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);
    if(is_sorted(a, a + n)) {
        puts("yes");
        puts("1 1");
        return 0;
    }
    int p = 1;
    while(p < n && a[p - 1] < a[p])
        p++;
    int q = p;
    while(q < n && a[q - 1] > a[q])
        q++;
    reverse(a + p - 1, a + q);
    if(is_sorted(a, a + n)) {
        puts("yes");
        printf("%d %d\n", p, q);
    } else {
        puts("no");
    }
}