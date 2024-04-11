#include <cstdio>
#include <cstdlib>

int a[2005], dx[2005];
int n,h;
long long mod = 1e9 + 7;

void input(){
    scanf("%d %d",&n,&h);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
        if(a[i] > h){
            puts("0");
            exit(0);
        }
    }
    for (int i=0; i<n; i++) {
        a[i] = h - a[i];
    }
    dx[0] = a[0];
    if(dx[0] > 1 || dx[0] < -1){
        puts("0");
        exit(0);
    }
    for (int i=1; i<n; i++) {
        dx[i] = a[i] - a[i-1];
        if(dx[i] > 1 || dx[i] < -1){
            puts("0");
            exit(0);
        }
    }
    dx[n] = -a[n-1];
    if(dx[n] > 1 || dx[n] < -1){
        puts("0");
        exit(0);
    }
}

int main(){
    input();
    int nowone = 0;
    long long res = 1;
    for (int i=0; i<=n; i++) {
        if(dx[i] == 1){
            nowone++;
        }
        else if(dx[i] == -1){
            res *= nowone;
            res %= mod;
            nowone--;
        }
        else{
            res *= nowone + 1;
            res %= mod;
        }
    }
    printf("%I64d",res);
}