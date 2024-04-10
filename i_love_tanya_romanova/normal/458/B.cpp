/*
Life in the world untold, question the unknown
This prison captures me, my cell is all I know
I thought I knew it all, stubborn in my ways
My sentence has begun, my future's what I waste

Next chapter of my life filled with violent scenes
I stay awake at night hiding from my dreams
The voices haunting me, driving me insane
Can't seem to get away, they're calling out my name

I feel I am slipping
Are they out to get me?
My life is upside down
More than meets the eye

For now I am in control, choosing my own fate
And now I sleep at night because I'm not afraid
My demons haunting me, I chased them all away
I've conquered all my fears, my destiny awaits

I'm no longer slipping, I'm not slipping away
No one is out to get me, no one will get in my way
Well, no longer upside down, I've turned my life around
More than meets the eye

More than, more than
More than, more than meets the eye
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

long long n,m,a[200000],b[200000],s1,s2,ans;
long long q;

long long safe(long long a,long long b)
{
 if (a==0||b==0)return 0;
 long long ii=1000000000ll;
 ii*=ii;
 if (ii/a<=b)return ii;
 return a*b;
}

int main(){
//freopen("refrain.in","r",stdin);
//freopen("refrain.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

for (int i=1;i<=n;i++)
 cin>>a[i];
for (int i=1;i<=m;i++)
 cin>>b[i];

sort(a+1,a+n+1);
sort(b+1,b+m+1);

// b to a

s1=s2=0;
for (int i=1;i<=n;i++)
 s1+=a[i];
for (int i=1;i<=m;i++)
 s2+=b[i];

ans=1e18;

for (int i=n;i;--i)
{
 s1-=a[i];
 q=safe(n-i+1,s2);
 ans=min(ans,s1+q);
}

// a to b

s1=s2=0;
for (int i=1;i<=n;i++)
 s1+=a[i];
for (int i=1;i<=m;i++)
 s2+=b[i];

for (int i=m;i;--i)
{
 s2-=b[i];
 q=safe(m-i+1,s1);
 ans=min(ans,s2+q);
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}