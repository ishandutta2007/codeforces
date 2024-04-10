#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int tt;
    int n,x,a,b;
    scanf("%d",&tt);
    while (tt--){
        scanf("%d%d%d%d",&n,&x,&a,&b);
        printf("%d\n",min(n-1,abs(a-b)+x));
    }
    return 0;
}