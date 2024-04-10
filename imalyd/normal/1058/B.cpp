//Problem B
#include<bits/stdc++.h>
using namespace std;
int rd(){
    int a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
    return a;
}

int n,d,m;

int main(){
    scanf("%d%d%d",&n,&d,&m);
    while(m--){
        int a,b,c=0;
        scanf("%d%d",&a,&b);
        if(a+b<d||a+b>n+n-d)c=1;
        if(a-b>d||a-b<-d)c=1;
        if(c)printf("No\n");else printf("Yes\n");
    }
    return 0;
}