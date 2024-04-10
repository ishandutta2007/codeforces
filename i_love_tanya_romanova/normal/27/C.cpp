/*
Afraid to walk the streets
In the coldness all alone
The blackness of the night
Engulfs your flesh and bones
Hoping for relief
From the fear you feel inside
Losing all perspective
Of reality in the night

[Chorus:]
Running from shadows
Blinded by fear
The horror of nightfall
Is ever so near
I slowly surround you
As terror sets in
Are you afraid of the night

I see the fright in your eyes
As you turn and run
But is your mind playing tricks
On a body so very young
Feeling as if no one cares
The fear runs down your spine
But I know I'll never rest
Until I know you're mine

[Chorus]

Afraid to walk the streets
In the coldness all alone
The blackness of the night
Engulfs your flesh and bones
Feeling as if no one cares
The fear runs down your spine
But I know I'll never rest
Until I know you're mine
I know you're mine
Too late to hide
Too late to save your life
Tormentor
*/

#pragma comment(linker, "/STACK:16777216")
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

long n,ar[200000],ans;

int main(){
//freopen("cooling.in","r",stdin);
//freopen("cooling.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for(int i=1;i<=n;i++)
cin>>ar[i];

ans=-1;
for (int i=2;i<n;i++)
{
 if (ar[i]>ar[1]&&ar[i]>ar[i+1])ans=i;
 if (ar[i]<ar[1]&&ar[i]<ar[i+1])ans=i;
 if (ar[i]>ar[1]&&ar[i]>ar[i+1])ans=i;
 if (ar[i]<ar[1]&&ar[i]<ar[i+1])ans=i;
}

if (ans==-1)cout<<ans+1<<endl;
else
{
    cout<<3<<endl;
    cout<<1<<" "<<ans<<" "<<ans+1<<endl;    
}

cin.get();cin.get();
return 0;}