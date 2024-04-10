/*
And thus you speak to me
With your divided tongue all tangled up
In lies
In lies
You try to explain to me
That your silent cry and that weakest whisper
Is real
Surreal

Interlocked reality
Fail to find the answer to my questions
And to see this innerline
I'll drown myself to be alive

Fall
My innerline
Beneath normality
Reveal the right way and I'll dream
To be alive
Embrace what's left behind
Forgive my sense of lost reality

So now I crawl to you
With my divided soul distorted and
In pain
Deranged
I scream to come back to you
To see what's real I'll sell myself
To you
To you

Nothingless reality
Still my desperate hunger
End the questions
But to be this innerline
I drown myself to free my mind

I choose to fight this dream
And drift into my lost reality
Forgive my sense of dream
I'll meet you in my lost reality

Be on this night my fallen angel
Touch my face and set me free

Be my fallen angel
Reveal the dream to all
Construct my sense of freedom
And I will hear you call

All is falling into lost reality
I sought to be my wildest dream

I choose to fight this dream
And drift into my lost reality
Forgive my sense of dream
I'll meet you in my lost reality
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

long n,m,q,ar1[400000],ar2[400000],
s1[400000],s2[400000],calc1,calc2,ps,cur;
long nice[500000];
vector<long> v;
long tp,ans,dp1[500000],dp2[500000];

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>q;
 ar1[q]=1;
}
for (int i=1;i<=m;i++)
{
 cin>>q;
 ar2[q]=1;
}
for (int i=1;i<=300000;i++)
 s1[i]=s1[i-1]+ar1[i],s2[i]=s2[i-1]+ar2[i];

for (int i=1;i<=300000;i++)
 if (ar2[i])
 {
  q=i;
  if (ar1[q]==0)
  {
   while (q<300000&&ar1[q]==0)++q;
   if (q<300000)nice[q]=1;
   q=i;
   while (q>0&&ar1[q]==0)--q;
   if (q>0){while (ar1[q])--q;nice[q+1]=1;}
  }
  else
  {
   while (ar1[q])--q;nice[q+1]=1;
  }
 }

for (int i=0;i<=300000;i++)
 if (nice[i])v.push_back(i);

cur=0;
for (int i=1;i<=300000;i++)
{
 while (cur<v.size()&&v[cur]<i)++cur;
 
 if (i==1||(ar1[i]==0&&ar1[i-1]!=0))
 {
  // mv i+1..j -> j
  for (int j=cur;j<v.size();j++)
  {
   tp=v[j];
   calc1=s1[tp-1]-s1[i-1];
   calc2=s2[tp-1]-s2[tp-calc1-1];
   dp2[tp]=max(dp2[tp],dp1[i]+calc2);
  }
 }
 
 if (nice[i]==0)continue;
 
 calc1=i;
 calc2=0;
 // mv i+1..j->i+1
 for (int j=i;j<300000;j++)
 {
  if (ar1[j])
  {
   if (ar2[calc1])++calc2;
   ++calc1;
   dp1[j+1]=max(dp1[j+1],dp2[i]+calc2);
  }
 }
}

for (int i=1;i<=300000;i++)
 ans=max(ans,dp1[i]);

cout<<ans<<endl;

cin.get();cin.get();
return 0;}