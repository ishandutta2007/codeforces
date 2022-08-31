/*
Carelessly you sentence. How indifferently you kill
The prophecies of mans corruption fulfilled

Arbitrarily you harm. Snap your fingers, cue demise
Murder on impulse. Your evil inclinations wrapped in lies

Divine man. Appointed. Claiming the stern voice of god
Absolute judgments passed from where you cowards hide
- The lair of snakes. Your dark haven
Where you and your ophidian partisans abide

The doctrine of your unholy trinity
- The violence, the spite and the enslavement
You awesome monarch, you man of dominance
All shall be as you decide

Illustrious ruler of all things
Wield your razors, cut the flesh of man
Control, govern and lead us
Into the nightmare of your wishes fulfilled

Grab the reins, you awesome puppeteer, you conductor of chains
Redeemer. Unbreakable strings. Damnation leashes
Remote cords extend, the trusses they run
They stretch all the way behind the sun

So vain our attempts, the useless tugging
This meaningless gnawing at restraints by which we're bound
Hail the tyrant saint, the great bereaver
You will bow before the emperor crowned
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
//#include <memory.h>

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

long n,m,a,c,usd[100],cl[200000];
long b,p;

int main(){
//freopen("deny.in","r",stdin);
//freopen("deny.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
    cin>>a>>b>>c;
    usd[1]=usd[2]=usd[3]=0;
    usd[cl[a]]=1;
    usd[cl[b]]=1;
    usd[cl[c]]=1;
    if (cl[a]!=0){usd[cl[a]]=1;}else{p=1;while (usd[p])++p;cl[a]=p;usd[p]=1;}
    if (cl[b]!=0){usd[cl[b]]=1;}else{p=1;while (usd[p])++p;cl[b]=p;usd[p]=1;}
    if (cl[c]!=0){usd[cl[c]]=1;}else{p=1;while (usd[p])++p;cl[c]=p;usd[p]=1;}
 //   cout<<cl[a]<<" "<<cl[b]<<" "<<cl[c]<<endl;
}

for (int i=1;i<=n;i++)
{
    if (i-1)cout<<" ";
    cout<<cl[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}