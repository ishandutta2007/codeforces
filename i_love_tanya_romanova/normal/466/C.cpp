/*
You... You fall asleep, laying down she...
Anxious dream for a burden relief

Seal the world with a word that's not yours
Heal the future with the past undone

What is left for me?
Just a burden from your false words
What is left for me?
Just a burden from your false words

I... I'll set you free, drink bumblebee
Honey from me for a burden relief

Seal the world with a word that's not yours
Heal the future with the past undone

Burden

What is left for me?
Just a burden from your false words
What is left for me?
Just a burden from your false words

What is left for me?
Just a burden from your false words
What is left for me?
Just a burden from your false words
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
#define bsize 512

using namespace std;

long long n,ar[1<<20];
long long s[1<<20],need,calc,ans;
long long qs;

int main(){
//freopen("optimize.in","r",stdin);
//freopen("optimize.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{ 
 cin>>ar[i];
 s[i]=s[i-1]+ar[i];
}

if (s[n]%3){cout<<0<<endl;return 0;}

need=s[n]/3;
for (int i=1;i<=n;i++)
{
 qs+=ar[i];
 if (qs==2*need&&i<n)
 {
  ans+=calc;
 }
 if (qs==need)++calc; 
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}