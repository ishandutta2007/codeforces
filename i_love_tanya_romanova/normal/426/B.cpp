/*
Out in the vast
Where time is standing still
I have been looking for sanctuary
Left the world behind
To find some peace of mind
Now I am one with eternity

Millenniums are passing
In the blink of an eye
While I was searching my very soul
Longing for the answer
To the question of it all
Is it man or machine in control?

Far beyond on cosmic winds
I have been meeting my fate
Now I see
That the answer's been in me

I am the Savior
The chosen one
I am the ultimate dream
I am man and machine
I am the Savior
The only one
And from eternity
I will return
Time has come
Time has come

Used to be a traveler
On a never-ending ride
Touching the end of the Universe
Never to rest
Always on the quest
For deliverance from the eternal curse

Far beyond on cosmic winds
I saw the truth to it all
Now I see
What the future holds for me

I am the Savior
The chosen one
I am the ultimate dream
I am man and machine
I am the Savior
The only one
And from eternity
I will return
Time has come
Time has come
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
 
#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009
#define bsize 256

using namespace std;

long n,m,er,ar[200][200];

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  cin>>ar[i][j];
  
while (true)
{
 er=0;
 if (n%2)break;
 for (int i=1;i<=n/2;i++)
  for (int j=1;j<=m;j++)
   if (ar[i][j]!=ar[n-i+1][j])er=1;
   if (er)break;
   else n/=2;
}
cout<<n<<endl;

cin.get();cin.get();
return 0;}