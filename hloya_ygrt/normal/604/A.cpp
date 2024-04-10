#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
#include <list>
#include <stdio.h>
#include <string>

const int maxn=2e5;
const int inf=2e9;
const int eps=1e-9;
const int minf=-2e9;

#define mp make_pair
#define f first
#define sec second
#define pb push_back
#define ll long long
#define ld long double

#define forn() for(int i=0;i<n;i++)
#define nfor() for(int i=n-1;i>=0;i--)

using namespace std;
int m[5],w[5],x3[5],x250[5];
int main()
{
    int s=0;
    int x=500;

   // scanf("%d",&n);
    for (int i=0;i<5;i++)
        scanf("%d",&m[i]);
      for (int i=0;i<5;i++)
        scanf("%d",&w[i]);
    x3[0]=150;x250[0]=2;
    x3[1]=300;x250[1]=4;
    x3[2]=450;x250[2]=6;
    x3[3]=600;x250[3]=8;
    x3[4]=750;x250[4]=10;
    for (int i=0;i<5;i++)
    {


        int r=max(x3[i],x-x250[i]*m[i]-50*w[i]);

        s+=r;
        x+=500;
    }

    int a,b;
    scanf("%d %d",&a,&b);
    s+=100*a;
    s-=50*b;

    printf("%d",s);
    return 0;
}