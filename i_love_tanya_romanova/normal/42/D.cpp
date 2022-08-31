/*
Under this sun no shadows will fall
Piercing our eyes as we charge
An armoured battalion on course to the east
Closing the end of it's march

This time we're here to finish a job
Started a decade ago
Driving the animals out of their holes
To bury them 6 feet below
Armoured tanks of mass destruction
Killers in the east
Rats who dares to stand before us
Feel our guns go live

[Chorus:]
Death in the shape of a panzer battalion
Insect of terror don't run face your fate like a
Man cannot outrun our panzer battalion

Thousands of tons of armour and guns
Making it's way through the sand
Our panzer battalion is back for revenge
Artillery sweeping the land

First strike is ours no mercy is shown
There's rivers of blood in our track
Breaking their waves of defence with our tanks
Infantry watching our back

Blow their SAM sites clear for air strike
Ready for the storm
Minefields swept there's no surrender
Feel our napalm burn

[Chorus x2]

Under this sun no shadows will fall
Piercing our eyes as we charge
An armoured battalion on course to the east
Has reached the end of it's march

Armoured tanks of mass destruction
Killers in the east
Rats who dares to stand before us
Feel our guns go live

Panzer battalion
Insect of terror don't run face your fate like a man
Panzer battalion
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

long er;
vector<long> v;
long n;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

v.push_back(1);
v.push_back(2);
v.push_back(3);
for (int i=4;i<=1000;i++)
{
 er=0;
 for (int a=0;a<v.size();a++)
  for (int b=0;b<v.size();b++)
   for (int c=0;c<v.size();c++)
    if (a!=b&&a!=c&&b!=c)
     if (v[a]+v[b]-v[c]==i)er=1;
   if (er==0)v.push_back(i); 
}

cin>>n;
for (int i=0;i<n;i++)
{
    for (int j=0;j<n;j++)
    {
     if (j)cout<<" ";
     if (i==j)cout<<0;else cout<<v[i]+v[j];
    }
    cout<<endl;
}

cin.get();cin.get();
return 0;}