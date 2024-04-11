//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

long long maks;
int ra, rb, rc, rd, re, rf, rg, rh;
int n, m;

void check(int a, int b, int c, int d, int e, int f, int g, int h, int wsk)
{
    if(wsk==0)
    {
        check(a,b,c-1,d,e,f,g,h,1);
        check(a,b,c+1,d,e,f,g,h,1);
        check(a,b,c-1,d,e-1,f,g,h,1);
        check(a,b,c+1,d,e+1,f,g,h,1);
        check(a,b,c,d-1,e,f,g,h,1);
        check(a,b,c,d+1,e,f,g,h,1);
        check(a,b,c,d-1,e,f-1,g,h,1);
        check(a,b,c,d+1,e,f+1,g,h,1);
    }
    if(a > n || c > n || e > n || g > n || b > m || d > m || f > m || h > m || a < 0 || c < 0 || e < 0 || g < 0 || b < 0 || d < 0 || f < 0 || h < 0)
        return;
    if(a==c && b==d)
        return;
    if(a==e && b==f)
        return;
    if(a==g && b==h)
        return;
    if(c==e && d==f)
        return;
    if(c==g && d==h)
        return;
    if(e==g && f==h)
        return;
    long long res = (c-a)*(c-a)+(e-c)*(e-c)+(g-e)*(g-e)+(d-b)*(d-b)+(f-d)*(f-d)+(h-f)*(h-f);
    if(maks < res)
    {
        maks = res;
        ra = a;
        rb = b;
        rc = c;
        rd = d;
        re = e;
        rf = f;
        rg = g;
        rh = h;
    }
}

void wypisz(int a, int b)
{
    cout << a << " " << b << "\n";
}

void test()
{
    cin >> n >> m;
    check(0,1,0,m,0,0,0,m-1,0);
    check(1,0,n,0,0,0,n-1,0,0);
    check(0,0,n,m,1,1,n-1,m-1,0);
    check(n,m,0,0,0,m,n,0,0);
    check(0,0,n,m,0,m,n,0,0);
    check(0,0,m/3,n,2*m/3,0,m,n,0);
    check(0,0,m,n/3,0,2*n/3,m,n,0);
    check(0,0,n,m,0,1,n,m-1,0);
    check(0,0,n,m,1,0,n-1,m,0);
    check(0,1,n,m,0,0,n,m-1,0);
    check(1,0,n,m,0,0,n-1,m,0);
    wypisz(ra,rb);
    wypisz(rc,rd);
    wypisz(re,rf);
    wypisz(rg,rh);
}

int main()
{
    int t;
    t = 1;
    while(t--)
        test();
    return 0;
}