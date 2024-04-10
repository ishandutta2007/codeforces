/*
Kept warm by the light of the lantern
Lost sight of everything tonight
My presence blackens their pattern
A pock in the healthy and calm

Their scorn behind your back
My promise would put them down
No trace of reverence left
Immemorial fire in their eyes

I would perish at the given signal
At the slightest touch from my soul
Tainted prophet in flesh
For all the plagued and lost

Dripping sin
Decision in stalemate
Dare to feel death at hand
Surprised me with its voice
Through the forest came the morn

Across the leafy pathway
Their deeds smeared in blood
For all to behold
The council of the cross
Must have sensed my coming
The pest through the air
With despise for squalor
Lashing out at the poor

I turned away my eyes
In pallor escape from the end
Fading time to leave from here
And less to fulfill my task
She would be safe and firm
Nothing of this is in vain
Taken away from stifling grace
And saved from the past
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

using namespace std;

long n,q,calc[1000],t;

int main(){
//freopen("firesafe.in","r",stdin);
//freopen("firesafe.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>q;
    calc[q]++;
}
if (calc[0]==0)
cout<<-1<<endl;
else
{
    if (calc[5]<9)cout<<0<<endl;
    else
    {
        t=calc[5]-calc[5]%9;
        for (int i=0;i<t;i++)
        cout<<5;
        for (int j=0;j<calc[0];j++)
        cout<<0;
        cout<<endl;
    }
}

cin.get();cin.get();
return 0;}