/*
I hear they're trying to make us all the same
It's mind control by any other name
Who's gonna pay the price
For this foolish paradise
Oh:Momma don't take that train

I hear it said we're headed too far south
Chinese whispers go by word of mouth
Rules for every size and shape
The nag has gone, shut the gate
Once you're in you're never getting out

I'm so misunderstood
There goes my manlihood
She's in my face again
With that picture of innocence

No drinks, No smokes
No dicking around
No dirty jokes
Straight lace, straight face
The old straight jacket
We got no hope

I hear they're gonna try out something new
I can feel it sticking to my shoe
So this is what tomorrow holds
Hopes and dreams are bought and sold
But still the world is misty green and blue

I', so misunderstood
There goes my mannish boyhood
She's in my face again
With that picture of innocence

No deals, No strokes
No forbidden fruit
No holy smoke
What next, no sex
That's the end of the road
That's the end of the road
We got no hope

No drinks, No smokes
No dicking around
No dirty jokes
Straight lace, straight face
The old straight jacket
We got no hope

No deals, No strokes
No forbidden fruit
No holy smoke
What next, no sex
That's the end of the road
We got no hope
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

using namespace std;

int primes[1<<24],pal[1<<24],pr[1<<23];

bool palin(int x)
{
    vector<int> v;
    while (x)
    {
        v.push_back(x%10);
        x/=10;
    }
    vector<int> v1;
    v1=v;
    reverse(v1.begin(),v1.end());
    return v1==v;
}

int p,q,ans;

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

pr[1]=1;
for (int i=2;i<=3000000;i++)
    if (pr[i]==0)
        for (int j=i*2;j<=3000000;j+=i)
            pr[j]=1;

for (int i=1;i<=3000000;i++)
    primes[i]=primes[i-1]+(pr[i]==0);

for (int i=1;i<=3000000;i++)
{
    pal[i]=pal[i-1];
    if (palin(i))
        pal[i]++;
}

cin>>p>>q;

ans=1;
for (int i=1;i<=3000000;i++)
{
    if (1ll*primes[i]*q<=1ll*p*pal[i])
        ans=i;
}

//cout<<primes[1000000]*1.0/pal[1000000]<<endl;

cout<<ans<<endl;

//cin.get();cin.get();
return 0;}