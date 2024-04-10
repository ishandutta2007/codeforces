/*
For too long now
There were secrets in my mind
For too long now
There were things I should have said
In the darkness
I was stumbling for the door
To find a reason
To find the time, the place, the hour

Waiting for the winter sun
And the cold light of day
The misty ghost of childhood fears
The pressure is building
And I can't stay away

I throw myself into the sea
Release the wave
Let it wash over me
To face the fear
I once believed
The tears of the dragon
For you and for me

Where I was
I had wings that couldn't fly
Where I was
I had tears I couldn't cry
My emotions
Frozen in an icy lake
I couldn't feel them
Until the ice began to break

I have no power over this
You know I'm afraid
The walls I built are crumbling
The water is moving
I'm slipping away

I throw myself into the sea
Release the wave
Let it wash over me
To face the fear
I once believed
The tears of the dragon
For you and for me

Slowly I awake
Slowly I rise
The walls I built are crumbling
The water is moving
I'm slipping away

I throw myself into the sea
Release the wave
Let it wash over me
To face the fear
I once believed
The tears of the dragon
For you and for me
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
#define lr asgasgash

#define  INF 100000000
#define eps 0.001
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long long mx[1100000],ans[10][1100000],dig[10][1100000],temp,par,aa,lst,fst,n;

long gmx(long long x)
{long long r=0;
while (x){r=max(r,x%10);x/=10;} return r;}

int main(){
//freopen("lifts.in","r",stdin);
//freopen("lifts.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (long long i=0;i<=1000000;i++)
{
    long long q=i;
    mx[i]=0;
    while (q){mx[i]=max(mx[i],q%10);q/=10;}
}

for (long long pref=0;pref<=9;pref++)
{
 for (long long suf=0;suf<=1000000;suf++)
 {
  temp=max(pref,mx[suf]);
  par=suf-temp;
  if (par<0){ans[pref][suf]=1;dig[pref][suf]=par;}
  else {ans[pref][suf]=ans[pref][par]+1;dig[pref][suf]=dig[pref][par];}
 }
}

cin>>n;
lst=n%1000000;
fst=n/1000000;
while (fst>=0)
{
 aa+=ans[mx[fst]][lst];
// cout<<mx[fst]<<" $ "<<lst<<endl;
 lst=1000000+dig[mx[fst]][lst];
 fst--;
}
cout<<aa-1<<endl;
/*
long long tans=0;
while (n>0){tans++;n=n-gmx(n);}
cout<<tans<<endl;
*/
cin.get();cin.get();
return 0;}