/*
I will be there when you mock thyself
In the nighttime, when the shadows dance
I will be there when you burn thyself
She betrayed you, coldness tears your soul

Out of the darkness
Ye've locketh me in
I have been aneath
I'll feed your fear

Whose is this voice, and why this strayness,
This bitter rage I can't control?

She'll grind ye down
She'll throw ye out
I'll be all hate that hides in ye
And all the things banished

I shall promise you vast victories
She will be crawling back on hands and knees
I shall cease your grief and heavy moan
I shall stick the blade through every whore

We have no choice, drowned She shall be
All th' wounds she stroke in thee
Tenfolded striken back in her
Tenfolded every whore shall burn

In dreadful deeds we shall unite
As one we shall not cease the fight
I shall set ye on th' throne of night,
Bring forth revenge that you desire

"I grind my teeth, I grind my teeth
I bite and pull ye deep beneath
Oh, let the children come to me...!"

...And I shall set, yer desires free
For dark is our hate
So let there be rage!

...And I shall show ye th' sterling strength
Of thousand pariahs
Let there be revenge!

I will be there when you mock thyself...

My sight, has it frailed,
has darkness prevailed?
Is someone still here with me?
Here in me?

These hands are they mine?
Is this smile or a grin?
What is this hate in me?
My love, where is she?

Scortum! Scortum!
Scornful whores!
Blade or a loin they are yearning for more!
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
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512
#define nice adsfasdfasdfasdf

using namespace std;

long long h,w,n,dp[1<<20];
vector<pair<long long, long long> > v;
long long fact[1<<20],invf[1<<20];

long long pw(long long a,long long b)
{
    if (b==0)
        return 1;
    if (b%2)
        return a*pw(a,b-1)%bs;
    return pw(a*a%bs,b/2);  
}
long long inv(long long x)
{
    return pw(x,bs-2);
}

long long c(long long n,long long m)
{
    if (m>n)
        return 0;
    long long res=fact[n];
    res*=invf[m];
    res%=bs;
    res*=invf[n-m];
    return res%bs;
}

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

fact[0]=1;
for (int i=1;i<=300000;i++)
    fact[i]=fact[i-1]*i%bs;

for (int i=0;i<=300000;i++)
    invf[i]=inv(fact[i]);

cin>>h>>w>>n;
for (int i=1;i<=n;i++)
{
    int a,b;
    
    cin>>a>>b;
    v.push_back(make_pair(a,b));
}

v.push_back(make_pair(1,1));
v.push_back(make_pair(h,w));

sort(v.begin(),v.end());

dp[0]=1;
n=v.size();

for (int i=1;i<v.size();i++)
{
//  cout<<i<<endl;
    dp[i]=c(v[i].first+v[i].second-2,v[i].first-1);
    for (int j=1;j<i;j++)
    {
        if (v[j].first<=v[i].first&&v[j].second<=v[i].second)
        {
            long long temp=c(v[i].first-v[j].first+v[i].second-v[j].second,v[i].first-v[j].first);
            temp=temp*dp[j]%bs;
            dp[i]=dp[i]+bs-temp;
            dp[i]%=bs;
        }
    }
}
cout<<dp[n-1]<<endl;

//cin.get();cin.get();
return 0;}