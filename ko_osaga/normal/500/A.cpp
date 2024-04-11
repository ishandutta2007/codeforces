#include <cstdio>

int a[30005], n,t;

int f(int x){
    if(x == t) return 1;
    if(x == n) return 0;
    return f(x + a[x]);
}
int main(){
    scanf("%d %d",&n,&t);
    for (int i=1; i<n; i++) {
        scanf("%d",&a[i]);
    }
    printf(f(1)?"YES":"NO");
}