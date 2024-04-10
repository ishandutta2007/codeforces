/*
All I can say is that my life is pretty plain
I like watchin' the puddles gather rain
And all I can do is just pour some tea for two
And speak my point of view but it's not sane, it's not sane

I just want someone to say to me
I'll always be there when you wake
You know I'd like to keep my cheeks dry today
So stay with me and I'll have it made

And I don't understand why I sleep all day
And I start to complain that there's no rain
And all I can do is read a book to stay awake
And it rips my life away, but it's a great escape, escape, escape, escape

All I can say is that my life is pretty plain
You don't like my point of view
You think I'm insane
It's not sane, it's not sane

I just want someone to say to me
I'll always be there when you wake
You know I'd like to keep my cheeks dry today
So stay with me and I'll have it made

And I'll have it made, and I'll have it made, oh no, no
You know we're really gonna, really gonna have it made, yeah
We're gonna have it made
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

long long n,l,ar[2000];
long long same[200][200],les[200][200];
long long ans;
long long a0,a1;

void add(long long&a,long long b)
{
 a+=b;
 if (a>=bs)a-=bs;
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
while (n){++l;ar[l]=(n&1);n/=2;}

same[l][0]=1;
for (int i=l;i;--i)
 for (int j=l;j+1;--j)
 {
  if (j==0)a0=1,a1=0;
  else a0=a1=(1<<(j-1));
  
  if (ar[i])// 1 here
  {
   add(les[i-1][j],same[i][j]*a0%bs);
   add(same[i-1][j],same[i][j]*a1%bs);
   add(same[i-1][j+1],same[i][j]);
  }
  else // can put nly 0
   add(same[i-1][j],same[i][j]*a0%bs);
  
  add(les[i-1][j],les[i][j]*(1<<j)%bs);
  add(les[i-1][j+1],les[i][j]);
 }

ans=0;
for (int i=0;i<=l;i++)
 add(ans,les[0][i]),
 add(ans,same[0][i]);

cout<<ans<<endl;

cin.get();cin.get();
return 0;}