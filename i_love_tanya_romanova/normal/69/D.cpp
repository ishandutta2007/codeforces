/*
A certain feeling assails
Visions form to wonder why
It still keeps fading
Away to the stars

The sanitarium is the night of the mind
Hidden where no-one wants to know
As nightside keeps saving your life
With its silver-painted dawn

The sanitarium holds the keys of the night
In a place no-one wants to know
And dance, dance for staying alive tonight
And you're not alone

On and on the rains with their anaemic crystals wash the pitch away
And I will follow you through centuries of famine and there will still be horror

Nightly blood anaemia
Night and blood, anaemia

As black sprites keep draining your life
When at night you're all alone
And dance, dance to remain alive
As this night beholds no dawn
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
#define N 120000

using namespace std;

long x,y,n,d,dx[2000],dy[2000];
long win[1000][1000];
bool solved[1000][1000];

bool bad(long qx,long qy)
{
 long dd=(qx-200)*(qx-200)+(qy-200)*(qy-200);
 return (dd>d*d);
}

long solve(long qx,long qy)
{
 if (bad(qx,qy))return 1;
 if (solved[qx][qy])return win[qx][qy];
 solved[qx][qy]=1;
 long w=0;
 for (int i=1;i<=n;i++)
 {
  if(solve(qx+dx[i],qy+dy[i])==0)w=1;
 }
 win[qx][qy]=w;
 return win[qx][qy];
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>x>>y>>n>>d;
for (int i=1;i<=n;i++)
 cin>>dx[i]>>dy[i];

x+=200;
y+=200;
if (solve(x,y)==1)cout<<"Anton"<<endl;
else cout<<"Dasha"<<endl;

cin.get();cin.get();
return 0;}