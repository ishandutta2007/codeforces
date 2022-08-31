/*
Well we got no choice
All the girls and boys
Makin all that noise
'Cause they found new toys
Well we can't salute ya
Can't find a flag
If that don't suit ya
That's a drag

School's out for summer
School's out forever
School's been blown to pieces

No more pencils
No more books
No more teacher's dirty looks

Well we got no class
And we got no principles
And we got no innocence
We can't even think of a word that rhymes

School's out for summer
School's out forever
School's been blown to pieces

No more pencils
No more books
No more teacher's dirty looks

Out for summer
Out till fall
We might not go back at all

School's out forever
School's out for summer
School's out with fever
School's out completely
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
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long n,ans,ar[200000];
set<long> ex;

int main(){
//freopen("processing.in","r",stdin);
//freopen("processing.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
ans=-1;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];ex.insert(ar[i]);
}

for (int i=1;i*i<=ar[1];i++)
{
    if (ar[1]%i==0)
    {
     if (ex.find(i)!=ex.end())
     {
      long fl=0;
      for (int j=1;j<=n;j++)
      if (ar[j]%i)fl=1;
      if (fl==0)ans=i;
     }
     
     if (ex.find(ar[1]/i)!=ex.end())
     {
      long fl=0;
      for (int j=1;j<=n;j++)
      if (ar[j]%(ar[1]/i))fl=1;
      if (fl==0)ans=ar[1]/i;
     }
    }
    
}

cout<<ans<<endl;
cin.get();cin.get();
return 0;}