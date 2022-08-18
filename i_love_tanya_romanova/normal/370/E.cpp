/*
I could not breath against the wall
The clash of light against the floor
They held me up against the wall
Too young to be ignored

Standing by a building
Leaks out information
Passive death of freedom gets me
Where's my security
Behind my back it goes
Early morning's coming
The risk that I am taking
Recall a song that I heard as a child
No more false immunity
Inside the blistering cold

My youth unknown to me
I'm walking by a wire
What's left from me to breathe
Cold smell of fire
One day I will be free
I was born to be no one
My youth unknown to me
I walked behind the sun

Emptiness within me
Exit signs within me
The one you're looking for is not here
Had no security
He will not come back
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
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 2000

using namespace std;

long n;
vector<pair<long, long> > v;
long ar[300000];
long reach[300000][10];
long rspan,need1,need2;
long p,q;
long par[300000][10];
long ps,cur;
long tp,np,niters,m2,m1,qq;

int main(){
//freopen("ascii.in","r",stdin);
//freopen("ascii.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;

v.push_back(make_pair(0,0));
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
 if (ar[i]>0)v.push_back(make_pair(ar[i],i));   
}

reach[0][5]=1;

for (int i=1;i<v.size();i++)
if (v[i].first<v[i-1].first){cout<<-1<<endl;return 0;}

for (int i=0;i+1<v.size();i++)
 {
  rspan=v[i+1].second-v[i].second;
  for (int op=1;op<=5;op++)
    for (int np=1;np<=5;np++)
     {
      if (reach[i][op]==0)continue;
      if (v[i+1].first==v[i].first&&np<=op)continue;
      if (v[i+1].first==v[i].first)
       {
        need1=need2=np-op;
       }
       else
       {
        need1=(5-op)+(v[i+1].first-v[i].first-1)*5+np;
        need2=(v[i+1].first-v[i].first-1)*2+np;
        if (op==1)need2++;
        
  //      cout<<need1<<" "<<need2<<endl;
        
       }
      if (rspan>=need2&&rspan<=need1)
      {
       reach[i+1][np]=1;
       par[i+1][np]=op;
      }
     }
 }

/*for (int i=0;i<v.size();i++)
{
    cout<<v[i].first<<"^^"<<v[i].second<<endl;
    for (int j=0;j<=5;j++)
    cout<<reach[i][j]<<" ";
    cout<<endl;
}*/

if (v[v.size()-1].second==n)reach[v.size()-1][1]=0;
if (v[v.size()-1].second==n-1)reach[v.size()-1][5]=0;
//if (v[v.size()-1].second==n-2)reach[v.size()-1][1]=0;
p=v.size()-1;

q=2;
while ((q<=5&&reach[p][q]==0))++q;
if (q==6)if (reach[p][1])q=1;
if (q==6){cout<<-1<<endl;return 0;}

/*for (int j=1;j<=5;j++)
cout<<reach[p][j]<<" ";
cout<<endl;
*/
//cout<<q<<endl; // gt t+

// tail
if (v[p].second==n-1)ar[n]=ar[n-1];
else
{
    ps=v[p].second;
    if (q==1){++ps;ar[ps]=ar[ps-1];}
    cur=ar[ps]+1;
    ++ps;
    while (ps+2<=n)
    {
     if (ps+2==n){ar[ps]=ar[ps+1]=ar[ps+2]=cur;++cur;ps+=3;}
     else{ar[ps]=ar[ps+1]=cur;cur++;ps+=2;}
    }
    if (ps<n){ar[ps]=cur;ar[ps+1]=cur;cur++;ps+=2;}
    else if (ps==n){ar[ps]=cur-1;++ps;}
}

/*
for (int i=1;i<=n;i++)
{
    if (i-1)cout<<" ";
    cout<<ar[i];
}
cout<<endl;
*/

for (int i=v.size()-1;i;--i)
{
    if (v[i-1].first==v[i].first){for (int j=v[i-1].second+1;j<v[i].second;j++)
    {
                                      ar[j]=ar[v[i-1].second];
    }
    q=par[i][q];continue;
    }   
    else
    {
        for (int j=q;j>=1;j--)
        ar[v[i].second-q+j]=ar[v[i].second];
        tp=v[i].second-q;
        
        np=par[i][q];
        
        niters=v[i].first-v[i-1].first-1;
        for (;niters;--niters)
        {
         /*m1=(niters-1)*2;
         if (np==1)++m1;*/
         m2=(niters-1)*5+(5-np);
         qq=2;
         while (tp-qq>(v[i-1].second+m2))++qq;
         for (int j=tp-qq+1;j<=tp;j++)
          ar[j]=v[i-1].first+niters;
         tp=tp-qq;
        }
        for (int j=v[i-1].second;j<=tp;j++)
        ar[j]=v[i-1].first;
        
        q=np;
        
    }
}
cout<<ar[n]<<endl;
for (int i=1;i<=n;i++)
if (ar[i]==0)ar[i]=1;

for (int i=1;i<=n;i++)
{
    if (i-1)cout<<" ";
    cout<<ar[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}