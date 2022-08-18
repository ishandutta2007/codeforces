/*
Bloodred sun rises
Setting the moon afire
Sullen sky bleeds tears
Raining into a sea of fear

Death beckons all tonight

All world burning
As we look up to the sky
Wish upon a star fall
Granted we will die

Another star lights the sky tonight

I found my life within you
I face my end standing by you
Come hell, unmake years gone tonight
These words I say are my last goodbye

Flame of unlife
Sear the flesh that we are
Charred remains
Ageless testament of our existence

Sunburst too bright to behold
Eyes branded with a last memento
We touched the face of god
With our hands of blood

I found my life within you
I face my end standing by you
Come hell, unmake years gone tonight
These words I say are my last goodbye

Grim is the wind that reveals what once was
Lying deep within forgotten sands
Embraced by universal end of life
Gods by our own right we scorched the land

Death beckons all tonight

I found my life within you
I face my end standing by you
Come hell, unmake years gone tonight
These words I say are my last goodbye
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
#define rmost agasdgasdg

using namespace std;

long n,s,ans,a,b;

long gett(long x)
{
 if (x==0)return 0;
 return 100-x;
 
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>s;
ans=-1;
for (int i=1;i<=n;i++)
{
 cin>>a>>b;
 if (a<s||(a==s&&b==0))ans=max(ans,gett(b));
 else continue;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}