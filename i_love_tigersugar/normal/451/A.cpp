#include<bits/stdc++.h>
const char win[]="Akshat";
const char lose[]="Malvika";
int main(void) {
    int m,n;
    scanf("%d%d",&m,&n);
    if (m>n) m=n;
    if (m%2) printf("%s",win); else printf("%s",lose);
}