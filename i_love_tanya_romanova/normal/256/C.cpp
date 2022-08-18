/*
From the darkness I arise and order
You to hear me
Follow my command and find your destiny
Your agony is my uncare your sorrow my peace
Make me your master and purify your soul
I'll make you die a thousand times
So you suffer without a break
Let the fear take care of your being

Lord of your chaos
I'm the holocaust of your soul
Lifeless alive you crawl
Whipped until the stake
Victim of my hate
As I celebrate

I'm inside you
I'm the true meaning of your horror
Beg for your death, show me your misery
Your being will be devasted
Your sacrifice will endless
Sanctified you die and burn at
The depeoness
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

long sg[2000000],has[2000];
long l,r;
long s[1100000][55];
long n;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

sg[1]=0;
s[1][0]=1;
for (int i=2;i<=1000000;i++)
{
 l=pow(i+eps,0.25)+0.999999;
 r=pow(i+0.5,0.5);
// if (i<20)
// cout<<i<<" "<<l<<" "<<r<<endl;
 
 for (int j=0;j<=50;j++)
  s[i][j]=s[i-1][j];
  
//  cout<<l<<" "<<r<<"   "<<i<<endl;
 if (r<l)sg[i]=0;
 else while (s[r][sg[i]]!=s[l-1][sg[i]])++sg[i];
 //if (sg[i]>40)cout<<i<<" "<<sg[i]<<endl;
 s[i][sg[i]]++;
}

/*
for (int i=1;i<=10;i++)
 cout<<sg[i]<<"  "<<i<<endl;
*/

long ans=0;
cin>>n;
for (int i=1;i<=n;i++)
{
 long long t;
 cin>>t;
 l=pow(t+eps,0.25)+1-1e-8;
 r=pow(t+0.5,0.5);
// cout<<l<<" "<<r<<" "<<s[r][0]<<" "<<s[l-1][0]<<endl;
 if (r<l)continue;
 if (t==1)continue;
 long cur=0;
 while (s[r][cur]!=s[l-1][cur])++cur;
 ans^=cur;
// cout<<cur<<" "<<"^"<<ans<<endl;
}
if (ans)cout<<"Furlo"<<endl;
else cout<<"Rublo"<<endl;
 
cin.get();cin.get();
return 0;}