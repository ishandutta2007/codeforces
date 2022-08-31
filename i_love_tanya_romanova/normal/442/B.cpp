/*
And now I don't know why
She wouldn't say goodbye
But then it seems that I
Had seen it in her eyes

Though it might not be wise
I'd still have to try
With all the love I have inside
I can't deny

I just can't let it die
'Cause her heart's just like mine
And she holds her pain inside

So if you ask me why
She wouldn't say goodbye
And I know somewhere inside
There is a special light still shining bright
And even on the darkest night
She can't deny

So if she's somewhere near me
I hope to God she hears me
There's no one else
Could ever make me feel
I'm so alive

I hoped she'd never leave me
Please God, You must believe me
I've searched the universe
And found myself
Within her eyes

No matter how I try
They say it's all a lie
So what's the use of my
Confessions to a crime
Of passions that won't die
In my heart

So if she's somewhere near me
I hope to God she hears me
There's no one else
Could ever make me feel
I'm so alive

I hoped she'd never leave me
Please God, You must believe me
I've searched the universe
And found myself
Within her eyes

So if she's somewhere near me
I hope to God she hears me
There's no one else
Could ever make me feel
I'm so alive

I hoped she'd never leave me
Please God, You must believe me
I've searched the universe
And found myself
Within her eyes

And now I don't know why
She wouldn't say goodbye
It just might be that I
Had seen it in her eyes

And now it seems that I
Gave up my ghost of pride
I'll never say goodbye
*/

#pragma comment(linker, "/STACK:16777216")
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

long n;
double bst,temp,ar[200];
long bmask;
/*
double solve(long mask)
{
 vector<long> v;
 for (int i=0;i<n;i++)
  if (mask&(1<<i))v.push_back(i);
 double res=0;
 for (int i=0;i<v.size();i++)
 {
double  tp=1;
  for (int j=0;j<v.size();j++)
   if (j==i)tp*=ar[v[j]]; else tp*=(1.0-ar[v[j]]);
  res+=tp;
 }
 return res;
}
*/

double solve(vector<double> v)
{
 double r=0;
 for (int i=0;i<v.size();i++)
 {
  double t=1;
  for (int j=0;j<v.size();j++)
  if (i==j)t*=v[j];else t*=(1.0-v[j]);
   r+=t;
 }
 return r;
}

double cur;
vector<double> ans;

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
/*for (int i=0;i<n;i++)
ar[i]=rand()%100*.01;
*/
for (int i=0;i<n;i++)
cin>>ar[i];
/*
for (int i=0;i<n;i++)
cout<<ar[i]<<" ";
cout<<endl;

bst=-1;
for (int mask=0;mask<(1<<n);mask++)
{
 temp=solve(mask);
 if  (temp>bst){bst=temp;bmask=mask;}
}

cout<<bst<<endl;
for (int i=0;i<n;i++)
 if (bmask&(1<<i))cout<<i<<" ";

cout<<endl;
*/
sort(ar,ar+n);
reverse(ar,ar+n);
ans.push_back(ar[0]);
cur=solve(ans);

for (int i=1;i<n;i++)
{
 ans.push_back(ar[i]);
 if (solve(ans)>cur){cur=solve(ans);continue;}
 ans.pop_back();
}
cout.precision(12);

cout<<fixed<<cur<<endl;

cin.get();cin.get();
return 0;}