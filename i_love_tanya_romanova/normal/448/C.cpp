/*
One by one we take control
New consciousness, one heart, one soul
Oppression ends, the time has come
So don't look back, it can be done

Something is still missing
Something keeps 'em blind
Like a precious sacrilege
They can never find
(They can never find)

So they walk together
Into a silent war
Though it seems to take forever
This generation is finally heading for

A better tomorrow
A better tomorrow

Tell me can't you feel it?
Tell me can't you see?
Tell me can't you hear it?
I know it ain't just me

Let us walk together
What are we waiting for?
(What are we waiting for?)
It is now or never
This generation is finally heading for

A better tomorrow
A better tomorrow

Day by day we're praying for
It to come across the shores
It brings new hope, it brings new light
Nameless spirits now they shine

One by one become aware
New consciousness will be there
And all the blind, now they will see
Embrace their minds to plant the seeds for

A better tomorrow
A better tomorrow
A better tomorrow
A better tomorrow
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-14
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
//#define N 120000

using namespace std;

long n,ar[60000];

long solve(long l,long r,long h)
{
 long bst=r-l+1;
 long lwr=2e9;
 for (int i=l;i<=r;i++)
  if (ar[i]<lwr)lwr=ar[i];
 long pb=l-1;
 long temp=0;
 for (int i=l;i<=r;i++)
 {
     if (ar[i]==lwr)
     {
      if(pb<i-1)temp+=solve(pb+1,i-1,lwr);
      pb=i;
     }
 }
 if (pb!=r)temp+=solve(pb+1,r,lwr);
 return min(bst,temp+lwr-h);
}

int main(){
//freopen("pattern.in","r",stdin);
//freopen("pattern.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 cin>>ar[i];
cout<<solve(1,n,0);

cin.get();cin.get();
return 0;}