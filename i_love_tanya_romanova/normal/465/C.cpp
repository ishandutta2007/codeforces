/*
All of my path has gone astray
I'm just trying to find my way
Wandered here from far away
I'm just trying to find my way

You were never meant to see
All those things inside of me
Now that you have gone away
I'm just trying to find my way

I have made a grave mistake
Pray the Lord, my soul to take
Those of who we used to be
I can feel them come for me

Looks as though they're here to stay
I'm just trying to find my way

Please, I never meant to
Please, I never meant for this

I have been to every place
I have been to everywhere
I'm just trying to find my way
Oh, dear Lord, hear my prayer
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