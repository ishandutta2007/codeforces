/*
Only ashes and bones remain
My hair is wet, my eyes are sore
The past has been fed to the flames
I cannot breathe anymore

I try to stand on my feet, but I fall
I try to walk, but I crawl
Life - as we knew it, is over
And you are gone
Forever gone...

I will not bend to a cross
I will not kneel at your feet

Greed and anger
Made us younger
Couldn't save us when the tower fell
All my strength and all my hunger
All is lost
And none will live to tell

I rest in the ruins of days gone by
Of young affection and velvet sky
A slave to greed...
I do not feel regret anymore
I sense the presence of birds
Encircling me...
And I am gone

Til jord skal vi bli

Dark is the night
Dead is the moon
I will not kneel

I'd rather die
Facing my doom
I will not kneel
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

long pr[1<<20],n;
long q;

int main(){
//freopen("army.in","r",stdin);
//freopen("army.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

pr[1]=1;
for (int i=2;i<=1000;i++)
 if (pr[i]==0)for (int j=i*i;j<=1000000;j+=i)
  pr[j]=1;

cin>>n;
q=2;
while (pr[q]+pr[n-q]<2)++q;
cout<<q<<" "<<n-q<<endl;

cin.get();cin.get();
return 0;}