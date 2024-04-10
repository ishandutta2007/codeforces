/*
Detonation
Fireworks and alchemy
Genes spliced and triggered
into the future
and her organic cave

Seismorgasmic omnipotence
scenes of magma in my eyes
Eruption stones my system

I owe this to the animal inside
and the stiffness that blocks out the daylight
Morphing into primal

I'll cover every particle
from there to Andromeda
not forgetting a single location
from the throat of the Ibis
to the co-ordinates of Matterhorn

My shot is genesis and catharsis
Penetratonaut in a cosmology of lusts

Suck this subterranean creature out
and show it proudly to the house of heaven
With one slight wave of my hand
stars dissolve

Dissolve my brain
Block my lungs
I'll die from fever tomorrow
when locked in such a perfected "now"
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 110031;

int n,ar[N];
int cnt;
int ans;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    }
    int mx=-1;
    for (int i=1;i<=n;i++){
    	mx=max(mx,ar[i]);
    }

    int ans=0;
    for (int i=1;i<=n;i++){
    	cnt++;
    	if (ar[i]!=mx)
    		cnt=0;
    	ans=max(ans,cnt);
    }
    cout<<ans<<endl;

//    cin.get(); cin.get();
    return 0;
}