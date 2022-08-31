/*
Rip it up, kick it out.
Blood begins to flow.
Taking chances,
The only way I know.
Sacrificed everything.
I'm the grinding stone.
Ripping flesh, drawing blood.
I'de love to eat your bones.

My world will not cave in.
I will dare so I will win.
Hear the timebombs begin to tick.
I'll hit you like a ton of bricks.

Hammer or anvil,
You must pay the price.
Thunder, lightning,
Yes, it does strike twice.
Vice grips hold me,
Keep me in control.
And if you think I'm kidding you,
You will feel the fatal blow.

My world will not cave in.
I will dare so I will win.
Hear the timebombs begin to tick.
I'll hit you like a ton of bricks, ton of bricks.

Oh yeah, you!
I know that it's true
Do you have a clue
To what I'm gonna do?

I'm gonna

Rip it up, kick it out
Blood begins to flow
Taking chances
The only way I know
Sacrificed everything
I'm the grinding stone
Ripping flesh and drawing blood
I;de love to eat your bones

My world will not cave in
I will dare so I will win
Hear the timebombs begin to tick
I'll hit you like a ton of bricks

Ton of bricks, ton of bricks

Oh yeah, you!
I know that it's true
Do you have a clue
To what I'm gonna do?

I'm gonna stop.
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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,com;
vector<pair<long, long> > v;
long val[100];
long comm[200000],mx,mp,q;
long lp;
long qu[200000];

int main(){
//freopen("codes.in","r",stdin);
//freopen("codes.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>comm[i];
}
lp=0;

while (lp<=n)
{
      q=lp+1;
      mx=0;mp=0;
      while (comm[q]!=0){if (comm[q]>mx){mx=comm[q];mp=q;}++q;}
      qu[mp]=1;
      lp=q;
}

/*for (int i=1;i<=n;i++)
cout<<comm[i]<<" ";
cout<<endl;
*/
for (int ii=1;ii<=n;ii++)
{
    com=comm[ii];
    if (com!=0)
    {
    
     if (qu[ii]){val[1]=com;cout<<"pushQueue"<<endl;continue;}
     v.clear();
     
     v.push_back(make_pair(val[0],0));v.push_back(make_pair(val[2],2));
     sort(v.begin(),v.end());
     if (v[0].first>=com)
     {cout<<"pushBack"<<endl;continue;}
     if (v[0].second==0){cout<<"pushStack"<<endl;val[0]=com;}
     if (v[0].second==1){cout<<"pushQueue"<<endl;val[1]=com;}
     if (v[0].second==2){cout<<"pushFront"<<endl;val[2]=com;}
    }
    else
    {
     v.clear();
     for (int i=0;i<3;i++)
     if (val[i]>0)v.push_back(make_pair(i,0));
     val[0]=val[1]=val[2]=0;
     cout<<v.size();
     for (int i=0;i<v.size();i++)
     {
         cout<<" ";
         if (v[i].first==0)cout<<"popStack";
         if (v[i].first==1)cout<<"popQueue";
         if (v[i].first==2)cout<<"popFront";
     }
     cout<<endl;
    }
}
cin.get();cin.get();
return 0;}