/*
My legs are weary but I still walk
My hands are sore and broken but I still clutch
My heart is jaded but I still love
My cup is empty but I still pour

All I ever wanna be, all I ever needed be
Was whatever you wanted me to
But you took that from me, yeah

I was never enough for you
I should have known, I shoud've known
I was never enough for you
Don't waste my time, don't waste my

I lost the feeling but I still touch
I stopped believing but I still trust
All I ever want to be, all I ever needed be
Was whatever you wanted me to
But you took that from me, yeah

I was never enough for you
I should have known, I should've known
I was never enough for you
Don't waste my time

All these questions asking why
I'll just close my eyes, my eyes
All these people, asking why
I'll just wave goodbye, goodbye

Time pushin' forward
I'm sick and tired, need a little shelter
Drag the glass across my eyes
Cut me open, cut me wide
Bleed me for the winner, just tear it away

I was never enough for you
I should have known, I should've known
I was never enough for you
Don't waste my time

I was never enough for you
Just wastin' my time
Don't waste mine
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

long tests;
string st;
string cm;
vector<string> v;
string temp;

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>tests;
for (;tests;--tests)
{
 cin>>cm;
 if (cm=="pwd")
 {
  for (int i=0;i<v.size();i++)
  cout<<"/"<<v[i];
  cout<<"/"<<endl;
 }
 else
 {
  cin>>st;
  if (st[0]=='/')v.clear(),st.erase(st.begin());
  st+="/";
  temp="";
  for (int i=0;i<st.size();i++)
  {
   if (st[i]=='/'){if (temp=="..")v.pop_back();else v.push_back(temp);
   temp="";}
   else
   {
       temp+=st[i];
   }
  }
 }
}

cin.get();cin.get();
return 0;}