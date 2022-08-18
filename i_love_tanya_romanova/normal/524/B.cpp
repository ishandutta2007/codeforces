/*
You took their lives
And you took their souls
To be the king of their land
You brought them misery
Anger and pain
To keep the crown in your hands

But soon they will tear you
Down to the crowd
The prophecy's coming true
It's death and revenge what they shout

The time has come
To face your desteny
Your life is done
And you're burning for eternity

You promised them heaven
And brought them to hell
Behind your blood shedded walls
Why don't you see
You're under a spell
And madness has taken its toll

And they won't forgive you
Soon you will die
And noone will help you thru
The price that you pay for your lies

The time has come
To face your desteny
Your life is done
And you're burning for eternity
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
#define MAGIC 47
#define count adsgasdgasdg

using namespace std;

long long n,h[1<<15],w[1<<15],span,bst,ans;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>h[i]>>w[i];
}
ans=1e17;

for (int ah=1;ah<=1000;ah++)
{
 span=0;
 for (int i=1;i<=n;i++)
 {
  bst=1e10;
  if (h[i]<=ah)bst=min(bst,w[i]);
  if (w[i]<=ah)bst=min(bst,h[i]);
  span+=bst;
 }
 ans=min(ans,span*ah);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}