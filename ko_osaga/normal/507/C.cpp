#include <cstdio>
long long obj;
int n;

long long f(int h, int right){
    if(h == n) return 1;
    if(right != (obj>>(n - h - 1))%2) return f(h+1,right) + (1ll<<(n - h));
    else return f(h+1,1 - right) + 1;
}

int main(){
    scanf("%d %I64d",&n,&obj);
    obj--;
    printf("%I64d",f(0,0) - 1);
}