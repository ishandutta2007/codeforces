/*
You have a vision brighter than a thousand suns
Preparing the final assault, your final assault
You have to live beneath...
The final hours are coming beneath a silent warfare!

You have a vision brighter than a thousand suns
Preparing the final assault, your final assault
It's the time for your last life's temptation!
It's the time for your blackened strategy!
I read into your hatred eyes

I know your problem
But the pleasure of watching you
Is what will get! We're slaves of a silent warfare!

One by one into the depths we fall
One by one we dive in hell
If you dare to break the silence

If you speak your name aloud

You'll be swallowed by your flames of revenge
And I'll be here again to see you

Preparing the final assault, your final assault
It's the time for your last life's temptation
It's the time for your blackened strategy

Listen to the silence...
Ride the storm that rush your soul!
Show the red into my eyes

I know your problem
But the pleasure of watching you
Is what will get! We're slaves of a silent warfare!
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
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long long a,b,res;
long long solve(long long x)
{
 long long q=0;
 while (q<x)q=q*10+9;
 return x*(q-x);
}

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>a>>b;
res=solve(a);
res=max(res,solve(b));
for (int i=5;i<=500000000;i*=10) 
 if (i>=a&&i<=b)
  res=max(res,solve(i));

cout<<res<<endl;

cin.get();cin.get();
return 0;}