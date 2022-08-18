/*
Hey... oooh...
Sheets of empty canvas, untouched sheets of clay
Were laid spread out before me, as her body once did
All five horizons revolved around her soul, as the earth to the sun
Now the air I tasted and breathed has taken a turn

Ooh, and all I taught her was everything
Ooh, I know she gave me all that she wore
And now my bitter hands shake beneath the clouds
Of what was everything

All the pictures had
All been washed in black, tattooed everything
I take a walk outside, I'm surrounded by some kids at play
I can feel their laughter, so why do I sear?

And twisted thoughts that spin round my head
I'm spinning, oh, I'm spinning
How quick the sun can, drop away
And now my bitter hands cradle broken glass
Of what was everything

All the pictures had
All been washed in black, tattooed everything
All the love gone bad, turned my world to black
Tattooed all I see, all that I am, all I'll be, yeah
Uh huh... uh huh... ooh...

I know someday you'll have a beautiful life
I know you'll be a star in somebody else's sky
But why, why, why can't it be, can't it be mine?
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
#define bsize 256
#define clone agsdahfaassdg

using namespace std;

long rem,cost[20],temp,mcost,ans,bdig;

int main(){
//freopen("virtualfriends.in","r",stdin);
//freopen("virtualfriends.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>rem;
for (int i=1;i<=9;i++)
cin>>cost[i];
mcost=1000000;

for (int i=1;i<=9;i++)
if (cost[i]<mcost)mcost=cost[i];

ans=rem/mcost;
if (rem<mcost)cout<<-1<<endl;
else
{

for (int i=1;i<=ans;i++)
{
 bdig=-1;
 for (int j=1;j<=9;j++)
 {
     temp=rem-cost[j];
     if (temp<0)continue;
     if (temp/mcost+i>=ans)bdig=max(bdig,ans-ans+j);
 }  
 cout<<bdig;
 rem-=cost[bdig];
}
cout<<endl;
}

cin.get();cin.get();
return 0;}