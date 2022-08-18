/*
You don't know where it is you're going
But you know you're on your way
Life only gives what you apply
Spend every day just searching
For something to pass the time
So many ways to waste a life

Debasing
Replacing
Embracing
Time wasting
Quit thinking
Mind shrinking

Wasting your life

Wasting away in a pseudo-existence
Let reality pass you by
Apathy and consciousness collide
You can join the real world
Don't let it be denied
Cut the cord: activate your mind

You don't know where it is you're going
But you know you're on your way
Life only gives what you apply
Don't let it be a last-minute decision
To stop throwing away your time
Before you know it, it's over and you die

Stop wasting your life
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
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256
 
using namespace std;

long n,m,k;
long ans;

int main(){
//freopen("sufflcp.in","r",stdin);
//freopen("sufflcp.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
if (n%2==0)cout<<"Marsel"<<endl;
else
{
swap(n,m);
 if (k==1&&n>1)ans=1;
 for (int i=2;i*i<=n;i++)
  if (n%i==0)
   if (i>=k||n/i>=k)ans=1;
  if (ans==0)cout<<"Marsel"<<endl;
  else cout<<"Timur"<<endl;    
}

cin.get();cin.get();
return 0;}