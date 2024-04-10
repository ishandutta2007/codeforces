/*
Is it any wonder
The spell you took me under
I have been a slave to your touch
But you stretched the borders too much

Can't you see that I'm thru with you
There is nothing left to do
Too many words that have been said
Don't you realize it's too late

Hate was what you've seed
War was on your mind

Stone cold
You didn't have no mercy with me
Can't you see that I'm boned

I am here and you are there
All alone but that's my share
This is what you've done to me
You have crucified my soul

Now that it's all over
And the truth has been told
What you gonna do with me
You've traded our love for gold

All the glamour that you own
Ain't worth nothing when you're alone
Is this really where you wanted to be
Here's the truth for you to see

Hate was what you've seed
War was on your mind

Stone cold
You didn't have no mercy with me
Can't you see that I'm boned

I am here and you are there
All alone but that's my share
This is what you've done to me
You have crucified my soul
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