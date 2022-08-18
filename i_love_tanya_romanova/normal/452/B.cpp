/*
It's caving in around me
What I thought was solid ground
I tried to look the other way
But I couldn't turn around
It's OK for you to hate me
For all the things I've done
I've made a few mistakes
But I'm not the only one

Step away from the ledge
I'm coming down

I could never be
What you want me to
You pulled me under
To save yourself
(Save yourself)
You will never see
What's inside of me
I pulled you under just to save myself

Was there ever any question
On how much I could take? 
You kept feeding me your bullshit
Hoping I would break
Is there anybody out there? 
Is there anyone who cares? 
Is there anybody listening? 
Will they hear my final prayers? 

Step away from the ledge
I'm coming down

I could never be
What you want me to
You pulled me under
To save yourself
(Save yourself) 
You will never see
What's inside of me
I pulled you under just to save myself
(Save myself) 

It's caving in around me 
(Caving in)
It's tearing me apart
(Tearing me)
It's all coming down around me
(Coming down)
Does anyone
Anyone
Care at all? 

I will never be
What you want me to
You pull me under
I pull you under

I could never be
What you want me to
You pulled me under
To save yourself
(Save yourself)
You will never see
What's inside of me
I pulled you under just to save myself
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

long n,m;
vector<pair<long, long> > v;
long dist;
long bst,b1,b2,b3,b4;

long gg(long x1,long y1,long x2,long y2)
{
 return abs(x1-x2)+abs(y1-y2);
}

long gd(long x,long y)
{
long res=gg(x,y,0,0);
res=min(res,gg(x,y,0,m));
res=min(res,gg(x,y,n,0));
res=min(res,gg(x,y,n,m));
 return res;
}

long g(long a,long b)
{
 return (v[a].first-v[b].first)*(v[a].first-v[b].first)+(v[a].second-v[b].second)*(v[a].second-v[b].second);
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

for (int i=0;i<=n;i++)
 for (int j=0;j<=m;j++)
  if (gd(i,j)<=4)v.push_back(make_pair(i,j));

//cout<<v.size()<<endl;

for (int i=0;i<v.size();i++)
 for (int j=0;j<v.size();j++) 
  for (int q=0;q<v.size();q++)
   for (int e=0;e<v.size();e++)
    if (i!=j&&i!=q&&i!=e&&j!=q&&j!=e&&q!=e)
    {
     dist=g(i,j)+g(j,q)+g(q,e);
     if (dist>bst)
     {
      bst=dist;
      b1=i;
      b2=j;
      b3=q;
      b4=e;
     }
    }

cout<<v[b1].first<<" "<<v[b1].second<<endl;
cout<<v[b2].first<<" "<<v[b2].second<<endl;
cout<<v[b3].first<<" "<<v[b3].second<<endl;
cout<<v[b4].first<<" "<<v[b4].second<<endl;

cin.get();cin.get();
return 0;}