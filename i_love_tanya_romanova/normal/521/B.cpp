/*
Well I want you to notice
To notice when I'm not around
I know that your eyes
See straight through me
And speak to me
Without a sound

I wanna hold you
Protect you
From all of the things
I've already endured
And I wanna show you
To show you
All the things
That this life has in store for you
I'll always love you
The way that a father
Should love his daughter

When I walked out this morning
I cried as I walked to the door
I cried about how long I'd be away for
Cried about leavin' you all alone

I wanna hold you
Protect you
From all of the things
I've already endured
And I wanna show you
To show you
All the things
That this life has in store for you
And I'll always love you
The way that a father
Should love his daughter

Sweet Zoe Jane
Sweet Zoe Jane

So I wanted to say this
'Cause I wouldn't know where to begin
To explain to you what I have been through
To explain where your Daddy has been

So I wanna hold you
Protect you
From all of the things
I've already endured
And I wanna show you
Show you
All the things
That this life has in store for you
And I'll always love you
The way that a father
Should love his daughter

Sweet Zoe Jane
Sweet Zoe Jane
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
#define bs 1000000009
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define MAG 10000

using namespace std;

long n,x[1<<20],y[1<<20];
set<pair<long, long> > have;
map<pair<long, long> ,long > mapp;
pair<long, long> tp;
long mark[1<<20];
long stand[1<<20];
long bad[1<<20];
set<long> nice;
set<long> ::iterator it;
long long ans;
long crits[1<<20];

void reeval(pair<long, long> p)
{
 if (have.find(p)==have.end())return;
 long id=mapp[p];
 stand[id]=0;
 pair<long, long> tp;
 tp=make_pair(p.first-1,p.second-1);
 if (have.find(tp)!=have.end())
  ++stand[id];
 tp.first++;
 if (have.find(tp)!=have.end())
  ++stand[id];
 tp.first++;
 if (have.find(tp)!=have.end())
  ++stand[id];
 if (stand[id]>1)
  return ;// ok
 tp.first-=2;
 while (have.find(tp)==have.end())
  ++tp.first;
 long danger=mapp[tp];
 if (nice.find(danger)!=nice.end())
  nice.erase(danger);
}

void recheck(pair<long, long> p)
{
 if (have.find(p)==have.end())return;
 if (nice.find(mapp[p])!=nice.end())return;
 nice.insert(mapp[p]);
 pair<long, long> tp;
 
 tp=make_pair(p.first-1,p.second+1);
 reeval(tp);
 tp.first++;
 reeval(tp);
 tp.first++;
 reeval(tp);
}

int main(){
//freopen("evacuation.in","r",stdin);
//freopen("evacuation.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;

for (int i=0;i<n;i++)
{
 cin>>x[i]>>y[i];
 have.insert(make_pair(x[i],y[i]));
 mapp[make_pair(x[i],y[i])]=i;
}

for (int i=0;i<n;i++)
{
    if (y[i]==0){stand[i]=0;continue;}
    tp=make_pair(x[i]-1,y[i]-1);
    if (have.find(tp)!=have.end())++stand[i];
    tp.first++;
    if (have.find(tp)!=have.end())++stand[i];
    tp.first++;
    if (have.find(tp)!=have.end())++stand[i];
}

for (int i=0;i<n;i++)
{
    tp=make_pair(x[i]-1,y[i]+1);
    if (have.find(tp)!=have.end())
    {
     int id=mapp[tp];
     if (stand[id]==1)
      bad[i]=1;
    }
    tp.first++;
    if (have.find(tp)!=have.end())
    {
     int id=mapp[tp];
     if (stand[id]==1)
      bad[i]=1;
    }
    tp.first++;
    if (have.find(tp)!=have.end())
    {
     int id=mapp[tp];
     if (stand[id]==1)
      bad[i]=1;
    }
}

for (int i=0;i<n;i++)
 if (bad[i]==0)
  nice.insert(i);

for (int i=0;i<n;i++)
{
    if (i%2==0)
    {
     it=nice.end();
     --it;
    }
    else
    {
     it=nice.begin();
    }
    int id=(*it);
   // cout<<"^"<<id<<endl;
    ans=ans*n+id;
    ans%=bs;
    have.erase(make_pair(x[id],y[id]));
    nice.erase(it);
    tp=make_pair(x[id]-1,y[id]+1);
    reeval(tp);
    tp.first++;
    reeval(tp);
    tp.first++;
    reeval(tp);
    tp=make_pair(x[id]-1,y[id]-1);
    recheck(tp);
    tp.first++;
    recheck(tp);
    tp.first++;
    recheck(tp);
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}