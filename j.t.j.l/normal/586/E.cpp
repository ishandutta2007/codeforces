#include<bits/stdc++.h>

using namespace std;

long long a[10000];
int b[10000];

int main(){
    long long x, y;
    int flag;
    cin>>x>>y;
    if (x > y)
        flag = 1;
    else{
        flag = 0;
        swap(x, y);
    }
    int cnt = 0;
    while(y != 1){
        if (x%y == 0){
            puts("Impossible");
            return 0;
        }
        cnt++;
        a[cnt] = x / y;
        b[cnt] = flag;
        flag = 1 - flag;
        long long tmp = x % y;
        x = y;
        y = tmp;
    }
    cnt++;
    a[cnt] = x - 1;
    b[cnt] = flag;
    for(int i = 1; i <= cnt; i++){
        printf("%I64d%c", a[i], "BA"[b[i]]);
    }
    puts("");
    return 0;
}