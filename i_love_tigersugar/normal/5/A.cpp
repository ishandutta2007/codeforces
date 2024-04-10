#include<bits/stdc++.h>
char s[308];
int n,i,l,r;
int main(void) {
    //freopen("tmp.txt","r",stdin);
    n=0;
    r=0;
    while (gets(s)) {
        l=strlen(s);
        if (s[0]=='+') {
            n++;
            continue;
        }
        if (s[0]=='-') {
            n--;
            continue;
        }
        for (i=0;i<l;i=i+1)
            if (s[i]==':') {
                r=r+(l-i-1)*n;          
                break;
            }
    }
    printf("%d",r);
    return 0;
}