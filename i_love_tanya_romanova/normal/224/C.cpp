/*
Under the lights where we stand tall
Nobody touches us at all
Showdown, shootout, spread fear within, without
We're gonna take what's ours to have
Spread the word throughout the land
They say the bad guys wear black
We're tagged and can't turn back

You see us comin'
And you all together run for cover
We're taking over this town

Here we come reach for your gun
And you better listen well my friend, you see
It's a pistol is down below aimed at you
We're the cowboys from hell.

Aimed at you we're the cowboys from hell
Deed is done again, we've won
Ain't talking no tall tales friend
'Cause high noon, your doom
Comin' for you we're the cowboys from hell

Pillage the village, trash the scene
But better not take it out on me
'Cause a ghost town is found
Where your city used to be
So out of the darkness and into the light
Sparks fly everywhere in sight
From my double barrel, 12 gauge,
Can't lock me in your cage

You see us comin'
And you all together run for cover
We're taking over this town

Here we come reach for your gun
And you better listen well my friend, you see
It's a pistol is down below aimed at you
We're the cowboys from hell.
Deed is done again, we've won
Ain't talking no tall tales friend
'Cause high noon, your doom
Comin' for you we're the cowboys from hell
*/

//#pragma comment(linker, "/STACK:16777216")
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
#include <list>
#include <memory.h>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
const int MAXN = 120000; 

string st;
long bst,bp,q,ss[200000],ts,ppar[200000],par[200000],fl;
stack<pair<long, char> > s;
pair<long, char> p;

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
bst=-1;
for (int i=0;i<st.size();i++)
par[i]=ppar[i]=-1;

for (int i=0;i<st.size();i++)
{
    if (st[i]=='['||st[i]=='('){p=make_pair(i,st[i]);s.push(p);}
    else
    {
        fl=1;
        if (s.size()==0)fl=0;
        
        while (fl)
        {
              p=s.top();
              s.pop();
              if (s.size()==0)fl=0;
              if (st[i]==')'&&p.second=='['){while (s.size())s.pop();fl=0;continue;}
              if (st[i]==']'&&p.second=='('){while (s.size())s.pop();fl=0;continue;}
              fl=0;
              par[i]=p.first;
              
        }
        
    }
}

//for (int i=0;i<st.size();i++)
//cout<<i<<" "<<par[i]<<endl;

for (int i=st.size()-1;i+1;--i)
{
    q=par[i]-1;
    while (q>=0&&par[q]!=-1)
    q=par[q]-1;
    ppar[i]=q+1;
}


//for (int i=0;i<st.size();i++)
//cout<<i<<" "<<ppar[i]<<endl;

for (int i=0;i<st.size();i++)
{ss[i+1]=ss[i]+(st[i]=='[');}

bst=-1;
bp=-1;

for (int i=0;i<st.size();i++)
{
    if (ppar[i]<i&&ppar[i]!=-1)
    {
                  ts=ss[i+1]-ss[ppar[i]];
                  if (ts>bst){bst=ts;bp=i;}
    }
}

//cout<<bst<<" "<<bp<<endl;
if (bst==-1)
{
            cout<<0<<endl;
            cout<<endl;
}
else

{cout<<bst<<endl;
 q=bp;
 q=ppar[bp];
 for (int i=q;i<=bp;i++)
 cout<<st[i];
 cout<<endl;
}
cin.get();cin.get();
return 0;}