/*
I hear you calling me
Just like the voices in a dream
I hear you calling me
Just like the voices in a dream
I can remember
Daylight dancing in your eyes
And when my mind is still
The memories come alive
The silent space between my thoughts
Is where your soul resides
And when my heart is still
The memories come to life
Memories haunting me
They echo through eternity
I hear you calling me
Just like the voices in a dream
When fear and darkness overcome
I have no need to hide
I only need to call your name
In my heart you are still alive
The silent space between my thoughts
Is where your soul resides
And when my heart is still
The memories come to life
Voices in a dream
Voices in a dream
Memories haunting me
They echo through eternity
I hear you calling me
Just like the voices in a dream
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