/*
Caged... and riding the snake
Straight down from the night
True love for the fix
and she never been able
one minute
to kick back the feelings enticed
and you know it's never the same
Venomous poison constricting your life

Life... enough of the taste
Sweet demonic night
Raised up on her legs
Everytime you encounter the demon
Your future forever forever is lost
While riding the snake
who suffers the loss

Is there no shame
Is life so bad without you...
So far away
and I still can't fight you!!!

Climb... straight into the veins
Ran into the cell
Straight up to the snake
and it never will ever be

Hiding from futures
of innocence lost
Will we ever escape
the clinch of the jaws

Drowning in pools filled with lies
Filled in with pain
Watch how the serpent survives...
Simmering hate!!!

Caged... and riding the snake
Love loss for the fix
bit down on the snake
Fates sending her back
No place to go
She will never change her ways
Spent to many nights
and can not take
raw emotions from others

Drowning in pools filled with lies
Condemned in pain
Watch how the serpent survives...
Simmering hate!!!
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

string st;
vector<long> g[1000],ans;
long deg[1000];
long usd[1000];

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int i=1;i<=3;i++)
{
    cin>>st;
    if (st[1]=='<')swap(st[0],st[2]);
    g[st[2]-'A'].push_back(st[0]-'A');
    deg[st[0]-'A']++;
}

for (int i=1;i<=3;i++)
{
 for (int j=0;j<3;j++)
 if (deg[j]==0&&usd[j]==0)
 {
  ans.push_back(j+'A');
  usd[j]=1;
  for (int q=0;q<g[j].size();q++)
  {
      deg[g[j][q]]--;
  }
 }   
}
//reverse(ans.begin(),ans.end());
if (ans.size()!=3)cout<<"Impossible"<<endl;
else {for (int i=0;i<ans.size();i++)
cout<<char(ans[i]);cout<<endl;}

cin.get();cin.get();
return 0;}