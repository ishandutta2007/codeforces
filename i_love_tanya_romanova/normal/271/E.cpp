/*
Waitin', watchin' the clock, it's four o'clock, it's got to stop
Tell him, take no more, she practices her speech
As he opens the door, she rolls over...
Pretends to sleep as he looks her over

She lies and says she's in love with him, can't find a better man...
She dreams in color, she dreams in red, can't find a better man...
Can't find a better man
Can't find a better man
Ohh...

Talkin' to herself, there's no one else who needs to know...
She tells herself, oh...
Memories back when she was bold and strong
And waiting for the world to come along...
Swears she knew it, now she swears he's gone

She lies and says she's in love with him, can't find a better man...
She dreams in color, she dreams in red, can't find a better man...
She lies and says she still loves him, can't find a better man...
She dreams in color, she dreams in red, can't find a better man...
Can't find a better man
Can't find a better man
Yeah...

She loved him, yeah... she don't want to leave this way
She feeds him, yeah... that's why she'll be back again

Can't find a better man
Can't find a better man
Can't find a better man
Can't find a better... man...
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long long n,m,q,g;
set<long long> s;
long long ans;

long long gcd(long long a,long long b)
{while (a&&b)a>b?a%=b:b%=a;
return a+b;}

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
g=0;
for (int i=1;i<=n;i++)
{
    cin>>q;
    --q;
    g=gcd(q,g);
}
//cout<<g<<endl;
for (int p=1;p*p<=g;p++)
{
 if (g%p==0){s.insert(p);if (g/p!=p)s.insert(g/p);}
}

set<long long>::iterator it;

for (it=s.begin();it!=s.end();++it)
{
 long long q=(*it);
 if (q%2==0)continue;
 for (int pw=0;pw<=30;pw++)
 if ((1ll<<pw)*q<=m)ans+=m-(1ll<<pw)*q;   
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}