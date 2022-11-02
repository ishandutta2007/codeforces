#include<bits/stdc++.h>
typedef long long ll;
int n,m=1,w=5,x[13]{0,31,29,31,30,31,30,31,31,30,31,30,31},c;
char a[105],b[105];

int main()
{
    int i,j;
    scanf("%d%s%s",&n,&a,&b);
    if(b[0]=='w') {
        for(i=1,j=1;m<=12;i++) {
            if(w==n) c++;
            w++; j++;
            if(j>x[m]) {
                m+=1;
                j=1;
            }
            if(w>7) w=1;
        }
    }
    else {
        for(i=1,j=1;m<=12;i++) {
            if(j==n) c++;
            w++; j++;
            if(j>x[m]) {
                m+=1;
                j=1;
            }
            if(w>7) w=1;
        }
    }
    printf("%d",c);
}