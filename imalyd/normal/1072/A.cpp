//Problem A
#include<bits/stdc++.h>
using namespace std;
int a,b,c,x,s;
int main(){
    scanf("%d%d%d",&a,&b,&c);
    x=a+a+b+b-4;
    for(int i=1;i<=c;i++)s+=x,x-=16;
    printf("%d",s);
    return 0;
}