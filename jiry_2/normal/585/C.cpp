#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct point{
    long long x,y;
}A,B;
int flag=0,ans[100000],fir;
long long x,y;
long long gcd(long long k1,long long k2){
    if (k2==0) return k1; return gcd(k2,k1%k2);
}
void findans(long long k1,long long k2){
    if (k1==1&&k2==1) return;
    if (k1>k2){
        long long num=k1/k2; if (k2==1) num--;
        printf("%I64dA",num); findans(k1-num*k2,k2);
    } else {
        long long num=k2/k1; if (k1==1) num--;
        printf("%I64dB",num); findans(k1,k2-num*k1);
    }
}
int main(){
    scanf("%I64d%I64d",&x,&y);
    if (gcd(x,y)>1){printf("Impossible\n"); return 0;}
    findans(x,y); putchar('\n');
    return 0;
}