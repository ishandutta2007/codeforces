//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

bool czy;
long long n, k, d1, d2, rest;

void check(long long a, long long b, long long c)
{
    long long y = min(a,min(b,c));
    if(y > 0)
        y = 0;
    a -= y;
    b -= y;
    c -= y;
    if(a+b+c > k)
        return;
    if((k - a-b-c)%3 != 0)
        return;
    long long x = max(a,max(b,c));
    long long wyn = 3*x-a-b-c;
    if(wyn<=rest && (rest-wyn)%3==0)
        czy = true;
    //printf("%lld %lld %lld %d\n", a, b, c, czy);
    return;
}

void test()
{
    czy = false;
    scanf("%lld%lld%lld%lld", &n, &k, &d1, &d2);
    rest = n-k;
    check(0,d1,d1+d2);
    check(d1,0,d2);
    check(0,d1,d1-d2);
    check(d1+d2,d2,0);
    check(d2-d1,d2,0);
    puts(czy ? "yes" : "no");
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        test();
    return 0;
}