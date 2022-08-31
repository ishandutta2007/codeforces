/*
I continue to succumb to mundane hospitality
Fabricating pertinent dinner conversation
Fascinating breath pressing drawls
Asking myself why

Unbelievable, isn't it? The way we twist the words around
Just to get that quick fix, I swore someday I'd save myself

Unbelievable, isn't it?
Unbelievable, isn't it?

And I'll tease you, tickle your goddamn nod job
Focus on the lines forming faster
Aching in the waste of primitive lust
Asking myself why

Unbelievable, isn't it? The way we twist the words around
Just to get that quick fix, I swore someday I'd save myself

Unbelievable, isn't it?
Unbelievable, isn't it?

From cum dreamt lines forcing faster and faster

Unbelievable, isn't it? The way we twist the words around
Just to get that quick fix, I swore someday I'd save myself

Unbelievable, isn't it?
Unbelievable, isn't it?

At last, can I please rest?
Unbelievable, isn't it?
Vacate every day after day
Unbelievable, isn't it?
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long a,b,s,pw;
string st;
long good[1<<20],ans;

int main(){
//freopen("average.in","r",stdin);
//freopen("average.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
cin>>a>>b;
for (int i=0;i<st.size();i++)
{
 s=s*10+st[i]-48;
 if (s%a==0)good[i+1]=1;
 s%=a;
}

s=0;
pw=1;
for (int i=st.size()-1;i+1;--i)
{
 s=s+pw*(st[i]-48);
 s%=b;
 if (s==0&&st[i]>'0')good[i]++;
 pw*=10;
 pw%=b;
}
ans=-1;
for (int i=0;i<st.size();i++)
if (good[i]==2)
 ans=i;
if (ans==-1)
cout<<"NO"<<endl;
else 
{
     cout<<"YES"<<endl;
     for (int i=0;i<ans;i++)
      cout<<st[i];
     cout<<endl;
     for (int i=ans;i<st.size();i++)
      cout<<st[i];
     cout<<endl;
 }
cin.get();cin.get();
return 0;}