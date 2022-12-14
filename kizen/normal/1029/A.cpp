#include <bits/stdc++.h>

using namespace std;

int N, k;
char s[2504];

int main(){
    scanf("%d %d", &N, &k);
    scanf("%s", s);

    int big = 0;
    for(int i=N-1;i>=1;--i){
        int f = 1;
        for(int j=0;j<i;++j) if(s[j]!=s[N-i+j]){
            f = 0; break;
        }
        if(f){
            big = i; break;
        }
    }
    int M = N;
    while(--k){
        for(int i=big;i<M;++i) s[N++] = s[i];
    }
    s[N++] = 0;
    printf("%s", s);

    return 0;
}