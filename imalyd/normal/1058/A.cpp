//Problem A
#include<bits/stdc++.h>
using namespace std;
int rd(){
    int a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
    return a;
}

int n,a,b;

int main(){
    scanf("%d",&n);
    while(n--)scanf("%d",&a),b|=a;
    if(b)printf("Hard");else printf("Easy");
    return 0;
}