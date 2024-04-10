/*
Riding in darkness through the hell of the night
Give all your torment to the heaven's might
In the name of satan spread all your fear
You feel his anger you know he's near
Casting a spell
Lord of all hells
Ripping the angels
God has fell
Tormentor
Baphomet's calling death is now real
Helldogs and demons waiting to kill
Pentagrams shining Luzifer smiles
Fucking the virgin rip out her eyes
Drinking the blood
Fear no god
Now you are dead
Your flesh is dot rot
Tormentor
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-14
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
//#define N 120000

using namespace std;

long long n,m,k,l,r,mid;

long long solve(long long x)
{
 long long r=0;
 for (int i=1;i<=n;i++)
 {
  long long temp=x-1;
  temp/=i;
  if (temp>m)temp=m;
  r+=temp;
 }
 return r;
}

int main(){
//freopen("pattern.in","r",stdin);
//freopen("pattern.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
l=1;
r=n*m;
while (l<r)
{
 mid=l+r+1;
 mid/=2;
 if (solve(mid)<k)l=mid;
 else r=mid-1;
}

cout<<l<<endl;

cin.get();cin.get();
return 0;}