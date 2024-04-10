/*
Emotions are easily spent, twisted and forever bent.
When fixations are not returned the lines are so quickly obscured.

When I am haunted by your vision, I will cause you pain.
At me you spit your derision, you are my obsession.
You are repelled by my existence, but you will soon be trained.
My sins atoned for in silence, an act of contrition.

Held before my eyes though distant enough to be seen,
If I were to pull it too close, I'd blur it to its full extreme.

I'm barren of anything else,
A lunatic's need to possess you.

When I am haunted by your vision, I will cause you pain.
At me you spit your derision, you are my obsession.
You are repelled by my existence, but you will soon be trained.
My sins atoned for in silence, an act of contrition.

Rational thought
Has vanished and fled for its life.
The one goal after which I've sought
It's upon your fear that I thrive.

When written words are now legible,
The story can be told.
But when they're thrust too close to my eyes,
They become a blindfold.

And it's then reality,
Fades into obscurity.

Then I find that my mania is out of control.
I tighten the grip on my obsession, but I can't be consoled.

Now it's made me dangerous
To all but you I'm oblivious.

Distortions, perverse and unfair, you're threatened as I dominate.
You need me, so why are you scared? From my grasp there is no escape.

Don't you ever think of leaving me.
You are mine until I set you free.
The pain you feel is of no consequence.
Many suffer, few survive...

I'm not one with whom to be toyed, your mind easily I'll destroy.
Enforcing my supremacy, accept me, I'm your destiny.

When I am haunted by your vision, I will cause you pain.
At me you spit your derision, you are my obsession.
You are repelled by my existence, but you will soon be trained.
My sins atoned for in silence, an act of contrition.
 *
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

const int N = 400031;

int n;
int cnt[2][1<<20];

int S[N];
long long ans;
int ar[N];

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
    	S[i]=S[i-1];
    	S[i]^=ar[i];
    }

    for (int i=0;i<=n;i++){
    	ans+=cnt[i%2][S[i]];
    	cnt[i%2][S[i]]++;
    }

    cout<<ans<<endl;

//    cin.get(); cin.get();
    return 0;
}