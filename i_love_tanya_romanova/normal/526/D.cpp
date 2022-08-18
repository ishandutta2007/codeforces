/*
Time has come
The dawn shall see us off again
Glory rides
The stars shall be our watching guide

We know God is ready and He's willing to fill our veins
It takes my mind away
Hot sun, splitting thunder, deafening violent storms
We sail atop the highest wave in search of our Viking Gold
And turn our backs into the night, we sail into the night

As the mighty desert wind blows through the mountains
Still she sails, our trusty ship across the sea
And we raise our glasses high to this good life
See our torches brandish light upon the free

Cowards running to the hills, no courage in their eyes
Shadowed terrors prey on them, no mercy in their eyes
Their battle's over long before they have a chance to pray
But we shall stand steadfast our ground
Unmoved through the day

Let us drink to the spirit
That has given us the power
To rule with the mightiest of swords
Through all of the land

Our ship now listless drifting aimlessly through the tide
This calm before the storm screams over high
This must be madness 'cause the sky is growing blacker
Than the shadow of a dead star in regression of its power

If the darkness that surrounds you
Leaves you nowhere you can run to
I implore you fall down to your knees
And pray these tentacles released their grip

Well, you and I do not belong here
Will we return, I cannot believe
Strong winds twisting and tearing our sails off
I'm hiding my eyes, you are fading away

Misfortune paints their lonely story
A thousand years shall endure
Unfold the tale of that dark day
Their mystics ship so far from sure

They sailed away into another sea
A mystery to us all
Beware the waves you sail upon in ships so strong
It is our belief, this story's true
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
#define bsize 256

using namespace std;

long long pw1[1<<21],pw2[1<<21];
long n,k;
string st;
long long s1[1<<21],s2[1<<21];
long er;
long opn[1<<21];
long s;

bool sam(long l1,long r1,long l2,long r2)
{
 long long val1,val2;
 val1=s1[r1]-s1[l1-1];
 if(val1<0)val1+=bs;
 val2=s1[r2]-s1[l2-1];
 if (val2<0)val2+=bs;
 val1*=pw1[l2-l1];
 val1%=bs;
 if (val1!=val2) return false;
 val1=s2[r1]-s2[l1-1];
 if(val1<0)val1+=bs;
 val2=s2[r2]-s2[l2-1];
 if (val2<0)val2+=bs;
 val1*=pw2[l2-l1];
 val1%=bs;
 return (val1==val2);
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

pw1[0]=1;
pw2[0]=1;

for (int i=1;i<=2000000;i++)
 pw1[i]=pw1[i-1]*173%bs;
for (int i=1;i<=2000000;i++)
 pw2[i]=pw2[i-1]*137%bs;
 
cin>>n>>k;
cin>>st;
for (int i=1;i<=st.size();i++)
{
 s1[i]=s1[i-1]+st[i-1]*pw1[i];
 s1[i]%=bs;
 s2[i]=s2[i-1]+st[i-1]*pw2[i];
 s2[i]%=bs;
}

for (long pref=1;pref*k<=n;pref++)
{
 er=0;
 for (int j=1;j<=k;j++)   
 {
  if (sam(1,pref,pref*(j-1)+1,pref*j)==0){er=1;break;}
 }
 if (er==0)
 {
  opn[pref*k]++;
  int same=0;
  int l,r;
  l=0;
  r=pref;
  if (pref*k+r>n)
   r=n-pref*k;
  
  while (l<r)
  {
   long one=1;
   long mid=l+r+1;
   mid/=2;
   if (sam(one,mid,pref*k+1,pref*k+mid)==1)
    l=mid;
    else r=mid-1;
  } 
  same=l;
  opn[pref*k+same+1]--;
 }
}

string ans;

for (int i=1;i<=n;i++)
{
    s+=opn[i];
    if (s>0)
     ans+="1";
     else ans+="0";
}
puts(ans.c_str());

cin.get();cin.get();
return 0;}