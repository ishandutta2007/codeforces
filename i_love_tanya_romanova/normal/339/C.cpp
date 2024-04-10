/*
Spirits coming from the mind,
waking up my deepest horrors,
capture my thoughts, make me blind.

Weird, cause I don't want to see
the abyss of my possibilities.

Scared I can't look away.

It has come to my side.
Sister demon - my bride.

I want you, I need you
and I have set you free.
You're always right behind me,
I know the devil's sent you to me.
You want me, you need me,
now that I've set you free.
Look always right behind you,
You know the devil's sent me to you.

What has started as a longing
almost is possession now,
it drives me again and again.
Put a light into your window,
maybe I can find a hold.
I run against myself till I find the end.

Sent by the devil
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
#define bs 2000000014

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

string st;
long n,dp[1100][20][60];
pair<long, long> par[1100][20][60];
long al,aw;
vector<long> answ;

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
cin>>n;
if (1>2)cout<<"NO"<<endl;
else
{
// move - last - dw+20

dp[0][0][20]=1;

for (int move=0;move<=n;move++)
for (int last=0;last<=10;last++)
for (int dw=10;dw<=30;dw++)   
{ 
 if (dp[move][last][dw]==0)continue;
 //cout<<move<<" "<<last<<" "<<dw<<endl;
 if (move==n&&dp[move][last][dw]==1)
 {
  al=last;aw=dw;
 }
 
 for (int ad=1;ad<=10;ad++)
 {
     if (st[ad-1]=='0')continue;
     if (ad==last)continue;
     long ndw=dw;
     if (move%2)ndw+=ad;else ndw-=ad;
     if (dw<20&&ndw<=20)continue;
     if (dw>20&&ndw>=20)continue;
     dp[move+1][ad][ndw]=1;
     par[move+1][ad][ndw]=make_pair(last,dw);
 }
 
}

 if (al==0&&aw==0)
 cout<<"NO"<<endl;
 else
 {
  
  for (int move=n;move;--move)
  {
      answ.push_back(al);
      long tal,taw;
      tal=par[move][al][aw].first;taw=par[move][al][aw].second;
      al=tal;aw=taw;
   //   cout<<al<<" "<<aw<<endl;
  }
  cout<<"YES"<<endl;   
  reverse(answ.begin(),answ.end());
  for (int i=0;i<answ.size();i++)
  {
      if (i)cout<<" ";
      cout<<answ[i];
  }cout<<endl;
 }
 
}
cin.get();cin.get();
return 0;}