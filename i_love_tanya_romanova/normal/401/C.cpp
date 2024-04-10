/*
You know I've heard it all before, I'll hear it all again
I know just where I'm going and I know just where I've been
I've seen so many come and go but somehow I survive
I know I will die someday, but I'm glad to be alive
Glad to be alive
The strong survive

I've got a life to lead, I care if I succeed
I got to find my way
I've got a life to lead, I take just what I need
That's where I will stay
That's where I'll stay

I can't tell the future, I can't give a prophecy
Doing what it take to make my destiny
I can't help but wonder, but much to my surprise
Doing what I want with no trace of compromise
No compromise!
I tell no lies!

I've got a life to lead, you know my soul is freed
I'm finding my way
I've got a life to lead, you know my soul is free
'Til the end of the day

I don't know who said it first, losers never last
Having no direction can make it end so fast
See so many come and go but somehow I survive
I know I will die someday, but I'm glad to be alive
Glad to be alive
The strong survive

I've got a life to lead, I am the hardened breed
I know the way
I've got a life to lead, I am the hardened breed
You know I'm here to stay
Here to stay!
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
 
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
 
//#define free asdfasdfsdadsg
#define bsize 512
 
using namespace std;

long n,m,a,b,t;

int main(){
//freopen("rmq.in","r",stdin);
//freopen("rmq.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
a=n-1;
b=(n+1)*2;

if (m<a||m>b){cout<<-1<<endl;return 0;}

 if (m==n-1)
 {
  cout<<0;
  for (int i=1;i<=m;i++)
  cout<<10;
  cout<<endl;
  return 0;
 } 

if (m==n)
{
 for (int i=1;i<=m;i++)
 cout<<10;
 cout<<endl;
 return 0;
}

t=m-(n+1);
for (int i=0;i<n;i++)
{
 if (i<t)cout<<11;
 else cout<<1;
 cout<<0;
}
if (m==b)cout<<11;
else cout<<1;
cout<<endl;

cin.get();cin.get();
return 0;}