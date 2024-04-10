/*
I've been on tender-hooks ending in dirty looks
Listening to the muzak, thinking 'bout this 'n' that
She says that's that, I don't wanna chitter chat
Turn it down a little bit or turn it down flat

Pump it up when you don't really need it
Pump it up until you can feel it

Down in the pleasure center, hell bent or heaven sent
Listen to the propaganda, listen to the latest slander
There's nothing under hand that she wouldn't understand

Pump it up until you can feel it
Pump it up when you don't really need it

She's been a bad girl, she's like a chemical
Though you try to stop it, she's like a narcotic
You wanna torture her, you wanna talk to her
All the things you bought for her could not get her temperature

Pump it up until you can feel it
Pump it up when you don't really need it

Out in the fashion show, down in the bargain bin
You put your passion out under the pressure pin
Fall into submission, hit and run transmission
No use wishing now for any other sin

Pump it up until you can feel it
Pump it up when you don't really need it
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

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long long n,w[500000],a,b,c;
long long sz[500000];
long long ans,temp;

long long gett(long long x)
{
 if (x==w[x])return x;
 return w[x]=gett(w[x]);
}

void merg(long long a,long long b)
{
 a=gett(a);
 b=gett(b);
 if (rand()%2)swap(a,b);
  w[a]=b;
  sz[b]+=sz[a];
}

bool luck(long long x)
{
 while (x)
 {
  if (x%10!=4&&x%10!=7)return false;
  x/=10;
 }
 return true;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
w[i]=i,sz[i]=1;

for (int i=1;i<n;i++)
{
 cin>>a>>b>>c;
 if (luck(c)==0)merg(a,b);
}

ans=n*(n-1)*(n-2);

for (int i=1;i<=n;i++)
{
 if (w[i]!=i)continue;
 temp=sz[i];
 ans-=temp*(temp-1)*(temp-2);
 ans-=temp*(n-temp)*(temp-1)*2;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}