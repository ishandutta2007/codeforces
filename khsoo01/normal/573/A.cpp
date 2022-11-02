#include<bits/stdc++.h>
int n,a,prev;

int main()
{
    int i;
    scanf("%d",&n);
    scanf("%d",&a);
    while(a%2==0)a/=2;
    while(a%3==0)a/=3;
    prev=a;
    for(i=1;i<n;i++) {
        scanf("%d",&a);
        while(a%2==0)a/=2;
        while(a%3==0)a/=3;
        if(prev!=a) {puts("NO");return 0;}
    }
    puts("YES");
}