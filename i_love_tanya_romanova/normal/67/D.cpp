/*
We pretend to care in the stuffy air we breath all day
We find ourself oppressing life that'll never know
Save their aim from the ashes

Too scared to lose our worthful power of blind control
Where's the right to rise with own force to built their system

Save their aim from the ashes

Delightful cultures that'll never grow with our apparent sens of relief
Our sweat ain't more than false deception and
Our helping hands are full of blood and dirt

Save their aim from the ashes

We set the frame in the genuine rain of a lost generation
Our sweat ain't more than false deception and
Our helping hands are full of blood and dirt

Save their aim from the ashes

All our norms have been stamped in innocent flesh
All our past has been burying their unborn hope
All our ignorance has unleashed all their misery

Save their aim... from the ashes
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
#define bsize 512
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long q,mapp[1<<20],n,l,r,mid,dp[1<<20],ans;

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>q;
 mapp[q]=n-i+1;   
} 

dp[0]=-1e9;

for (int i=1;i<=1000000;i++)
 dp[i]=1e9;

for (int i=1;i<=n;i++)
{
 cin>>q;
 q=mapp[q];
 l=0;
 r=1000000;
 while (l<r)
 {
  mid=l+r+1;
  mid/=2;
  if (dp[mid]<q)l=mid;
  else r=mid-1;
 }
 if (dp[l]<q&&q<dp[l+1])
  dp[l+1]=q;
}

for (int i=0;i<=1000000;i++)
 if (dp[i]<1e7)ans=i;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}