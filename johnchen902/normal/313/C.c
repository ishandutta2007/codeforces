#include <stdio.h>
#include <stdlib.h>

int a[2000000];

int cmp(const void*i, const void*j){
    return *(int*)j - *(int*)i;
}
int main(){
    int nn, i, m = 0, j;
    long long s = 0;
    scanf("%d", &nn);
    for(i = 0; i < nn; i++)
        scanf("%d", a + i);
    qsort(a, nn, sizeof(int), cmp);
    for(i = 1; i <= nn; i <<= 2)
        m++;
    for(i = 1, j = 0; i <= nn; i <<= 2, m--)
        for(; j < i; j++)
            s += a[j] * (long long)m;
    printf("%I64d\n", s);
    // system("pause");
    return 0;
}