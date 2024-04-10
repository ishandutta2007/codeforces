/*
I always thought we'd be together
And that our love could not be better
Well, with no warning you were gone
I still don't know what went wrong
You don't know what I've been through
Just want to put my love in you

No more nights of blood and fire
All those special memories
Now I bleed for you, burn for me
Perhaps I was just dreaming
When I think these things had real meaning
You don't know what I've been through
Just want to put my love in you

Love eternal
Lust infernal
Bleeding, burning
Needing, yearning

I see your face in every flame
With no answers, I have only myself to blame
Of all the women, I have known they're not you
I'd rather be alone

No more nights of blood and fire
All those special memories
Now I bleed for you, burn for me
Perhaps I was just dreaming
When I think these things had real meaning
You don't know what I've been through
Just want to put my love in you
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