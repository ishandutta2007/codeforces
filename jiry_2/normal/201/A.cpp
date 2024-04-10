#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int x,n;
int rank(int k1,int k2){
    if (k2%2==0){
        if (k1%2==0) return (k1*k1+1)/2; else return (k1*k1-1)/2;
    } else if (k1%2==0) return (k1*k1-1)/2; else return (k1*k1+1)/2;
}
int main(){
    scanf("%d",&x);
    if (x%4-x%2==2&&x%2==1) n=5; else n=1;
    for (;;n+=2) if (rank(n,x)>=x) break;
    printf("%d\n",n); return 0;
}