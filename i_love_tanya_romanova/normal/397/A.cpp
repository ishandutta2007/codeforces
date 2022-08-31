/*
As a man youll understand liberty
But stay aware when you hear the sirens ring
Know your foe, for where he walks you will never perceive the colour of freedom

You can walk with your eyes wide open through coal
But the harder you try its blowing so slow

Build a wall between your soul and reality
Only then will your head be truly free
Paint a face over your veins so nobody can see the horror youre feeling

Are you praying for an end to this?

Wed all love to fly away
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
 
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
 
//#define free asdfasdfsdadsg
#define bsize 512
 
using namespace std;

long n,l[2000],r[2000],calc[2000],ans;

int main(){
//freopen("rmq.in","r",stdin);
//freopen("rmq.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>l[i]>>r[i];
 for (int j=l[i];j<r[i];j++)
 calc[j]++;
}
for (int j=l[1];j<r[1];j++)
if (calc[j]==1)++ans;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}