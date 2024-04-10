//Problem A
#include<bits/stdc++.h>
using namespace std;
int rd(){
    int a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
    return a;
}

int n;

int main(){
    scanf("%d",&n);
    if(n%3)printf("1 2 %d",n-3);else printf("1 1 %d",n-2);
    return 0;
}