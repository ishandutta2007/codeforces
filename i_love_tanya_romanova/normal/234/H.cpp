/*
Slaves
Hebrews born to serve, to the pharaoh
Heed
To his every word, live in fear
Faith
Of the unknown one, the deliverer
Wait
Something must be done, four hundred years

So let it be written
So let it be done
I'm sent here by the chosen one
So let it be written
So let it be done
To kill the first born pharaoh son
I'm creeping death

Now
Let my people go, land of goshen
Go
I will be with thee, bush of fire
Blood
Running red and strong, down the Nile
Plague
Darkness three days long, hail to fire

So let it be written
So let it be done
I'm sent here by the chosen one
So let it be written
So let it be done
To kill the first born pharaoh son
I'm creeping death

Die by my hand
I creep across the land
Killing first born man
Die by my hand
I creep across the land
Killing first born man

I
Rule the midnight air the destroyer
Born
I shall soon be there, deadly mass
I
Creep the steps and flood final darkness
Blood
Lambs blood painted door, I shall pass

So let it be written
So let it be done
I'm sent here by the chosen one
So let it be written
So let it be done
To kill the first born pharaoh son
I'm creeping death
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
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
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh

#define  INF 20000000000ll
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long n,m,q,fl,dp1,ttl,dp2;
vector<long> v,v1,ans1,mv,v2,v3,v4,answ,ans;
int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++){cin>>q;v1.push_back(q);}

cin>>m;

for (int i=0;i<m;i++)
{cin>>q;v2.push_back(q);}

dp1=dp2=1;
for (int i=1;i<v1.size();i++)
{if (v1[i]!=v1[i-1])dp1++;
}
if (v1[v1.size()-1]==1)dp1++;

for (int i=1;i<v1.size();i++)
if (v1[i]!=v1[i-1])dp2++;
if (v2[v2.size()-1]==1)dp2++;

for (int i=0;i<v1.size();i++)
v3.push_back(i+1);
for (int i=0;i<v2.size();i++)
v4.push_back(i+v1.size()+1);


      while (v1.size()>0&&v1[v1.size()-1]==0)
      {ans1.push_back(0);ans.push_back(v3[v1.size()-1]);v3.pop_back();v1.pop_back();}
      
      while (v2.size()>0&&v2[v2.size()-1]==0)
      {     ans1.push_back(0);
            ans.push_back(v4[v2.size()-1]);v4.pop_back();v2.pop_back();}
      
      
      
while (v1.size()||v2.size())
{
      answ.push_back(ttl);
      fl=0;
      
      while (v1.size()>0&&v1[v1.size()-1]==1)
      {ttl++;ans1.push_back(1);ans.push_back(v3[v1.size()-1]);v3.pop_back();v1.pop_back();}
      
      while (v2.size()>0&&v2[v2.size()-1]==1)
      {
            ttl++;ans1.push_back(1);ans.push_back(v4[v2.size()-1]);v4.pop_back();v2.pop_back();}
      
      if (v1.size()==0&&v2.size()==0)break;
      answ.push_back(ttl);fl=1;
      
      while (v1.size()>0&&v1[v1.size()-1]==0)
      {ttl++;ans1.push_back(0);ans.push_back(v3[v1.size()-1]);v3.pop_back();v1.pop_back();}
      
      while (v2.size()>0&&v2[v2.size()-1]==0)
      {
            ttl++;ans1.push_back(0);ans.push_back(v4[v2.size()-1]);v4.pop_back();v2.pop_back();}
      
      
      
}

reverse(ans.begin(),ans.end());
reverse(ans1.begin(),ans1.end());

for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
    cout<<endl;

//cout<<answ.size()<<endl;

//for (int i=0;i<ans1.size();i++)
//{
//cout<<ans1[i]<<" ";}
//cout<<endl;

for (int i=1;i<ans1.size();i++)
{if (ans1[i]!=ans1[i-1]){mv.push_back(i);
}}
if (ans1[ans1.size()-1]==1)mv.push_back(ans1.size());
cout<<mv.size()<<endl;

//reverse(answ.begin(),answ.end());

for (int i=0;i<mv.size();i++)
{if (i)cout<<" ";cout<<mv[i];}

cout<<endl;


cin.get();cin.get();
return 0;}