/*  
My eyes seek reality
My fingers seek my veins
Theres a dog at your back step
He must come in from the rain

I fall cause I let go
The net below has rot away
So my eyes seek reality
And my fingers seek my veins

The trash fire is warm
But nowhere safe from the storm
And I can't bare to see
What I've let me be
So wicked and worn

So as I write to you
Of what is done and to do
Maybe you'll understand
And won't cry for this man
'Cause low man is due

Please forgive me

My eyes seek reality
My fingers feel for faith
Touch clean with a dirty hand
I touched the clean to the waste

The trash fire is warm
But nowhere safe from the storm
And I can't bare to see
What I've let me be
So wicked and worn

So as I write to you
Of what is done and to do
Maybe you'll understand
And won't cry for this man
'Cause low man is due

Please forgive me
Please forgive me
Please forgive me

So low the sky is all I see
All I want from you is forgive me
So you bring this poor dog in from the rain
Though he just wants right back out again

And I cry, to the alley way
Confess all to the rain
But I lie, lie straight to the mirror
The one I've broken, to match my face

The trash fire is warm
But nowhere safe from the storm
And I can't bare to see
What I've let me be
So wicked and worn

So as I write to you (yeah)
Of what is done and to do (yeah)
Maybe you'll understand
And won't cry for this man
'Cause low man is due

Please forgive me
Please forgive me

So low the sky is all I see
All I want from you is forgive me
So you bring this poor dog in from the rain
Though he just wants right back out again

My eyes seek reality
My fingers seek my veins
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
#define eps 1e-9
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

long n,m,s[200000],ar[200000],l,ans;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;

for (int i=1;i<=n;i++)
cin>>ar[i];

s[0]=0;

for (int i=1;i<=n;i++)
s[i]=s[i-1]+ar[i];

l=0;
for (int i=1;i<=n;i++)
{
    while (s[i]-s[l]>m)++l;
    ans=max(ans,i-l);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}