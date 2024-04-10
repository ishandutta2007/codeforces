/*
Throw me a penny and I'll make you a dream
You find that life's not always what it seems, no no
Then think of a rainbow and I'll make it come real
Roll me, I'm a never ending wheel
I'll give you a star
So you know just where you are
Don't you know that I might be
Your wishing well
Your wishing well
Look in the water, tell me what do you see
Reflections of the love you give to me
Love isn't money, it's not something you buy
So let me fill myself with tears you cry, why?
Time is a never ending journey
Love is a never ending smile
Give me a sign to build a dream on
Dream on...
Yeah, Throw me a penny and I'll make you a dream
You find that life's not always what it seems, no no
Love isn't money, it's not something you buy
So let me fill myself with tears you cry
I'll give you a star
So you know just where you are
Someday, some way, you'll feel the things I say
Dream for a while
Of the things that make you smile
'Cause you know
Don't you know
Oh, you know
That I'm your wishing well
Your wishing well
Your wishing well
I wish you well
I'm your wishing well
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

vector<pair<long, long> > k;
string st[100];
long tests,s,fl;
long bad[20][20];

int main(){
//freopen("gift.in","r",stdin);
//freopen("gift.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>tests;
for (;tests;--tests)
{
 k.clear();
  for (int i=1;i<=8;i++)
  {
   cin>>st[i]; 
   for (int j=1;j<=8;j++)
   {if (st[i][j-1]=='#')bad[i][j]=1;
   else bad[i][j]=0;
   if (st[i][j-1]=='K')k.push_back(make_pair(i,j));
   }
   
  }
 fl=0;
 for (int i=1;i<=8;i++)
 {
  for (int j=1;j<=8;j++)
  {
   //if (bad[i][j]==0)
   {
    s=0;
    for (int q=0;q<k.size();q++)
    if (abs(i-k[q].first)==2&&abs(j-k[q].second)==2)
    s++;
    if (s==2)++fl;
   }
  }
 }
 if (fl)cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
}

cin.get();cin.get();
return 0;}