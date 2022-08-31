/*
Burning bridges, building walls
Erasing memories
I leave no trail for you to follow your eyes, a snake's eyes.
Charm and deceive
Blue-eyes, true eyes. Keep me awake

Kneel in shame. I despise all that you are
Bow your head and make amends
We all will cast you out once and for all
Bow your head and make amends

For the sake of shame. For the sake of dignity
show me yourself. Something honest and real!

Don't speak, don't move, don't breathe, submit
Step down. A slip of the tongue will be your demise
your eyes, a snake's eyes. Charm and deceive
Blue-eyes, true eyes. Keep me awake

Kneel in shame. I despise all that you are
Bow your head and make amends
We all will cast you out once and for all
Bow your head and make amends

Bow your head and make amends
Bow your head and make amends
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define MAG 10000

using namespace std;

string st;
long s[1<<20];
long long cnt,tl;
double ans;

bool vowel(char c)
{
 if (c=='I')
  return 1;
 if (c=='A')
  return 1;
  if (c=='E')
   return 1;
   if (c=='O')
    return 1;
 if (c=='U') 
  return 1;
  if (c=='Y')
   return 1;
  return 0;
}

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
for (int i=1;i<=st.size();i++)
 s[i]=s[i-1]+vowel(st[i-1]);

for (int i=1;i<=st.size();i++)
{
 cnt+=s[st.size()-i+1]-s[i-1];
 tl=i*1ll*(st.size()-i+1);
 ans+=cnt*1.0/i;
// cout<<cnt<<endl;
}

cout.precision(10);

cout<<fixed<<ans<<endl;

cin.get();cin.get();
return 0;}