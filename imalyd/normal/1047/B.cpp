//Problem B
#include<bits/stdc++.h>
using namespace std;
int rd(){
    int a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
    return a;
}

int n,a,b,c;

int main(){
    scanf("%d",&n);
    while(n--)scanf("%d%d",&a,&b),c=max(c,a+b);
    printf("%d",c);
    return 0;
}