/*
My love will rise!

This was a story that was foretold by a man, a prophecy.
He gave his son to us, gave his son.
He died for our sins to be forgiven.

This trust I adore,
This trust I need some more (All forget this day)
Today I realize I take everything for granted,
I take everything for granted.
Today I realize I take everything for gra... I adore
This trust I need some more (Punished by destiny)
Today I realize I take everything for granted,
I take everything for granted.
Today I realize I take everything for granted,
I take everything for granted.

You're the reason I feel in love with yesterday,
You're the reason I dream tomorrow,
You're the reason I live today.
Youre the reason;
I'll always think of you!
Ill always
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long n,a[1<<10],b[1<<10],found,used1[1<<10],used2[1<<10],ans;
long m;

int main(){
//freopen("billing.in","r",stdin);
//freopen("billing.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 cin>>a[i];

cin>>m;
for (int i=1;i<=m;i++)
 cin>>b[i];

sort(a+1,a+n+1);
sort(b+1,b+m+1);

while (true)
{
 found=0;
 for (int i=1;i<=n&&found==0;i++)
  if (used1[i]==0)
  {
   for (int j=1;j<=m&&found==0;j++)
    if (used2[j]==0&&abs(a[i]-b[j])<2)
    {
     used1[i]=used2[j]=1;
     found=1;
     ++ans;
    }
  }
  if (found==0)break;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}