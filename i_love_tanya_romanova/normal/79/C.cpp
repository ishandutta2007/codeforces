/*
The world around me is lost in misery
The only good I've got in my life is you
No meaning, no other reason
When everything feels wrong I feel right with You

So madly, desperate deeply
Obsessed your love is better than mine to me
Can I have this moment forever?

Take me, to the beginning

You are what I believe
I'll live and die for You
This is all that I need
When nothing is real you are my truth

In the darkness You shine
Can You keep me safe tonight?

When I'm down on my knees
You are what I believe

When we started whole hearted
I never needed anything or anyone else
I was broken you made me whole again
The only one I trusted more than myself

So madly desperate deeply
I will live for you completely
Can I have this moment forever?

Take me, to the beginning

You are what I believe
I'll live and die for you
This is all that I need
When nothing is real you are my truth

In the darkness you shine
Can you keep me safe tonight?

When I'm down on my knees
You are what I believe

Believe in your love
Believe in your life
Believe that You can put me back
Together on the inside

Chase all the fear away
Every time I speak your name

Take me
You are what I believe

You are what I believe
I'll live and die for You
This is all that I need
When nothing is real you are my truth

In the darkness You shine
Can You keep me safe tonight?

When I'm down on my knees
You are what I believes
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

string st;
long n,p;
long proh[1<<18];
string temp;

long mn(long a,long b)
{return max(a,b);}

bool check(long ps)
{
 for (int i=ps-temp.size();i<ps;i++)
  if (st[i]!=temp[i-ps+temp.size()])return false;
 return true;
}

long lc,ans,ap;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
cin>>p;
n=st.size();
for (int i=1;i<=n;i++)
 proh[i]=-1e9;
 
for (int i=1;i<=p;i++)
{
 cin>>temp;
 for (long j=temp.size();j<=st.size();j++)
  if (check(j))proh[j]=mn(proh[j],j-temp.size());
}
/*
for (int i=1;i<=n;i++)
 cout<<proh[i]<<" ";
cout<<endl;
*/
lc=0;
for (int i=1;i<=n;i++)
{
    lc=max(lc,proh[i]+1);
    if (i-lc>ans)
    {
     ans=i-lc;
     ap=lc;
    }
}
cout<<ans<<" "<<ap<<endl;

cin.get();cin.get();
return 0;}