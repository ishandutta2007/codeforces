/*
Ever felt away with me just once that all I need
Entwined in finding you one day
Ever felt away without me my love it lies so deep
Ever dream of me

Would you do it with me
Heal the scars and change the stars
Would you do it for me
Turn loose the heaven within

I'd take you away
Castaway on a lonely day
Bosom for a teary cheek
My song can but borrow your grace

Ever felt away with me just once that all I need
Entwined in finding you one day
Ever felt away without me my love it lies so deep
Ever dream of me

Come out, come out wherever you are
So lost in your sea
Give in, give in for my touch
For my taste for my lust

Ever felt away with me just once that all I need
Entwined in finding you one day
Ever felt away without me my love it lies so deep
Ever dream of me

Your beauty cascaded on me in this white night fantasy

Ever felt away with me just once that all I need
Entwined in finding you one day
Ever felt away without me my love it lies so deep
Ever dream of me

Ever felt away with me just once that all I need
Entwined in finding you one day
Ever felt away without me my love, it lies so deep
Ever dream of me

Ever felt away with me just once that all I need
Entwined in finding you one day
Ever felt away without me my love, it lies so deep
Ever dream of me
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

#define EPS 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

string st;
long n,ar[2050][2050],s1[2050],s2[2050],s3[2050],s4[2050];
long cur,ans;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>st;
 for (int j=1;j<=st.size();j++)
  ar[i][j]=st[j-1]-48;
}

for (int i=1;i<=n;i++) // ur
 for (int j=n;j>i;j--)
 {
  cur=s1[i]+s2[j];
  cur%=2;
  if (cur!=ar[i][j]){++ans;++s1[i];++s2[j];}
 }

for (int i=n;i;i--)
 for (int j=1;j<i;j++)
 {
  cur=s3[i]+s4[j];
  cur%=2;
  if (cur!=ar[i][j]){++ans;++s3[i];++s4[j];}
 }

for (int i=1;i<=n;i++)
{
 cur=s1[i]+s2[i]+s3[i]+s4[i];
 cur%=2;
 if (cur!=ar[i][i])++ans;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}