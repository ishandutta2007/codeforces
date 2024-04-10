/*
Look at this photograph
Every time I do it makes me laugh
How did our eyes get so red?
And what the hell is on Joey's head?

And this is where I grew up
I think the present owner fixed it up
I never knew we'd ever went without
The second floor is hard for sneaking out

And this is where I went to school
Most of the time had better things to do
Criminal record says I've broke in twice
I must have done it half a dozen times

I wonder if it's too late
Should I go back and try to graduate?
Life's better now than it was back then
If I was them I wouldn't let me in

Oh oh oh
Oh God I

Every memory of looking out the back door
I have the photo album spread out on my bedroom floor
It's hard to say it, time to say it
Goodbye, goodbye

Every memory of walking out the front door
I found the photo of the friend that I was looking for
It's hard to say it, time to say it
Goodbye, goodbye
Goodbye

Remember the old arcade?
Blew every dollar that we ever made
The cops hated us hanging out
They said somebody went and burned it down

We used to listen to the radio
And sing along with every song we know
We said someday we'd find out how it feels
To sing to more than just the steering wheel

Kim's the first girl I kissed
I was so nervous that I nearly missed
She's had a couple of kids since then
I haven't seen her since God knows when

Oh oh oh
Oh God I

Every memory of looking out the back door
I have the photo album spread out on my bedroom floor
It's hard to say it, time to say it
Goodbye, goodbye

Every memory of walking out the front door
I found the photo of the friend that I was looking for
It's hard to say it, time to say it
Goodbye, goodbye

I miss that town
I miss their faces
You can't erase
You can't replace it

I miss it now
I can't believe it
So hard to stay
Too hard to leave it

If I could I relive those days
I know the one thing that would never change

Every memory of looking out the back door
I have the photo album spread out on my bedroom floor
It's hard to say it, time to say it
Goodbye, goodbye

Every memory of walking out the front door
I found the photo of the friend that I was looking for
It's hard to say it, time to say it
Goodbye, goodbye

Look at this photograph
Every time I do it makes me laugh
Every time I do it makes me
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

using namespace std;

long n,m;
long a,b;
long ar[1050][1050];
long ans;

bool check(long a,long b)
{
 if (a<=0||b<=0||a+2>n||b+2>n)return false;
 if (ar[a][b]==0)return false;
 if (ar[a+1][b]==0)return false;
 if (ar[a][b+1]==0)return false;
 if (ar[a+2][b]==0)return false;
 if (ar[a][b+2]==0)return false;
 if (ar[a+2][b+1]==0)return false;
 if (ar[a+1][b+2]==0)return false;
 if (ar[a+2][b+2]==0)return false;
 if (ar[a+1][b+1]==0)return false;
 return true;
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
ans=1e9;

for (long iter=1;iter<=m;iter++)
{
 cin>>a>>b;
 ar[a][b]=1;
 for (int i=a-2;i<=a+2;i++)
  for (int j=b-2;j<=b+2;j++)
   if (check(i,j))
     ans=min(ans,iter);
}
if (ans>m*2)ans=-1;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}