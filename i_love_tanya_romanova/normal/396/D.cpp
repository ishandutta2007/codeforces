/*
I don't feel the sun's comin' out today
It's staying in, it's gonna find another way, yeah, hey
As I sit here in this misery
I don't think I'll ever no long' seen the sun from here

And, oh, as I fade away
They'll all look at me and say and they'll say
"Hey, look at him", I'll never live that way
And that's okay, they're just afraid to change

Ah, when you feel life ain't worth living
You've got to stand up and take a look around
You look up way to the sky
Hey and when your deepest thoughts are broken
Keep on dreaming boy, 'cause when you stop dreamin' it's time to die

And as we all play parts of tomorrow, oh, no, no
Some ways we'll work, in other ways we'll play, yeah, yeah
But I know we can't all stay here forever, oh
So I want to write my words on the face of today
And then they'll paint it up

And, oh, as I fade away, yeah
They'll all look at me and say, they'll say
"Hey, look at him and where he is these days"
When life is hard, you have to change
When life is hard, you have to change
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

long t[2000000];

long sum(long r)
{
 long res=0;
 for (;r>=0;r=(r&(r+1))-1)
 res+=t[r];
 return res;
}

void add(long ps)
{
 for (;ps<1000500;ps=(ps|(ps+1)))
  t[ps]++;
}

long long pw(long long a,long long b)
{
 if (b==0)return 1;
 if (b%2)return a*pw(a,b-1)%bs;
 return pw(a*a%bs,b/2);
}

long long inv(long long x)
{
 return pw(x,bs-2);
}

long long fact[2000000],ar[2000000],full[2000000];
long long ttl,temp,les,ans;
long long n;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

fact[0]=1;
for (int i=1;i<=1000000;i++)
 fact[i]=fact[i-1]*i%bs;

cin>>n;

for (int i=1;i<=n;i++)
 cin>>ar[i];

for (int i=1;i<=n;i++)
{
 temp=i;
 temp*=(i-1);
 temp%=bs;
 temp*=fact[i];
 temp%=bs;
 temp*=inv(4);
 temp%=bs;
 full[i]=temp;
}

add(ar[n]);

ttl=1;

for (int i=n-1;i;--i)
{
 les=sum(ar[i]);
 add(ar[i]);
 // t[i]<ar[i]
 ans+=fact[n-i]*(les*(les-1)/2%bs);// invs with ar[i] on suf
 ans%=bs;
 ans+=full[n-i]*les;// in suf;
 ans%=bs;
 // t[i]==ar[i]
 ans+=ttl*les;
 ans%=bs;
 ttl+=fact[n-i]*les;
 ttl%=bs;
}
 
cout<<ans<<endl;

cin.get();cin.get();
return 0;}