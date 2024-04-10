/*
From the skies, across the sea of lies
To the dungeons of the damned
Scorching winds blazing thunderclouds raging
Here I make my stand

The viper's venomous bite
Has brought on the night
Swept away, like a bird of prey
Now there's hell to pay

From darkness into light
Nothing matters anymore
My strings ring hollow
Bleeding evermore

Nevermore
Can't let go
Your silences tells me
All I need to know
Nevermore
Strike a chord
The walls of silence fall
Nevermore

Kings of death calling
Frigid breath fallin
In the cyptic den
Curse the dark with a
Longing heart and song
You will rise again

On tragic wings I take flight
Bring on the night
Eyes of stone ripping flesh from bone
Into depths unknown

From darkness into light
Nothing matters anymore
My strings ring hollow
Bleeding evermore

Nevermore
Can't let go
Your silences tells me
All I need to know
Nevermore
Strike a chord
The walls of silence fall
Nevermore

Lost in shadows of what might have been
Bloodless spirits wept in fear
The void of anguish slowly pulls me in
"Abandon hope all who enter here"

Nevermore
Can't let go
Your silences tells me
All I need to know
Nevermore
Strike a chord
The walls of silence fall
Nevermore
Nevermore
Nevermore
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
#define bsize 256

using namespace std;

int n,l,r,x,ans,s;
int ar[1<<20];

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>l>>r>>x;
for (int i=0;i<n;i++)
 cin>>ar[i];
ans=0;

for (int mask=0;mask<(1<<n);mask++)
{
    int minn=1e9;
    int maxx=-1e9;
    int s=0;
    for (int i=0;i<n;i++)
    {
        if (mask&(1<<i))
        {
            minn=min(minn,ar[i]);
            maxx=max(maxx,ar[i]);
            s+=ar[i];
        }
    }
    if (maxx-minn>=x&&s>=l&&s<=r)
    ans++;
}

cout<<ans<<endl;
//cin.get();cin.get();
return 0;}