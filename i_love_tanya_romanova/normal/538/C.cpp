/*
Rainy clouds covered up the sunny sky
now I know I'll sleep alone tonight
tears and prays will be taken by the rain
And the loneliness in my dreams
And I know I'll never be the same living this tragedy, insane,
All I wanna be is to be free with you, with me
I don't blame the fate but it's too hard to face the truth
It was all just like paradise
just like we wanted to be
far beyond the reason
rest our lives
eternity denies the guilt of reality
senselessness
Fly high, reaching skies
to eagles trying to be free
moments of madness will be left behind
the same horizon but in different lands...
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
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long n,m,x[1<<20],h[1<<20],ans,span,lwr;
long er;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>m>>n;

for (int i=1;i<=n;i++)
{
    cin>>x[i]>>h[i];
}

ans=h[1]+x[1]-1;

for (int i=2;i<=n;i++)
{
    span=x[i]-x[i-1];
    lwr=max(h[i],h[i-1]);
    span-=lwr-min(h[i],h[i-1]);
    ans=max(ans,lwr+span/2);
    if (span<0)er=1;    
}

ans=max(ans,h[n]+(m-x[n]));

if(er) cout<<"IMPOSSIBLE"<<endl;
else cout<<ans<<endl;

cin.get();cin.get();
return 0;}