/*
To the fucker who let me have a life in the dark,
Till the day my life ran out
Well a day in the dark, a bloody lust of wind, wanna know what it's about?

It's not like your gonna need me or I'm gonna miss you
when the worlds so cold out there
So dumb, what the fuck am I doing here?
All I need to know

I'm sorry and ill let you go by the reign you built for me
Still a god but, don't wanna even know what's waiting for me

I'll be waiting here for always
Wanna go? Yeah, hang that rope
Every thought breaks down in my head
Best to run, blinded soul
Bring me back on my feet and let me go I'm fine alone
In this shell of life you left me hanging dry
With a smile on my face I'll watch you cry

Forms of my dream
Down you'll be grime

I'll be waiting here for always
Wanna go? Yeah, hang that rope
Every thought breaks down in my head
Best to run, blinded soul
Bring me back on my feet and let me go I'm fine alone
In this shell of life you left me hanging dry
With a smile on my face I'll watch you cry

Watch you cry
Watch you cry
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

long n,ans;
vector<long> vec;

void generate1(long x,long p)
{
 vec.push_back(x);
 if (x>100000000)return;
 generate1(x*10+p,p);
}

void generat(long v,long a,long b)
{
 long ar[12];
 for (int i=0;i<=10;i++)
  ar[i]=0;
 long pp=v;
 while (pp){ar[pp%10]++;pp/=10;}
 if (ar[a]&&ar[b]) vec.push_back(v);
if (v>100000000)return;
if (v*10+a>0)
generat(v*10+a,a,b);
if (v*10+b>0)
generat(v*10+b,a,b);
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=1;i<=9;i++)
 generate1(i,i);

for (int i=0;i<=9;i++)
 for (int j=i+1;j<=9;j++)
 {
  generat(0,i,j);
 }

cin>>n;
for (int i=0;i<vec.size();i++)
 if (vec[i]<=n)++ans;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}