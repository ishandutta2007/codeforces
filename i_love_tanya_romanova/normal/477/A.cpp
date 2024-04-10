/*
I admit it
What's to say, what
I'll relive it
Without pain, mmmm

Backstreet lover on the side of the road
I got a bomb in my temple that is gonna explode
I got sixteen gauge buried under my clothes, I play

Once upon a time I could control myself
Once upon a time I could lose myself, yeah

Oh, try and mimic
What's insane
I am in it
Where do I stand?
Stand, stand

Indian summer and I hate the heat
I got a backstreet lover on the passenger seat
I got my hand in my pocket, so determined, discreet, I pray
Once upon a time I could control myself
Once upon a time I could lose myself, yeah yeah yeah

Once upon a time I could control myself
Once upon a time I could lose myself, yeah yeah yeah
Once, upon a time I could love myself
Once upon a time I could love you

Once, once
Once, once
Once, once
Yeah
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
#define free adsgasdg

using namespace std;

long long fst,lst,val,ans,a,b;
long long mag;

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

int main(){
//freopen("dial.in","r",stdin);
//freopen("dial.out","w",stdout);
//freopen("C:/rai06.in","r",stdin);
//freopen("C:/rai06.out","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>a>>b;

mag=inv(2);

for (int rem=1;rem<b;rem++)
{
 fst=rem*b+rem;
 fst%=bs;
 lst=((rem*a)%bs*b)%bs+rem;
 lst%=bs;
 val=fst+lst;
 val*=a;
 val%=bs;
 val*=mag;
 val%=bs;
 ans+=val;
 ans%=bs;
}

cout<<ans<<endl;


cin.get();cin.get();
return 0;}