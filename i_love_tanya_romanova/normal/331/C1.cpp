/* 
In one last breath
You'll feel this damned old soul
You'll see the things I see

For all these years
Of pain and sacrifice
You'll know the pain I know

Of all these things
I offer unto you
Infernal wisdom waits

Now unleashed
Like the flames of hate
My sacrifice is made

Every note
And every word you hear
Comes from deep within

An angry soul
That twists and turns inside
Pondering this life

Crimson eyes
Staring through your lies
Awakes the inner rage

Take my knife
Make my sacrifice
You're my burnt offering

Spill your blood
Offer me good omen
Make the sacrifice, the hours close at hand
Burn your soul
Offer me good omen
Take your very life, this I command

Dark shadows fall on this sacred ground
Where true evil lies, summon them to rise
Take the traitors, thieves and liars
Feed them to the fire
But first, spread their blood around
The message will be found
Walk carefully my friends stab my back again
A warning from the skies

These are not idle threats my friends
We're slaughtering the lambs
True vengeance is on the rise
The traitors shall be damned
Cast their bodies to the flames

Spill your blood
Offer me good omen
Make the sacrifice, the hours close at hand
Burn your soul
Offer me good omen
Take your very life, this I command
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
#define eps 0.001
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

long ans[2000000];
long can[11],q,n;

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

ans[0]=0;
for (int i=1;i<=1000000;i++)
ans[i]=10000000;

for (int i=1;i<=1000000;i++)
{
 for (int j=0;j<10;j++)
 can[j]=0;
 q=i;
 while (q){can[q%10]=1;q/=10;}   
 for (int j=1;j<10;j++)
 if (can[j])ans[i]=min(ans[i],ans[i-j]+1);
}

cin>>n;
cout<<ans[n]<<endl;

cin.get();cin.get();
return 0;}