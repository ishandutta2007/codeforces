#include <cstdio>
#include <cstdlib>

int n, m;
int a[200000];

void t1(int x, int v){
    a[x - 1] = v;
}
int t2(int l, int r){
    unsigned long long sum = 0;
    unsigned long long fibo = 1, last = 0;
    for(int i = l; i <= r; i++){
        sum += fibo * (unsigned long long)a[i - 1];
        sum %= 1000000000;
        unsigned long long tmp = fibo;
        fibo += last;
        fibo %= 1000000000;
        last = tmp;
    }
    return (int)sum;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);
    for(int i = 0; i < m; i++){
        int t, xl, vr;
        scanf("%d%d%d", &t, &xl, &vr);
        switch(t){
        case 1: t1(xl, vr); break;
        case 2: printf("%d\n", t2(xl, vr)); break;
        }
    }
    // system("pause");
    return 0;
}