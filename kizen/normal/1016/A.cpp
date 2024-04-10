#include <bits/stdc++.h>

using namespace std;

int N, M;
int cnt;

int main(){
    scanf("%d %d", &N, &M);
    while(N--){
        int a;
        scanf("%d", &a);
        cnt += a;
        printf("%d ", cnt/M);
        cnt %=M;
    }

    return 0;
}