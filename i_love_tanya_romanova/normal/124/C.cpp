/*
Within struggle, amidst horror
Inside conflict, visceral war
Make a stand here, vanquish all fear
Don't hesitate, eradicate

Torn between Scylla and Charybdis
Feel the fear ripening, go taste it
Torn between Scylla and Charybdis
Feast fruits of valor, if you face it

Walls of carnage surround your weakness
Crash down like oceans, wait for the light
In total darkness, drowning in bleakness
Awaiting death's grip, cry out for life

Divided by destiny
Torn between death and doom
Destruction by decision
Fate shows me my open tomb

Apprehension runs down your chin
Masticate it, suck those tears in
Life's a battle, perpetual crusade
One against all, time to wield the blade

Torn between Scylla and Charybdis
Feel the fear ripening, go taste it
Torn between Scylla and Charybdis
Feast fruits of valor, if you face it

In total darkness, drowning in bleakness
Awaiting death's grip, cry out for life

Divided by destiny
Torn between death and doom
Destruction by decision
Fate shows me my open tomb
A fight that tests the substance
Of all that you call your life
Destruction by decision
Fate shows me my open tomb

Face down that which makes you bleed
Turn it 'round and force your seed
Down

Face down that which makes you bleed
Turn it 'round and force your seed
Down

Torn between Scylla and Charybdis
Feast fruits of valor, if you face it

Walls of carnage surround your weakness
Crash down like oceans, wait for the light
In total darkness, drowning in bleakness
Awaiting death's grip, cry out for life

Divided by destiny
Torn between death and doom
Destruction by decision
Fate shows me my open tomb
A fight that tests the substance
Of all that you call your life
Destruction by decision
Fate shows me my open tomb
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
#define eps 1e-9
//#define M_PI 3.141592653589793
#define mx 1000000000000ll
#define bs 1000000007
using namespace std;
string st;
long n,nmb,pss,ansp,nmb1,pr[200000],cl[200000];
char answ[10000];
string st1;

char getmax(string st)
{
 long ara[300];
 for (int i=0;i<260;i++)ara[i]=0;
 
 for (int i=0;i<st.size();i++)
 ara[st[i]]++;
 ansp=0;
 for (int i=0;i<257;i++)
 if (ara[i]>ara[ansp])ansp=i;
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

cin>>st;
n=st.size();
//cin>>n;

pr[1]=1;

for (int i=2;i<=1000;i++)
if (pr[i]==0)
for (int j=i*2;j<=1000;j+=i)
pr[j]=1;

cl[1]=1;

for (int i=2;i<=1000;i++)
cl[i]=10000;

for (int i=2;i<=1000;i++)
if (pr[i]==0)cl[i]=i;

for (int i=2;i<=n;i++)
for (int j=i+1;j<=n;j++)
{for (int q=i;q<=n;q+=i)
if  (q%i==0&&q%j==0)cl[j]=min(cl[j],cl[i]);}

getmax(st);

long nmb=0;

for (int i=0;i<st.size();i++)
{if (st[i]==ansp)nmb++;
}
nmb1=nmb;

for (int i=2;i<=n;i++)
{if (pr[i]==0&&i*2>n){;}
else {answ[i]=ansp;--nmb;}
}
//cout<<nmb<<endl;
//cout<<nmb1<<endl;
nmb1-=nmb;
if (nmb<0)
{cout<<"NO"<<endl;
          }
else 
{
     sort(st.begin(),st.end());
     
     for (int i=0;i<st.size();i++)
     {
         if (st[i]==ansp&&nmb1>0){nmb1--;}
         else {st1.push_back(st[i]);}
     }

 //cout<<st1<<endl;
 
for (int i=1;i<=n;i++)
if ((i*2>n&&pr[i]==0)||(i==1))
{answ[i]=st1[pss];++pss;}
cout<<"YES"<<endl;
for (int i=1;i<=n;i++)cout<<answ[i];
cout<<endl;
}
cin.get();cin.get();
return 0;}