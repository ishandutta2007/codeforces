/*
Feel the sweat break on my brow
Is it me or is it shadows that are dancing on the walls?
Is this a dream or is it now?
Is this a vision or normality I see before my eyes?

I wonder why, I wonder how
That it seems that the powers getting stronger every day
I feel a strength an inner fire
But I'm scared I wont be able to control it anymore

There's a time to live and a time to die
When it's time to meet the maker
There's a time to live but isn't it strange
That as soon as you're born you're dying

There's a time to live and a time to die
When it's time to meet the maker
There's a time to live but isn't it strange
That as soon as you're born you're dying

Just by looking through your eyes
He could see the future penetrating right in through your mind
See the truth and see your lies
But for all his power couldn't foresee his own demise

There's a time to live and a time to die
When it's time to meet the maker
There's a time to live but isn't it strange
That as soon as you're born you're dying

There's a time to live and a time to die
When it's time to meet the maker
There's a time to live but isn't it strange
That as soon as you're born you're dying

I've been reborn again
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
#define bs 1000000009
#define bsize 256

using namespace std;

string st;
long l,n;
char ans[200000];

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n;

for (int i=1;i<=n;i++)
{
 cin>>st;
 l=st.size();
 for (int j=0;j<st.size();j++)
 {
  if (st[j]=='?')continue;
  if (ans[j]==0)ans[j]=st[j];
  if (ans[j]=='?')continue;
  if (ans[j]!=st[j])ans[j]='?';
 }
}
for (int i=0;i<l;i++)
if (ans[i]==0)cout<<'a';
else cout<<ans[i];
cout<<endl;

cin.get();cin.get();
return 0;}