#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int c[13];
int main(void) {
    int k;
    scanf("%d",&k);
    REP(i,4) {
        char s[13];
        scanf("%s",s);
        REP(j,4) if (s[j]!='.') c[s[j]-48]++;
    }
    REP(i,9) if (c[i+1]>2*k) {
        printf("NO");
        return 0;
    }
    printf("YES");
    return 0;
}