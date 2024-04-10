/*
Miles away there's hopeless
Smiles brighter than mine
And I need for you to come and go
Without the truth falling out

Old incisions refusing to stay
Like sun through the trees on a cloudy day

You brighten my life like a polystyrene hat
But it melts in the sun like a life without love
And I've waited for you so I'll keep holding on
Without you, without you

Telephone, socially scared and impaired
If the trees will bloom, the wind can blow
Without the fruit falling out

Old incisions refusing to stay
Like sun through the trees on a cloudy day

You brighten my life like a polystyrene hat
But it melts in the sun like a life without love
And I've waited for you so I'll keep holding on
Without you, without you

Feels like the wind blows
Holding you with us
She takes no other
False light and ashes
Blooming like winter

You brighten my life like a polystyrene hat
But it melts in the sun like a life without love
And I've waited for you so I'll keep holding on
Without you, without you, without you
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