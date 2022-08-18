/*
I hate what I am and I hate what I do
Alternatives here I sit and wait for you

There are no cats in the bible did you know
God's breath is cold when you're drunk and far from home

Life - I am god gifted with life

I am video incarnate
Zapping from channel murder to channel rape
I'm pretty much into human evil
I'm personified hunger
And if I'm gonna survive this airplane crash
I'll take a knife and a fork and start eating people
Would you like to hear a story
So obviously of negative intent - yeah
Do what you will
We are god gifted

For my mum a letter I'm about to fall
I'm the least successful human cannonball
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

long n,bst;
string w[2000];
long tests,k,cc,gt,bp;
string z[2000];

void generate(vector<long> v)
{
 if (v.size()<n)
 {
  for (int j=1;j<=k;j++)
  {
   v.push_back(j);
   generate(v);
   v.pop_back();
  }
  return;
 }
 
 for (int i=0;i<v.size();i++)
  if (z[v[i]]!=w[i+1])return ;
 long ci=0;
 for (int i=0;i<v.size();i++)
  for (int j=i+1;j<v.size();j++)
  {
   if (v[i]<v[j])++ci;
  }
  if (ci>bst){bst=ci;bp=gt;}
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);


bst=-1;

cin>>n;
for(int i=1;i<=n;i++)
{
 cin>>w[i];
}

cin>>tests;
for (;tests;--tests)
{
 cin>>k;
 ++cc;
 gt=cc;
 for (int j=1;j<=k;j++)
  cin>>z[j];
  vector<long> vec;
  generate(vec);
}

if (bst<0)cout<<"Brand new problem!"<<endl;
else
{
 cout<<bp<<endl;
 cout<<"[:|";
 for (int i=1;i<=bst;i++)cout<<"|";
 cout<<":]"<<endl;
}


cin.get();cin.get();
return 0;}