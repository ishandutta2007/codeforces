/*
There's a man who sees all there is to see
What the future holds for all
As the days grow dark, was his sole and final warning
Beware of the one with invisible friends
They will steal into your mind
And all too soon, the signs begin to show

Rise up to the shining 
Live long live now 
Rise up to the shining 
Don't be blind by fools again 

As the page is turned and the story's told
From the visions he had seen
The house on the hill with the haunting eyes that call
No one left when madness came out
To play its game
If you stay too long, you'll finally go insane

Rise up to the shining 
Live long live now 
Rise up to the shining 
Don't be blind by fools again

Bells will take their toll
On your way
There's no way we're born to shine
Before our time ,all your life, you're
On your own
Lonely road
Lost in a time
Let the light lead your way
To the golden throne
It's the only way

Rise up to the shining
Live long live now
Rise up to the shining
Don't be blind by fools again
Rise up to the shining
Love long live now

Oh rise up, to the shining
Wise up they're gonna steal your mind
Rise up, the house is gonna haunt you
No one laughed, no one cried
You stayed too long
You're finally gonna stay
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,ar[10000],dp[5500][5500],bst,calc,dif;

int main(){
//freopen("gift.in","r",stdin);
//freopen("gift.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>ar[i];

long tinv=0;

for (int i=1;i<=n;i++)
 for (int j=i+1;j<=n;j++)
 if (ar[j]<ar[i])++tinv;
for (int i=0;i<=n;i++)
for (int j=1;j<=n;j++)
{
    dp[i][j]=dp[i][j-1];
    if (ar[j]<i)dp[i][j]++;
}

bst=100000;
calc=0;
long a,b;

/*while (cin>>a>>b)
cout<<dp[a][b]<<endl;
*/

for (int i=1;i<=n;i++)
 for (int j=i+1;j<=n;j++)
  if (ar[i]>ar[j])
  {
   dif=dp[ar[i]][i]+dp[ar[j]][j]-dp[ar[j]][i]-dp[ar[i]][j];
   
   if (dif<bst){bst=dif;calc=1;}
   else if (dif==bst)++calc; 
   //cout<<i<<" "<<j<<" "<<dif<<endl; 
  }

//cout<<tinv<<" "<<bst<<endl;
cout<<tinv+2*bst+1<<" "<<calc<<endl;

cin.get();cin.get();
return 0;}