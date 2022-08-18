/*
What comes as no surprise
To a jaded mind no less
Insight comes from soothing grace
Left to waiting days
Another chord unstrummed

Our secret's safe and sound
Solid now, unless it breaks in two
Faithfully unbound
And none of this was ever built to last

With the paleness of a less than life
From a corner watching old paint dry
Never once a break
Into the self again
An endeavor that will flat or fail
What maturity comes to end
Never one to face
Another beat undone

Our secret's safe and sound
Solid now, unless it breaks in two
Faithfully unbound
And none of this was ever built to last

Once again
Another instant saved today
Left a print that leads nowhere
Never built to last
What makes it work
A part of life that'll make a weak heart grow
Take it if you're willing to pay, willing to kill
Prepared to lay it down
Just know that
(The prayer, the lord, the weaker, the prey)
Was never ever built to last
Never ever built to last
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
#define bsize 512

using namespace std;

string st;
long n,k,used[20000];

bool cinc(long ps)
{
 if (st[ps]+1<'a'+k&&used[st[ps]+1]==0)return true;
 if (st[ps]+2<'a'+k&&used[st[ps]+2]==0)return true;
 if (st[ps]+3<'a'+k&&used[st[ps]+3]==0)return true;
 return false;
}

string doinc(string st,long ps)
{
 ++st[ps];
 while (used[st[ps]])++st[ps];
 for (int i=ps+1;i<st.size();i++)
 {
  for (int j='a';j<='z';j++)
  used[j]=0;
  if (i)used[st[i-1]]=1;
  if (i>1)used[st[i-2]]=1;
  st[i]='a';
  while (used[st[i]])++st[i];
 }
 return st;
}

int main(){
//freopen("highway.in","r",stdin);
//freopen("highway.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
cin>>st;

for (int i=st.size()-1;i+1;--i)
{
 for (int j='a';j<'a'+k;j++)
  used[j]=0;
 if (i>0)used[st[i-1]]=1;
 if (i>1)used[st[i-2]]=1;
 if (cinc(i))
 {
  st=doinc(st,i);
  cout<<st<<endl;
  return 0;
 }
}

cout<<"NO"<<endl;

cin.get();cin.get();
return 0;}