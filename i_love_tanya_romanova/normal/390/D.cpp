/*
Oh spiritus, oh sanctus
Adoramus domine
Te deum laudamus
In memoriam, gloriam

Warriors, immortal knights, we walk our way alone
Eternally, we're born to write the sign of victory
Warriors, immortal knights, far away from home
Eternally, we're born to fight, forever riding free

And the day has come, time to die
Somewhere far beyond
On the stairway to the sky, on the rainbow soaring high
We are born from the sun

In our hands we hold the future as we live so we will die
Carry on to save mankind
Back to back we stand as one until the last crusade is done
We're leaving from the night

Call for vengeance, raise your steel
We are the knights on our glory ride
Law defenders, raise your swords
Freedom for us all

A hail to the gods of creation
A hail to the king of the world
A hail to the metal invasion
A heavenly kingdom on earth

A hail to the gods of creation
A hail to the king of the world
A hail to the metal invasion
A heavenly kingdom on earth

Godless odyssey, endless agony
We're heading for eternal life

Call for vengeance, raise your steel
We are the knights on our glory ride
Law defenders, raise your swords
Freedom for us all

A hail to the gods of creation
A hail to the king of the world
A hail to the metal invasion
A heavenly kingdom on earth

A hail to the gods of creation
A hail to the king of the world
A hail to the metal invasion
A heavenly kingdom on earth

Call for vengeance, raise your steel
We are the knights on our glory ride
Law defenders, raise your swords
Freedom for us all

A hail to the gods of creation
A hail to the king of the world
A hail to the metal invasion
A heavenly kingdom on earth

A hail to the gods of creation
A hail to the king of the world
A hail to the metal invasion
A heavenly kingdom on earth
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
 
#define  INF 100000000
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009
 
//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 2048
 
using namespace std;

long n,m,k,res;
vector<pair<long, pair<long, long> > > v;

void solve(pair<long, long> p)
{
 for (int i=1;i<=p.first;i++)
 {
  cout<<"("<<i<<","<<1<<") ";
 }
 for (int i=2;i<=p.second;i++)
 cout<<"("<<p.first<<","<<i<<") ";
 cout<<endl;
}

int main(){
//freopen("rmq.in","r",stdin);
//freopen("rmq.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>k;
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
  v.push_back(make_pair(i+j-1,make_pair(i,j)));
 }
 sort(v.begin(),v.end());

res=0;
for (int i=0;i<k;i++)
res+=v[i].first;
cout<<res<<endl;
for (int i=k-1;i+1;--i)
solve(v[i].second);

cin.get();cin.get();
return 0;}