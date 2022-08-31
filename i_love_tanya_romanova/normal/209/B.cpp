/*
Oppressed by darkness in the mind, unleashed action
Illusions forming to a substance, manifestation
Confused beyond reality, false-fact-fusion
Engulfed chaotic interlude, obscure vision
When the sick mind is left to rule...
Confusion grows, thoughts intertwine
Memory is a blur in a scenario of time
Details are exposed, but remain ignored
Things that are real, are found in a dream
The way in which to see things is not what it seems
Looking for answers, in a mirror that is blank
Images overlap
Reflections deviate
Images overlap
Reflections deviate
Vengeance, sickness claims its spite, twisted memory
Unbalance of fantasy and reality, ruptured harmony
Fiction animated falsely, materialized
There's no reason for deception, there's no lie
When the sick mind is left to rule...
Vast capacity of imagination
Within focus of concentration
Abstract input disrupting aim
Course of option appears the same
A rapid static flashing glance
Only a sudden random chance
When reasons defy reality
Insight has no authority
Visions that reality hid
Victimized by the Id
That's the reflections I despise
Or is it true the mirror lies?
The truth is clouded from my sight
Radiating heat not light
Mirages forming identity
Thoughts becoming entity
Images overlap
Reflections deviate
Images overlap
Reflections deviate
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

long long ans;
vector<long long> v;

int main(){
//freopen("binomial.in","r",stdin);
//freopen("binomial.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=0;i<3;i++)
{
    long long q;
    cin>>q;
    v.push_back(q);
}

ans=v[0]+v[1]+v[2]-1;

for (int i=0;i<3;i++)
    for (int j=i+1;j<3;j++)
    {
        if ((v[i]-v[j])%2==0)
            ans=min(ans,max(v[i],v[j]));//xl - xr - xl....| xy xy xy
    }

cout<<ans<<endl;

//cin.get();cin.get();
return 0;}