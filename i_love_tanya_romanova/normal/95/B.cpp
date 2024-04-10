/*
I saw the morning it was shattered by a gun
Heard a scream, saw him fall, no one cried
I saw a mother, she was praying for her son
Bring him back, let him live, don't let him die

Do you ever ask yourself
Is there a Heaven in the sky?
Why can't we get it right?

'Cause we all live under the same sun
We all walk under the same moon
Then why, why can't we live as one?

I saw the evening fading shadows one by one
Watch the lamb, lay down to the sacrifice
I saw the children, the children of the sun
How they wept, how they bled, how they died

Do you ever ask yourself
Is there a Heaven in the sky?
Why can't we stop the fight?

'Cause we all live under the same sun
We all walk under the same moon, yea
Then why, why can't we live as one?

Sometimes I think I'm going mad
We're loosing all we had and no one seems to care, yea
But in my heart it doesn't change
We've got to rearrange and bring our world some love

And does it really matter
If there's a Heaven up above?
We sure could use some love

'Cause we all live under the same sky
We all look up at the same stars, yea
Then why, why can't we live as one?
'Cause we all live under the same sun
We all walk under the same moon, yea
We all live under the same sky
We all look up at the same stars, yea
Then why, tell me why can't we live as one?
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

using namespace std;

string st;
long n,s[200000][3],ap,av;

bool nice(string st)
{
 long s1,s2;
 s1=s2=0;
 for (int i=0;i<st.size();i++)
  if (st[i]=='4')++s1;else if (st[i]=='7')++s2;
 if (s1==s2&&s1+s2==st.size())return true;
 return false;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
if (nice(st))cout<<st<<endl; // it is
else if (st.size()%2)// odd size
{
 n=st.size()+1;
 n/=2;
 for (int i=0;i<n;i++)
  cout<<4;
 for (int i=0;i<n;i++)
  cout<<7;
  cout<<endl;
}
else
{
 ap=av=-1;
 for (int i=1;i<=st.size();i++)
 {
  s[i][0]=s[i-1][0];
  s[i][1]=s[i-1][1];
  if (st[i-1]=='4')s[i][0]++;
  if (st[i-1]=='7')s[i][1]++;
 }
 for (int i=st.size()-1;i>=0;--i)
 {
  if (s[i][0]+s[i][1]!=i)continue; // bad pref
  if (st[i]<'4'&&abs(s[i][0]+1-s[i][1])<st.size()-i)
   {ap=i;av=4;break;}
  if (st[i]<'7'&&abs(s[i][0]-s[i][1]-1)<st.size()-i)
   {ap=i;av=7;break;}
 }
 if (ap==-1){n=st.size()/2;for (int i=0;i<=n;i++)cout<<4;for (int i=0;i<=n;i++)cout<<7;cout<<endl;}
 else
 {
  long need4=st.size()/2;
  for (int i=0;i<ap;i++)
  {
   cout<<st[i];if (st[i]=='4')--need4;
  }
  cout<<av;
  if (av==4)--need4;
  for (int i=ap+1;i<st.size();i++)
  {
   if (need4){cout<<4;--need4;}
   else cout<<7;
  }
  cout<<endl;
 }
}

cin.get();cin.get();
return 0;}