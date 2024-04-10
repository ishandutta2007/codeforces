/*
It is no mystery
What you get is what you see
You betrayed my loyalty
You've gone and done me wrong
Now I do you harm
My revenge is guaranteed
You stabbed me in the back
Spit right in my eye
Dragging me into the fray
Take you out, right you off, there's never enough
Ways to throw you away

[Chorus:]
You'd better start runnin'
Cause you know that I'm comin'
Cocked and loaded and I never miss
I'm onto your game
And I'm layin' the blame
And I'm addin' your name to my blacklist
You should've thought twice
Cause your playin' with your life
You must have some sort of death wish
I haven't any doubt
That your time has run out
Cause I've added your name
To my blacklist

You tried to beat me
Thought you could defeat me
But how you we ever wrong
I rise to the occasion
Character assassination
To put you down where you belong
You've got a lot to say
When I'm so far away
Now you've got a problem with me
Take you out, write you off, when I've had enough
Of your verbal debris

[Chorus]

For all the shit you talk
You've never walked the walk
All you do is run and hide
Slander me, slag me
I'm not a man you should deride
I've heard everything
All your mudslinging
You better run, as fast as you can
Take you out, write you off, are you brave enough
To stand and fight like a man

[Chorus]
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
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n;
long pr[10000];
vector<long> v;
set<long> has;
long ul;
long limm;
set<long>::iterator it;
long calc[100];vector<long> v1;
long need[200];

void generate(long x)
{
     has.insert(x);
//     cout<<ul<<endl;
     for (int j=0;j<ul;j++)
     {
         if (x*v[j]<=limm&&has.find(x*v[j])==has.end())
         {
          has.insert(x*v[j]);
          generate(x*v[j]);
         }
     }
}

bool check()
{
 
for (int j=0;j<ul;j++)
need[j]=(n+1)/2;

for (int j=v1.size()-1;j>=v1.size()-n;--j)
{
    long mx,mp;
    mx=-1;mp=0;
    for (int q=0;q<ul;q++)
    if (need[q]>mx){mx=need[q];mp=q;}
    if (v1[j]%v[mx])continue;
    for (int q=0;q<ul;q++)
    if (v1[j]%v[q]==0)--need[q];
 //   if (j+1!=v1.size())cout<<" ";
 //   cout<<v1[j];
}
for (int i=0;i<ul;i++)
if (need[i]>0)return false;
return true;
}

int main(){
//freopen("gift.in","r",stdin);
//freopen("gift.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);


pr[1]=1;
for (int i=2;i<=1000;i++)
if (pr[i]==0)
for (int j=i*2;j<=1000;j+=i)
pr[j]=1;

for (int i=1;i<=1000;i++)
if (pr[i]==0)
v.push_back(i);

cin>>n;
limm=n*n*2;
for (int upp=2;upp<=10;upp++)
{
    has.clear();
    ul=upp;
    generate(1);
    for (int j=0;j<upp;j++)
    calc[j]=0;
   /* for (it=has.begin();it!=has.end();++it)
    {
        long q=(*it);
        for (int j=0;j<upp;j++)
        if (q%v[j]==0)++calc[j];
    }
    */
    if (has.size()>=n*2)break;;
   // if (check()==false)continue;
    it=has.end();
    --it;
/*    cout<<has.size()<<endl;
    for (int j=0;j<upp;j++)
    cout<<calc[j]<<" ";
    cout<<endl;
*/

}

for (it=has.begin();it!=has.end();++it)
{
    v1.push_back(*it);
}
//reverse(v1.begin(),v1.end());

for (int j=0;j<ul;j++)
need[j]=(n+1)/2;

long done=0;
for (int j=v1.size()-1;j>=0;--j)
{
    long mx,mp;
    mx=-1;mp=-1;
    for (int q=0;q<ul;q++)
    if (need[q]>mx){mx=need[q];mp=q;}
    if (mp>-1)if (v1[j]%v[mp])continue;
    if (done<n){
    cout<<v1[j]<<" ";++done;
    
    for (int q=0;q<ul;q++)
    if (v1[j]%v[q]==0)--need[q];
    }
 //   if (j+1!=v1.size())cout<<" ";
 //   cout<<v1[j];
}
cout<<endl;
/*
cout<<done<<endl;
for (int i=0;i<ul;i++)
cout<<need[i]<<" ";
cout<<endl;
*/
cin.get();cin.get();
return 0;}