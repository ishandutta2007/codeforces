/*
When I stand before you shining
In the early morning Sun
When I feel the engines roar
And I think of what we've done

Oh the bittersweet reflection
As we kiss the earth goodbye
As the waves and echoes of the
Towns become the ghosts of time

Over borders that divide the
Earthbound tribes
No creed and no religion
Just a hundred winged souls

We will ride this thunderbird
Silver shadows on the earth
A thousand leagues away
Our land of birth

To Albion's land
Coming home
When I see the runway lights
In the misty dawn
The night is fading fast

Coming home far away
As the vapor trails alight
Where I've been tonight
You know I will not stay

Curving on the edge of daylight
Till it slips into the void
Waited in the long night dreaming
Till the Sun is born again

Stretch the fingers of my hand
Cover countries with my span
Just a lonely satellite
A speck of dust in cosmic sand

Over borders that divide the
Earthbound tribes
Flown the dark Atlantic
Over mariners' stormy graves

We will ride this thunderbird
Silver shadows on the earth
A thousand leagues away
Our land of birth

To Albion's land
Coming home
When I see the runway lights
In the misty dawn
The night is fading fast

Coming home far away
As the vapor trails alight
Where I've been tonight
You know I will not stay

To Albion's land
Coming home
When I see the runway lights
In the misty dawn
The night is fading fast

Coming home far away
As the vapor trails alight
Where I've been tonight
You know I will not stay

Coming home far away
When I see the runway lights
In the misty dawn
The night is fading fast

Coming home far away
As the vapor trails alight
Where I've been tonight
You know I will not stay
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
#define right adsgasgadsg

using namespace std;

string z[2000];
string st;
char bl;
long tests,er,bad[2000];

char gett(char x)
{
 if (x>='A'&&x<='Z')
  return x-'A'+'a';
 return x;
}

long flag;
bool upper(char x)
{
 if (x>='A'&&x<='Z')return 1;
 return 0;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>tests;
for (int i=1;i<=tests;i++)
{
 cin>>z[i];
}
cin>>st;
cin>>bl;

for (int i=0;i<st.size();i++)
{
 for (int j=1;j<=tests;j++)
 {
  er=0;
  if (i+z[j].size()>st.size())continue;
  for (int p=0;p<z[j].size();p++)
  {
   if (gett(z[j][p])!=gett(st[i+p]))
    er=1;
  }
  if (er==0)
   for (int p=0;p<z[j].size();p++)
    bad[p+i]=1;
 }
}

for (int i=0;i<st.size();i++)
{
 if (bad[i]==0){cout<<st[i];continue;}
 flag=0;
 if (upper(st[i]))
 {
  st[i]=st[i]-'A'+'a';
  flag=1;
 }
 if (st[i]==bl&&bl=='a')st[i]='b';
 else if (st[i]==bl&&bl!='a')st[i]='a';
 else st[i]=bl;
 if (flag){st[i]=st[i]-'a'+'A';}
 cout<<st[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}