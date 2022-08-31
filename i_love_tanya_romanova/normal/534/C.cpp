/*
Tonight I stood upon the crest and witnessed our decay
The land that was our father's, lay in ruins at our feet
And I dare not look out or into unseeing eyes
Of mankind's blind ambitions and desires

The wisdom of humanity is wasted on you all
You pushed us into corners of a tortured paradise
Your selfish pillaging is a treason to this earth
And in the end, you are betrayed by your own deeds

Now, every time I turn around it's just too late
To give back our mother earth a little dignity
I wish you'd set her free and give her love back to me
'Cause our spirits are not weak like you

We're on our own
Pushed from our home
Our voices joining

Sacreligious and deceitful are your truces
Tattered paper poison letters bloody skies
I do my best to keep it all to myself
But now I fight for my name
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

using namespace std;

long long n,A,d[1<<20],S,upr,lwr;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>A;
for (int i=1;i<=n;i++)
{
 cin>>d[i];
 S+=d[i];   
}

for (int i=1;i<=n;i++)
{
 upr=A-(n-1);   
 lwr=d[i]-(S-A);
 if (lwr<1)lwr=1;
 if (upr>d[i])upr=d[i];
 if (i>1)cout<<" ";
 cout<<lwr-1+d[i]-upr;
}
cout<<endl;

cin.get();cin.get();
return 0;}