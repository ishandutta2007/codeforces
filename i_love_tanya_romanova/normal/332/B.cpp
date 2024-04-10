/*  
Wake up!
Missiles are crossing the sky
You never thought this day would really come
Better seek shelter in hell
Than try escape from insanity

No Future
Annihilation is a profit
Wretched
Apocalypse is not a prophecy

Prepare for Toxic Death!
Prepare for Toxic Death!

Gasp!
The Eyes are burning in pain
When the air becomes your enemy?
Acid runs in your veins
Infected by a lethal plague

Slow Death
While militarise are laughing
Human Waste
Bullets can't feed the survivals (of the war)

A force no one control
A way to total end - Chemical
A power to splinter the world
A desert whose blood's sand - Chemical Assault!
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long long n,k,ar[400000],s[400000],bst[400000],bp[400000];
long long a1,a2,tans,span,ans;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
cin>>ar[i];

for (int i=1;i<=n;i++)
s[i]=s[i-1]+ar[i];

for (int i=n;i>=1;i--)
{
 if (i+k-1>n)
 {
  bst[i]=-100000000000000000ll;
 }   
 else
 {
  span=s[i+k-1]-s[i-1];
  bst[i]=bst[i+1];
  bp[i]=bp[i+1];
  if (span>=bst[i])
  {
   bst[i]=span;
   bp[i]=i;
  }
 }
}

ans=0;

for (int i=1;i<=n;i++)
{
 if (i+k<=n)
 {
  tans=s[i+k-1]-s[i-1];
  tans+=bst[i+k];
  if (tans>ans){ans=tans;a1=i;a2=bp[i+k];}
 }   
}

cout<<a1<<" "<<a2<<endl;
//cout<<ans<<endl;

cin.get();cin.get();
return 0;}