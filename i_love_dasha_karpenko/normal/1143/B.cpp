#include <bits/stdc++.h>

using namespace std;
#define DIM 1007
#define INF 1000000000000000007
long long n,maxd = 0,lnum,h;

long long F(long long x){
    long long res = 1;
    while(x!=0){
        res*=x%10;
        x/=10;
    }
    return res;
}
long long cn(long long x){
    long long res = 0;
    while(x!=0){
        res++;
        x/=10;
    }
    return res;
}
long long fnum(long long s){
    s--;
    long long u = n/pow(10,s);
    u *=pow(10,s);
    return u-1;
}
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%lld\n",&n);
    h = cn(n);
    maxd = max(maxd,F(n));
    lnum = fnum(h);
    for (int i = h;i>=2;i--){
        maxd = max(maxd,F(fnum(i)));
    }
    printf("%lld\n",maxd);
    //for (int i = n;i>=)
}