/*
You've made your choice just now
For a better solution - peaceful revolution
Time has never been on your side
Been taken out for a ride
You've just escaped from c. camp
Unwillingly imprisoned
You need no guiding light
For the definite conversion
We show you how to begin
Tell you "Brother you'll win"
Don't reinstate those again
Who caused you sorrow and pain
SED just stands for
Socialists' eternal death
Socialists' eternal death
Watch every step you make
Control evolution - no more disillusion
See! How far you got with you faith
Achieved more than could
Just like everyone should
I trust in you
And you wish to survive
And the struggle and strife
That you will face every day
In China they killed your friends
Slaughtering with no sense
The way they treat their folks
Is showing us that you're rogues
SED just stands for
Socialist' eternal death
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

long n,ar[1<<20],has[1<<21];
vector<long> s;
vector<long>::iterator it;
long v,ans;

int main(){
//freopen("logins.in","r",stdin);
//freopen("logins.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
 has[ar[i]]=1;
 s.push_back(ar[i]);
}
sort(s.begin(),s.end());

for (int i=1;i<=1000000;i++)
if (has[i])
{
 for (int j=i*2;j<=1000000+i;j+=i)
 {
     it=lower_bound(s.begin(),s.end(),j);
     if (it!=s.begin())
     {
      --it;
      v=(*it);
      ans=max(ans,v%i);
     }
 }
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}