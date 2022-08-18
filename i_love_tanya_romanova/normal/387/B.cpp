/*
Spawn of the ever rolling abyss
Ever espousing unluminous
Charred soul - Burned at rebirth
Quest not save the death of the sun

Repulsed by the light
Heart pumping ice
So cold to this world
Reclude until the summoning
Sworn to the black

Our father begotten, not made
Before all legends of man
Receive my loyalty, my offering
In my veins; the blood of the ancient brood
Summon me

Burning inside, I feel the call
Blood of the Ancient Ones now boils
At war - War with the race
Father rise and the world be one

Repulsed by the light
No feeling for life
Drained of my being
I lie dead but still I'm sworn
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

long n,m,ar1[10000],ar2[10000],flag,used[10000];
long ans;

int main(){
//freopen("exchange.in","r",stdin);
//freopen("exchange.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
cin>>ar1[i];
for (int i=1;i<=m;i++)
cin>>ar2[i];
for (int i=1;i<=n;i++)
{
 flag=0;
 for (int j=1;j<=m;j++)
 if (ar2[j]>=ar1[i]&&used[j]==0&&flag==0)
 {
  flag=1;
  used[j]=1;
 }
 if (flag==0)++ans;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}