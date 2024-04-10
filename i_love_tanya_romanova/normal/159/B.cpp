/*
How come I shiver, hurt and bleed
If in dreams I cannot truly feel?
Who would dare say, who would claim
This hallucination isn't real?

Synoptical glitch looking glass
So enticing, real and free of lies
Prodigious, omnifarious
It nourishes, it feeds my starving eyes

Artificial, the catalyst, organic, its progeny
Voracious spectral offspring, so sweet in its hunger
Unbound this new vision, optical re-genesis
Threatening, so complete in beautiful deformity

These authoritive visions order my collective senses
My questioning, doubtful, rigid self to kneel
A Judas syndrome in effect, former self, the deceiver
Its denial, the wretched kiss that kept this in disguise

Cast off the concealing veil, the rational cloak of doubt
Torn off the restraints, the vile shackles
Burned away, the agony, the fear, the grief
A new set of eyes cleansed by a new belief
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

using namespace std;

long n,m,a,b,ans1,ans2,
calc1[11000000],calc2[11000000],calc3[11000000],calc4[11000000];

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>a>>b;
 calc1[b]++;
 calc2[a*10000+b]++;
}
for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 calc3[b]++;
 calc4[a*10000+b]++;
}
for (int i=0;i<=10100000;i++)
{
 ans1+=min(calc1[i],calc3[i]);
 ans2+=min(calc2[i],calc4[i]);
}
cout<<ans1<<" "<<ans2<<endl;

cin.get();cin.get();
return 0;}