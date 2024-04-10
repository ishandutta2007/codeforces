/*
Breathe on these bones
Breathe on these bones
Breathe on these bones

Find there's no need to hide
The time has come to stand and fight
Save the world
And save that girl
From enemies unseen
Our hands will
Bleed for children unborn
The mornings come and rumours are
The hope that lasts
Within our grasp
If we muster up the strength to grab it

Stand
Face the world with open hands
And tears
And these tired body's spirit perseveres
Remembering these wounds will heal
You are not
Alone in this

We will look ahead
At the dreams
That were laid
In our heart
And we can begin again

Stand
Face the world with open hands
And tears
And these tired body's spirit perseveres
Remembering these wounds will heal
You are not
Alone in this

How long did You bleed for us
How long did You bleed for us

Hold fast
Don't you look at the past
Because hope and love last
Beyond the end

Stand
Face the world with open hands
And tears
And these tired body's spirit perseveres
Remembering these wounds will heal
You are not
Alone in this

Stand
Face the world with open hands
And tears
And these tired body's spirit perseveres
Remembering these wounds will heal
You are not
Alone in this
You are not
Alone in this
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
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long long n,k;
vector<long long> wave,twave;
long ttl[10][2][1000000];

void generate(long ps,bool up, long ldig,long val)
{
// if (val==1)
//  cout<<ps<<" "<<up<<" "<<ldig<<" "<<val<<endl;
 if (val>0) wave.push_back(val);
 if (ps==7)
 {
  ttl[val/1000000][up][(val%1000000)%n]++;
  return;
 }
 for (int ad=0;ad<10;ad++)
 {
  if (ad>ldig&&up==1)
   generate(ps+1,!up,ad,val*10+ad);
  if (ad<ldig&&up==0)
   generate(ps+1,!up,ad,val*10+ad);
 }
}

long long ans;
long long nice,ld;
long long need,req;
long long pref,temp;

void check(long long x)
{
 if (k<=0)return;
 --k;
 if (k==0)ans=x;
}

long get_dir(long x)
{
 if (x<10)return 3; // who nws
 int d1,d2;
 d2=x%10;
 d1=x%100/10;
 if (d1<d2)// goin up
  return 2;
 return 1; 
}

bool iswave(long long x)
{
 if (x<10)return 1;
 vector<long> v;
 while (x){v.push_back(x%10);x/=10;}
 if (v[0]==v[1])return 0;
 bool o=(v[0]<v[1]);
 for (int i=1;i+1<v.size();i++)
 {
  if (o==0&&v[i+1]<=v[i])return 0;
  if (o==1&&v[i+1]>=v[i])return 0;
  o=1-o;
 }
 return 1;
}

int main(){
//freopen("logins.in","r",stdin);
//freopen("logins.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);


/*while (cin>>n)
cout<<iswave(n)<<endl;
*/
cin>>n>>k;
generate(0,1,-100,0);
generate(0,0,100,0);
sort(wave.begin(),wave.end());
twave=wave;
wave.clear();
for (int i=0;i<twave.size();i++)
 if (i==0||twave[i]!=twave[i-1])
  wave.push_back(twave[i]);
  
/*for (int i=0;i<=100;i++)
 cout<<wave[i]<<endl;
*/
ans=-1;
for (int i=0;i<wave.size();i++)
{
 if (wave[i]%n==0&&k>0)
 {
  check(wave[i]);
 }
}

for (int i=0;i<wave.size();i++)
{
 if(ans!=-1)continue;
 nice=0;
 int dirm=get_dir(wave[i]);
 ld=wave[i]%10;
 need=1ll*wave[i]*10000000%n;
 need=n-need;
 if (need==n)need=0;
 if (need>10000000)continue;
 for (int dir=1;dir<=2;dir++)
  if (dirm&dir)
   for (int fdig=0;fdig<10;fdig++)
   {
    // match parts
    if (dir==1&&fdig<=ld)continue;
    if (dir==2&&fdig>=ld)continue;
    req=need-fdig*1000000%n;
    req%=n;
    while (req<0)req+=n;
    if (req<1000000)
     nice+=ttl[fdig][dir-1][req];
   }
 if (nice<k)
 {
  k-=nice;
  continue;
 }
 pref=wave[i]*10000000;
 for (int j=0;j<wave.size();j++)
 {
  temp=pref+wave[j];
  if (iswave(temp)==1&&temp%n==0)
   check(temp);
 }
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}