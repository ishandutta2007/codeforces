/*
Matriarchal piety disturbed at their
Vespers.
Sisterly society feels the stifling whispers...
Anger of the dead-at-sea denied proper
Interment,
Dumped overboard summarily, washed down
In a current.

Sepulchral consideration...
Wrathful omen...
Dog removed from the casket,
Dead and dripping.

First stage of disintegration... Piecemeal
Decomposition
Of the indignant deceased, submerged for
What reason?
Parchedness of living throats and mouths
Has cracked some tongues
But attempts to slake their thirst (only)
Leads to soaking lungs.

Hearts are heavy, minds are numb, souls
Oppressed...
Supernatural siege upon the landlocked
Dead.
Baptism in netherfluids In their crypts,
(but) Suffocating dryness in the catacombs.

Mad at thirst, they dry
To draw sustenance
From a burial mound;
Necrophagous fails,
Aridity ends lives,
More wet corpses found.

Watery warfare, and in its mist,
The forsaken
Who cry for them, the bridges of
The flaccid god.

Intone a funeral rosary...
Blessed morbid murmur
To hopefully placate the dead and
End the curse of moisture.
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

using namespace std;

long n,m;
char c;
long hi[600000][3],hj[600000][3],ans;
long temp;
long l,u;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
     cin>>c;
     if (c=='.')continue;
     temp=c-48;
     if (temp<3)l=1;else l=0;
     if (l%2==j%2)
     hi[i][1]=1;
     else hi[i][0]=1;
     if (temp==1||temp==4)u=1;else u=0;
     if (u%2==i%2)
     hj[j][1]=1;else hj[j][0]=1;
 }

ans=1;
for (int i=1;i<=n;i++)
{
 temp=2;
 temp-=hi[i][0]+hi[i][1];
 ans=ans*temp%1000003;
}

for (int i=1;i<=m;i++)
{
 temp=2;
 temp-=hj[i][0]+hj[i][1];
 ans=ans*temp%1000003;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}