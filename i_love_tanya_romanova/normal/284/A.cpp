/*
Let's go!

With blood shot eyes I watch you sleeping
The warmth I feel beside me is slowly fading
Would she hear me if I called her name?
Would she hold me if she knew my shame?

There's always something different going wrong
The path I walk's in the wrong direction
There's always someone fucking hanging on
Can anybody help me make things better?

Your tears don't fall, they crash around me
Her conscience calls, the guilty to come home
Your tears don't fall, they crash around me
Her conscience calls, the guilty to come home

The moments die, I hear no screaming
The visions left inside me are slowly fading
Would she hear me if I called her name?
Would she hold me if she knew my shame?

There's always something different going wrong
The path I walk's in the wrong direction
There's always someone fucking hanging on
Can anybody help me make things better?

Your tears don't fall, they crash around me
Her conscience calls, the guilty to come home
Your tears don't fall, they crash around me
Her conscience calls, the guilty to come home

Oh yeah

This battered room I've seen before
The broken bones they heal no more, no more
With my last breath I'm choking
Will this ever end? I'm hoping
My world is over one more time

Let's go!

Would she hear me if I called her name?
Would she hold me if she knew my shame?

There's always something different going wrong
The path I walk's in the wrong direction
There's always someone fucking hanging on
Can anybody help me make things better?

Your tears don't fall, they crash around me
Her conscience calls, the guilty to come home
Your tears don't fall, they crash around me
Her conscience calls, the guilty to come

Better!

Your tears don't fall, they crash around me
Her conscience calls, the guilty to come home
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
 
#define  INF 100000000
#define eps 1e-5
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
 
using namespace std;
long n,ans;

long gcd(long a,long b)
{
     while (a&&b)a>b?a%=b:b%=a;
     return a+b;
}

int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<n;i++)
if (gcd(i,n-1)==1)++ans;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}