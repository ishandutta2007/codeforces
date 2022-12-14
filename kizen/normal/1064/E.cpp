#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    int l = 0, r = (int)1e9, mid;
    scanf("%d", &N);
    printf("0 1\n");
    fflush(stdout);
    char A[10];
    scanf("%s", A);
    N--;
    while(N--){
        mid = (l+r)/2;
        printf("%d 1\n", mid);
        fflush(stdout);
        char s[10]; scanf("%s", s);
        if(s[0]==A[0]) l = mid;
        else r = mid;
    }
    mid = (l+r)/2;
    printf("%d %d %d %d\n", l, 0, r, 2);
    fflush(stdout);
    return 0;
}