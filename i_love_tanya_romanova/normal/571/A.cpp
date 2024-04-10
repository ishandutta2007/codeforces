/*
This Halloween so unlike any other
Her final words don't be afraid
Of the green light, of the green light
Green light
Baby, baby

On muddy ground, I'm lying drunk on her grave
Where I must wait until she wakes
The soil splits, Greenwood's ground will quake beneath me
And so shall take into the earth
To the green light, to the green light
Baby, baby, baby

The autumn air thickly fills my lungs so sweetly
Reminds me of her smoky breath
With wine and this bouquet of maple and oak leaves
In death or life we'll always be

I find myself drawn to her shadow domain
I find myself drawn to her shadow domain
I find myself drawn to her shadow domain

This moonlit night late October's swirlin' fog gloom
And as promised, my love did rise
From the green light, from the green light
Green light

I find myself drawn to her shadow domain
I find myself drawn to her shadow domain
I find myself drawn to her shadow domain

Quiet, quiet, quiet, quiet
*/
 
//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>  
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime> 

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512
#define time asdfasdfasfd

using namespace std;

long long ttl,a,b,c,l;

long long C(long long n,long long m)
{
    long long res=1;
    for (long long i=n;i>n-m;i--)
        res*=i;
    for (long long i=1;i<=m;i++)
        res/=i;
    return res;
}

long long solve(long long a,long long b,long long c)
{
    long long ta,tb,tc;
    long long res=0;
    for (int adda=0;adda<=l;adda++)
    {
        ta=a+adda;
        tb=b;
        tc=c;
        long long rem=ta-tb-tc;
        rem=min(rem,l-adda);
        if (rem<0)
            continue;
        res+=C(rem+2,2);
    }
    return res;
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>a>>b>>c>>l;

ttl=C(l+3,3);

ttl-=solve(a,b,c);
ttl-=solve(b,a,c);
ttl-=solve(c,a,b);
cout<<ttl<<endl;

//cin.get();cin.get();
return 0;}