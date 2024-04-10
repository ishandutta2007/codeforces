/*
Feelin' fine, the fire won't burn out
Taste the sign, the trees won't come out
Seein' traffic drivin' by
Maybe you, you won't see me again
'Cause I'm needed, needed more and more every day
Someone take my mind away
Tell me that it's time to go
You wanna help me as I'm fallin' down

I don't need you
Lies they won't surface
Your mind it wanders on over again

Someone take on my mind
I'm losin' you in time
Maybe that man, he's standin' by me
My head won't take it all alone
Someone they wanna tell you
Maybe you would suffer
Tell me once again, I'm under cover
Someone wanna feel like, someone want to feel like

I don't need you
Lies they won't surface
Your mind it wanders, ohh
Oh, yeah

Maybe, yeah I don't need you
Lies they won't surface
My mind it wanders oh over again
Someone to tell you

Should I close my eyes again once again
Maybe someone will come and rescue me
Should I beg your forgiveness
I've fallen on my own
Someone take a picture
Put your camera away
Someone take today, traffic passes by, never see
You never see it all

I don't need you
Your lies they won't surface
Your mind it wanders oh over, again

Yeah, I don't need you
Your lies they won't surface
My mind it wanders oh over again
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
#define free adsgasdg

using namespace std;

long n,s[1<<20],ar[1<<20],tests,l,r,need;

int main(){
//freopen("dial.in","r",stdin);
//freopen("dial.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{ cin>>ar[i];
 s[i]=s[i-1]+ar[i];
}
cin>>tests;
for (;tests;--tests)
{
 cin>>need;
 l=1;
 r=n;
 while (l<r)
 {
  long m=l+r;
  m/=2;
  if (s[m]<need)l=m+1;
  else r=m;
 }
 cout<<l<<endl;
 
}
cin.get();cin.get();
return 0;}