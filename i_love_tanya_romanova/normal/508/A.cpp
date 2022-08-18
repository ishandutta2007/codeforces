/*
End
Sometimes a start for others
End
I don't know the word 'Beginning'

Sometimes fear is power
Like when I lost control
This time, it has to come to an end

I'd like to try to live my life again
I'd like to see where I was going wrong
I'd like to try to live my life again
I'd like to see where I was going wrong

End
Sometimes a start for others
End
I don't know the word 'Beginning'

Sometimes fear is power
Like when I lost control
This time, it has to come to an end

I'd like to try to live my life again
I'd like to see where I was going wrong
I'd like to try to live my life again
I'd like to see where I was going wrong

I'd like to try to live my life again
I'd like to see where I was going wrong
I'd like to try to live my life again
I'd like to see where I was going wrong

I'd like to try to live my life again
I'd like to see where I was going wrong
I'd like to try to live my life again
I'd like to see where I was going wrong
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
#define MAG 10000

using namespace std;

long n,m,k,a,b,ar[1<<10][1<<10];

bool nice(long a,long b)
{
 if (a>=1&&a<=n&&b>=1&&b<=m&&ar[a][b]==1)
  return 1;
  return 0;
}

bool check(long a,long b)
{
 if (nice(a,b)&&nice(a,b+1)&&nice(a+1,b)&&nice(a+1,b+1))
  return true;
 return false;
}

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;

for (int i=1;i<=k;i++)
{
 cin>>a>>b;
 ar[a][b]=1;
 if (check(a-1,b-1)||check(a,b-1)||check(a-1,b)||check(a,b))
  {cout<<i<<endl;
  return 0;}
}
cout<<0<<endl;

cin.get();cin.get();
return 0;}