/*
With the dying

Rot in hell religious one
(Cold fate) the chosen son
Find the darkness kill the day
You said you'd never cease saying

We're the cause of death

Find the one kill the need
You're the one to make him bleed
Find the darkness little one...

We're the cause of death

Rot in hell religious one
(Cold fate) the chosen son
Find the darkness kill the day
You said you'd never cease saying

With the darkness we arise
Your hell is denied
The powers below
Reality's here

With the darkness we arise
Your hell is denied
The powers below
Reality's here
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
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

set<long> rem;
long n,k,ar[1200000],ps[1200000],need[1200000];
long q,t;
set<long>::iterator it;
long l,r;
long tt[3200000];
long long ans;

long sum(long v,long tl,long tr,long l,long r)
{
     if (l>r)return 0;
     if (l==tl&&r==tr){//cout<<tl<<" "<<tr<<" "<<"%%"<<tt[v]<<endl;
     return tt[v];}
     long tm=tl+tr;
     tm/=2;
     return sum(v*2,tl,tm,l,min(r,tm))+
     sum(v*2+1,tm+1,tr,max(l,tm+1),r);
}

void update(long v,long tl,long tr,long pos,long val)
{
 if (tl==tr){//cout<<"%"<<tl<<" "<<v<<pos<<" "<<val<<endl;
 tt[v]=val;return;}
 long tm=tl+tr;tm/=2;
 if (pos<=tm)update(v*2,tl,tm,pos,val);
 else update(v*2+1,tm+1,tr,pos,val);
 tt[v]=tt[v*2]+tt[v*2+1];
 //if (tt[v]>0)
// cout<<v<<" "<<tl<<" "<<tr<<" "<<tt[v]<<" "<<tm<<endl;
}

int main(){
//freopen("exchange.in","r",stdin);
//freopen("exchange.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{cin>>ar[i];ps[ar[i]]=i;}

rem.insert(0);
rem.insert(n+1);

for (int i=1;i<=k;i++)
{
    cin>>q;
    need[q]=1;
}

for (int i=1;i<=n;i++)
{
 t=ps[i];
 it=rem.lower_bound(t);
 --it;
 l=(*it);
 it=rem.lower_bound(t);
 r=(*it);   
 ++l;
 --r;
// cout<<l<<" "<<r<<" "<<ans<<endl;
 if (need[i]==0)// dodel
 {
 ans+=r-l+1-sum(1,1,n,l,r);
// cout<<sum(0,1,n,l,r)<<endl;
 //cout<<t<<endl;
 update(1,1,n,t,1);
 }
 else
 rem.insert(t);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}