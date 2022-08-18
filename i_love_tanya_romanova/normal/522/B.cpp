/*
And again the moon is on the wave, gliding gently into me,
on silent wings the night comes from there,
as my heart longs to thee...

...for in my hand I still hold the rose that froze long times ago,
its leafs have withered, it ceased to grow - left in me is woe.

The wine of love, is o so sweet, but bitter is regret,
I knew at sunset I would meet the ascending veils of dread.

Before my eyes nocturnal curtains fall,
The dark and gentle haze of the night, greedily devours all.

The Night:
"Woe to him whose heart is filled with bitter rue and who drowns in grief"

In the silence of the night I loose myself,
it makes me drunken with its sweet blue sound.

In the drunk'ness of solitude
I fear no more the solemn realms of death
No single sigh from my lips as I drink the wine of bitterness
My heart is aching nevermore
for I know that all may end
Just I and the poetry of the night
Now forever one....

Just I and the poetry of the night, now forever one,
The ensemble of silence plays so beautiful for me...
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

long n,w[1<<20],h[1<<20],sw[1<<20],mh1[1<<20],mh2[1<<20];

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>w[i]>>h[i];
 sw[i]=sw[i-1]+w[i];
 mh1[i]=max(mh1[i-1],h[i]);   
}

for (int i=n;i;--i)
{
 mh2[i]=max(mh2[i+1],h[i]);
}

for (int i=1;i<=n;i++)
{
    if (i>1)cout<<" ";
    cout<<max(mh1[i-1],mh2[i+1])*1ll*(sw[n]-w[i]);
}
cout<<endl;

cin.get();cin.get();
return 0;}