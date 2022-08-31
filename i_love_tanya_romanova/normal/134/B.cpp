/*
All the photographs were peeling
and colors turned to gray
He stayed... in his room with memories for days
He faced... an undertow of futures laid to waste
Embraced... by the loss of what he could not replace

There is no reason that she passed
And there is no god with a plan
It's sad... and his loneliness is proof
It's sad... he could only love you
It's sad

The door swings to a passing fable
A fate we may delay
We say... holding on...delivered in our own brace
He let em as he laid in bed
hoping that dreams would bring her back
It's sad... and his loneliness is proof
It's sad... he could only love you
It's sad

Holding his last breath
Believing... he'll make his way
But she's not forgotten
He's haunted...he's searching for escape

If just one wish could bring her back
It's sad... and his lonliness is proof
It's sad... he will always love you
It's sad
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

long n,ans;

long solve(long a,long b)
{
     if (b==1)return a-1;
     if (b==0)return 100000000;
     return a/b+solve(b,a%b);
}

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
ans=1000000;

for (int last=1;last<n;last++)
{
 long a,b;
 long r=0;
 a=n;
 b=last;
 ans=min(ans,solve(a,b));
}
if (n==1)ans=0;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}