/*
Maybe one day I'll be an honest man
Up till now I'm doing the best I can
Long roads.Long days, of sunrise, to sunset
Sunrise to sunset

Dream on brothers while you can
Dream on sisters I hope you will find the one
All of our lives, covered up quickly by the tides of time

Spend your days full of emptiness
Spend your years full of loneliness
Wasting love, in a desperate caress
Rolling shadows of night

Dream on brothers while you can
Dream on sisters I hope you will find the one
All of our lives, covered up quickly by the tides of time

Sands are flowing and the lines are in your hand
In your eyes I see the hunger, and the desperate cry that tears the night

Spend your days full of emptiness
Spend your years full of loneliness
Wasting love, in a desperate caress
Rolling shadows of night
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

long n;
long up,dwn,lmove;
vector<long> ans;
int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
if (n%4>1)
cout<<-1<<endl;
else
{
 if (n%4==0)
 {
  up=n;dwn=2;
  lmove=1;
  for (int i=1;i<=n/2;i++)
  {
      if (lmove==1){ans.push_back(dwn);dwn+=2;lmove=0;}
      else{ans.push_back(up);up-=2;lmove=1;}
  }
  up=n/2+1;dwn=n/2-1;
  lmove=1;
  for (int i=1;i<=n/2;i++)
  {
      if (lmove==1){ans.push_back(dwn);dwn-=2;lmove=0;}
      else{ans.push_back(up);up+=2;lmove=1;}
  }
 }
 else
 {
 dwn=2;
 up=n-(n+1)%2;
 lmove=1;
 for (int i=1;i<=n;i++)
 {
  if (i==n/2+1&&n%2==1)
   {ans.push_back(i);up-=2;lmove=0;}
   else if (lmove==0){ans.push_back(up);lmove=1;up-=2;}
   else {ans.push_back(dwn);lmove=0;dwn+=2;}   
 }
 
 }
 
 for (int i=0;i<ans.size();i++)
 {if (i)cout<<" ";
 cout<<ans[i];}
 cout<<endl;
}

cin.get();cin.get();
return 0;}