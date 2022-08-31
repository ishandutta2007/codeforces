/*
Far to the east ruled the Samurai, mystic warrior class,
Honorable brave, bark armoured man, donning hideous mask.
700 years of reigning Japan, the masters of attack,
Dominators of the isle of dragons, fearsom military caste.

In battle no prisoners for the enemy, noble self-sacrifice,
Crooked crowns sentenced to die, pay the bloody price.
Sacred rites held close by the fighters, no place for disgrace,
Taught to stand with dignity while staring in death's face.

[chorus:] 
Honor even in death, soldiers glorified,
The dagger plunges deep, slashes side to side.
Honor even in death, digrace is defied,
The end they never fear, give their life before their pride.
Honor even in death, soldiers glorified,
The dagger plunges deep, slashes side to side.
Honor even in death, digrace is defied,
The end they never fear, give their life before their pride.

Gracefully, with steady hand,
He takes the dagger that lays before him.
Collects his thoughts for the last time,
And plunges the dirge from left to right.
No sign of pain on his face,
With the final cut withdraws the blade.
Loyal companion by his side,
Lifts the sword to help him die.
Lightning flash, one swift blow,
Honor is done, warriors head rolls.

In a mans glory, his spirit is stored, his very being inside,
Dignity respected, courage is shown by his ritual suicide.
No room for dishonor in hari kari's dagger gashing side to side,
Under the rising sun the core is exposed, to reveal a new life.

[chorus]
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
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;
long n,tp,q,ans[2000],deg[2000];

int main(){
//freopen("raydist.in","r",stdin);
//freopen("raydist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>tp;
    deg[tp]++;
    cin>>q;
    ans[tp]+=q;cin>>q;
}
if (ans[1]>=deg[1]*5)cout<<"LIVE"<<endl;
else cout<<"DEAD"<<endl;
if (ans[2]>=deg[2]*5)cout<<"LIVE"<<endl;
else cout<<"DEAD"<<endl;

cin.get();cin.get();
return 0;}