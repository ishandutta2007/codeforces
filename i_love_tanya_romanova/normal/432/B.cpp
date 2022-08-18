/*
Hey... Look around you
Everything's helter-skelter
Listen up... I warn you
Run for cover, run
Bang... It happened
Time's up, Armageddon
Fire... Meltdown
The sky is crumbling in

Black Curtains... Never ending

Escape... You're joking
Can't find no place to run
Hair... Is burning
My flesh is bubbling up
Blood... Is boiling
Taste copper on my tongue
Fate... Is coming
Welcome it with a smile

Black Curtains... Never ending, fall

Am I dreaming? My heart pounds my chest
Held for ransom in spider's web
Suffocating, no one hears my calls
Never ending, till the black curtain falls

Snakes... Surround me
Offering their death kiss to me
Down... I'm drowning
How long, I hold my breath
Dogs... Are chasing
My legs are paralyzed
Pray... Don't find me
My life is fading fast
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
 
#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256
 
using namespace std;

long n,c1[200000],c2[200000],ans,calc[200000];

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>c1[i]>>c2[i];
 calc[c1[i]]++;
}
for (int i=1;i<=n;i++)
{
 ans=n-1;
 ans+=calc[c2[i]];
 cout<<ans<<" "<<n*2-2-ans<<endl;
}

cin.get();cin.get();
return 0;}