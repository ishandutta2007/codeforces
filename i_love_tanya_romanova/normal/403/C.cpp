/*
Down below the city
Where the light is cold and dim
Creatures without name
Are paying for the sin
Not dead nor alive
In a dark and toxic reign
Infected by the virus
We failed to reach the aim

Damned to walk the night
Access to the world above denied
Lost without a cure
But as long as we are standing
I'll endure

On that very day
God has turned away
Even though I pray
Hear my words

Heal me
Heal my scars
I'm longing for peace
Heal me
Heal my pain
Let me walk the daylight again

We challenged the creation
In the hope to reveal
The secrets of the maker
When the ancient broke the seal
Immortal we are suffering
For opening the locks
To see what is concealed
Inside Pandora's box

Locked up in the night
With access to the light above denied
Can't you hear my cry
When you sleep or die
Longing for salvation
Set us free

Heal me
Heal my scars
I'm longing for peace
Heal me
Heal my pain
And let me walk the daylight again

On that very day
God has turned away
Even though I pray
Hear my words

Heal me
Heal my scars
I'm longing for peace
Heal me
Heal my pain
And let me walk the daylight again
Heal me
Heal my pain
And let me walk the daylight again
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
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,q,ar[2100][2100];
long flag;

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
 {
  cin>>q;
  if (q)ar[i][j/30]|=(1<<(j%30));
 }
 
 
for (int k=1;k<=n;k++)
 for (int i=1;i<=n;i++)
  if (ar[i][k/30]&(1<<(k%30)))
   for (int j=0;j<=n/30+1;j++)
    ar[i][j]|=ar[k][j];
 
 flag=0;
 for (int i=1;i<=n;i++)
  for (int j=1;j<=n;j++)
   if ((ar[i][j/30]&(1<<(j%30)))==0)flag=1;
 
 if (flag)cout<<"NO"<<endl;
 else cout<<"YES"<<endl;
 
cin.get();cin.get();
return 0;}