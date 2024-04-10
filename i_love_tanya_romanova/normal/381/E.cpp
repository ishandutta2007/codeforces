/*
Is there anything left
Left of me to save?
My life is like a carnival
My body a sunken grave

It's what I have to do
To distance me from you
Lays a suffering inside
And my veins are showing through
A man become a child. Are you happy with your prize?
With haunted looks of fear
I step away from your side
My mind a fractured ruin. The crushing of my soul
It is time to spread my wings
To fill this empty hole
It has now begun. The forces under me
Will conquer all before
And bring me to my victory

I've seen that man before
Down from the fall
And now standing tall
I've seen this
I have been this
And now I am my own man

No more misery
Look outside and see
What are you waiting for?
Pick yourself up
Get up off the floor
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

string st;
long match[1200000];
stack<long> v;
long temp;
long m,a,b;
struct dat
{
 long op;
 long cl;
 long pars;
};

dat combine(dat a,dat b)
{
 long np=min(a.op,b.cl);
 dat temp;
 temp.pars=a.pars+b.pars+np;
 temp.op=a.op+b.op-np;
 temp.cl=a.cl+b.cl-np;
 return temp;
}

dat res[2200000];

dat make_data(char c)
{
 dat temp;
 temp.pars=0;
 temp.op=temp.cl=0;
 if (c=='(')temp.op++;
 if (c==')')temp.cl++;
 return temp;
}

void build(long v,long tl,long tr)
{
 if (tl==tr)
 {
  res[v]=make_data(st[tl]);
  return;
 }
 long tm=tl+tr;
 tm/=2;
 build(v*2,tl,tm);
 build(v*2+1,tm+1,tr);
 res[v]=combine(res[v*2],res[v*2+1]);
}

dat gett(long v,long tl,long tr,long l,long r)
{
 if (l>r)return make_data('.');
 if (l==tl&&r==tr)
 {
  return res[v];
 }
 long tm=tl+tr;
 tm/=2;
 return combine(gett(v*2,tl,tm,l,min(r,tm)),gett(v*2+1,tm+1,tr,max(l,tm+1),r));
}

int main(){
//freopen("circuit.in","r",stdin);
//freopen("circuit.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
for (int i=0;i<st.size();i++)
match[i]=-1;

for (int i=0;i<st.size();i++)
{
 if (st[i]=='(')v.push(i);
 else
 {
  if (v.size()==0)continue;
  temp=v.top();
  v.pop();
  match[i]=temp;
 }   
}

/*for (int i=0;i<st.size();i++)
cout<<match[i]<<" ";
cout<<endl;
*/

build(1,0,st.size()-1);
cin>>m;
for (int i=0;i<m;i++)
{
 cin>>a>>b;
 --a;
 --b;
 cout<<gett(1,0,st.size()-1,a,b).pars*2<<endl;   
}
cin.get();cin.get();
return 0;}