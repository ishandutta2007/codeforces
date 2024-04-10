/*
The embers are burning bright as the sun
The gallows are waiting for us to hang
No crime goes unpunished
Judgement will come
The hangman is waiting
Ashes remain

Driven by sorrow
Your time has come
I will not follow
The end has begun

Heaven is no place for us
Darkness will overcome
We burn in purgatorial fire

The abyss of hell
Is where we will drown
Dark lord awaits us
Torture begins

We're burning
Forever
Embracing the pain

This is our fate
Our destiny
Our legacy
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
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define MAGIC 47
#define count adsgasdgasdg

using namespace std;

long n,m,T,t;
vector<long> evs[100000];
string st;
deque<pair<long, long> > qu;
pair<long, long> tp;
long reached;
long ans[1<<20];
long users;

long parse(string st)
{
 long h,m,s;
 
 for (int i=0;i<st.size();i++)
  if (st[i]==':') st[i]=' ';
 stringstream S(st);
 S>>h;
 S>>m;
 S>>s;
 return h*3600+m*60+s;
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>T;
for (int i=0;i<n;i++)
{
    cin>>st;
    t=parse(st);
    evs[t].push_back(i+1);
//    cout<<"%"<<t<<endl;
}

reached=0;

for (int i=0;i<86400;i++)
{
 if (qu.size()==m)reached=1;
 while (true)
 {
  if (qu.size()==0)break;
  tp=qu.back();
  if (tp.first+T<=i)
  {
   qu.pop_back();
  }
  else break;
 }
 
 for (int j=0;j<evs[i].size();j++)
 {
  //cout<<qu.size()<<endl;
  
  if (qu.size()==m)reached=1;
  long id=evs[i][j];
  if (qu.size()==m)
  {
   tp=qu.front();
   tp.first=i;
   qu.pop_front();
   qu.push_front(tp);
   ans[id]=tp.second;
  }
  else
  {
   users++;
   qu.push_front(make_pair(i,users));
   ans[id]=users;
  }
 }
}

if (reached==0)
 cout<<"No solution"<<endl;
else
{
 cout<<users<<endl;
 for (int i=1;i<=n;i++)
  cout<<ans[i]<<endl;
}
cin.get();cin.get();
return 0;}