#include<bits/stdc++.h>
#define MAX   10101
char s[MAX];
int pw[11];
void precal(void) {
    pw[0]=1;
    int i;
    for (i=1;i<=5;i=i+1) pw[i]=pw[i-1]*26;
}
void process(void) {
    int i,n,t,r,c,l,j;
    scanf("%s",s);  
    n=strlen(s);
    t=2;
    for (i=1;i<n;i=i+1)
        if (s[i]=='C' && '0'<=s[i-1] && s[i-1]<='9') {
            t=1;
            break;
        }
    if (t==1) {
        i=1;
        r=0;
        while (s[i]!='C') {
            r=10*r+s[i]-48;
            i=i+1;
        }
        i=i+1;
        c=0;
        while (i<n) {
            c=10*c+s[i]-48;
            i=i+1;
        }
        for (l=1;l<=5;l=l+1) {
            if (c>pw[l]) c=c-pw[l];
            else break;
        }
        for (i=1;i<=l;i=i+1)
            for (j='A';j<='Z';j=j+1) {
                if (c>pw[l-i]) c=c-pw[l-i];
                else {
                    printf("%c",j);
                    break;
                }
            }
        printf("%d\n",r);
    }
    else {
        l=0;
        while (s[l]>'9') l++;
        c=0;
        for (i=1;i<l;i=i+1) c=c+pw[i];
        for (i=0;i<l;i=i+1) c=c+(s[i]-'A')*pw[l-i-1];
        c++;
        r=0;
        for (i=l;i<n;i=i+1) r=10*r+s[i]-48;
        printf("R%dC%d\n",r,c);
    }
}
int main(void) {
    precal();
    int t,i;
    scanf("%d",&t);
    for (i=1;i<=t;i=i+1) process();
    return 0;
}