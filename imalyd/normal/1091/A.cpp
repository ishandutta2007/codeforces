//Problem A
#include<bits/stdc++.h>
using namespace std;

int a,b,c;

int main(){
    scanf("%d%d%d",&c,&b,&a);
    int x=min(c,min(a-2,b-1));
    printf("%d",x*3+3);
    return 0;
}