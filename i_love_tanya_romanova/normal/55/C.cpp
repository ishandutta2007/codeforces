/*
Another day
Another failed chance
Another question is filling my mind
Without an answer
How many times
we cried to change the ways
of our hard fate...
But It's all in our hands!
I want a reason to live for
I want a reason to die
I want a reason to fight everyday!
I'm trying
day by day
To learn from this sorrow
Shades of past
turning back
But I won't stop being a dream chaser

I think I'll never
Dispel this uncertainty
But I've still so much power inside...
Can't you see it?
So give me a reason to live for
Give me a reason to die
Give me a reason to fight everyday!
I'm trying
day by day
To learn from this sorrow
Shades of past
('re) turning back
But I won't stop being a dreams' chaser
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

long n,m,k,ans,a,b;

long gd()
{
 long res=min(a,n-a+1);
 res=min(res,min(b,m-b+1));
 return res;
}

int main(){
//freopen("capital.in","r",stdin);
//freopen("capital.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
ans=0;
for (int i=1;i<=k;i++)
{
 cin>>a>>b;
 if (gd()<=5)ans=1;
}

if (ans)cout<<"YES"<<endl;
else cout<<"NO"<<endl;

cin.get();cin.get();
return 0;}