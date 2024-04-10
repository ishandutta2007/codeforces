/*
Your cruel device,
Your blood like ice.
One look could kill,
My pain, your thrill.

I wanna love you, but I better not touch (don't touch)
I wanna hold you, but my senses tell me to stop
I wanna kiss you, but I want it too much (too much)
I wanna taste you, but your lips are venomous poison

You're poison runnin through my veins
You're poison, I don't wanna break these chains.

Your mouth, so hot
Your web, I'm caught
Your skin, so wet
Black lace on sweat

I hear you callin and it's needles and pins (and pins)
I wanna hurt you just to hear you screaming my name
Don't wanna touch you, but you're under my skin (deep in)
I wanna kiss you, but your lips are venomous poison

You're poison runnin through my veins
You're poison, I don't wanna break these chains
Poison

One look (one look), could kill (could kill),
My pain, your thrill.

I wanna love you, but I better not touch (don't touch)
I wanna hold you, but my senses tell me to stop
I wanna kiss you, but I want it too much (too much)
I wanna taste you, but your lips are venomous poison

You're poison runnin through my veins
You're poison, I don't wanna break these chains
Poison

I wanna love you, but I better not touch (don't touch)
I wanna hold you, but my senses tell me to stop
I wanna kiss you, but I wanna too much (too much)
I wanna taste you, but your lips are venomous poison

Yeah
Well I don't wanna break these chains
Poison

Runnin deep inside my veins
Burnin deep inside my veins
Poison
I don't wanna break these chains
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
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
 
#define  INF 100000000
#define eps 1e-5
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
 
using namespace std;

long n,nu[100];
vector<long> v,v2;
vector<string> ip;
vector<vector<long> > ans,ans1,ans2;
vector<long> v1;
long usd[100];

bool ok(vector<long> st,long l,long r)
{
     if (r-l>5)return false;
 if (l<r-1&&st[l]==0)return false;
 long s=0;
 for (int i=l;i<r;i++)
 s=s*10+st[i];if (s<256)return true;return false; 
}

void genip(vector<long> v,long p1,long p2,long p3,long p4)
{
 string st="";
 for (int i=0;i<p1;i++)
 st=st+char(v[i]+48);
 st+='.';
 for (int i=p1;i<p2;i++)
 st=st+char(v[i]+48);
 st+='.';
 for (int i=p2;i<p3;i++)
 st=st+char(v[i]+48);
 st+='.';
 for (int i=p3;i<p4;i++)
 st=st+char(v[i]+48);
 ip.push_back(st);
}

void generate(vector<long> v)
{
 if (v.size()>0)
 ans.push_back(v);
 
 if (v.size()==6)return;
 for (int i=0;i<n;i++)
 {
     v1=v;
     v1.push_back(nu[i]);
     generate(v1);
}    
}

bool check(vector<long> v)
{
     for(int i=0;i<n;i++)
     usd[i]=0;
     for (int i=0;i<v.size();i++)
     for (int j=0;j<n;j++)
     if (v[i]==nu[j])
     usd[j]=1;
     for (int i=0;i<n;i++)
     if (usd[i]==0)return false;
     return true;
}

vector<long> gen1(vector<long> v)
{
 v1=v;
 v2=v;
 reverse(v2.begin(),v2.end());
 for (int i=0;i<v2.size();i++)
 v1.push_back(v2[i]);
 return v1;
}

vector<long> gen2(vector<long> v)
{
 v1=v;
 v2=v;
 v2.erase(v2.end()-1);
  reverse(v2.begin(),v2.end());
 for (int i=0;i<v2.size();i++)
 v1.push_back(v2[i]);
 return v1;

}

int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
cin>>nu[i];

if (n>6){
         cout<<0<<endl;
         }
else
{
 generate(v);



for (int i=0;i<ans.size();i++)
if (check(ans[i]))
ans1.push_back(ans[i]);

/*
cout<<ans1.size()<<endl;
for (int i=0;i<ans1.size();i++)
{
    for (int j=0;j<ans1[i].size();j++)
    cout<<ans1[i][j];
    cout<<endl;
}*/

for (int i=0;i<ans1.size();i++)
{
    ans2.push_back(gen1(ans1[i]));
    ans2.push_back(gen2(ans1[i]));
}
/*cout<<ans2.size()<<endl;
for (int i=0;i<ans2.size();i++)
{
    for (int j=0;j<ans2[i].size();j++)
    cout<<ans2[i][j];
    cout<<endl;
}*/

for (int i=0;i<ans2.size();i++)
{
   n=ans2[i].size();
   for (int j=1;j<=n;j++)
   if (ok(ans2[i],0,j))
    for (int q=j+1;q<=n;q++)
     if (ok(ans2[i],j,q))
      for (int w=q+1;w<n;w++)
       if (ok(ans2[i],q,w))
        for (int e=n;e<=n;e++)
         if (ok(ans2[i],w,e))
         {
          genip(ans2[i],j,q,w,e);
         }   
}

cout<<ip.size()<<endl;
for (int i=0;i<ip.size();i++)
cout<<ip[i]<<endl;
}
cin.get();cin.get();
return 0;}