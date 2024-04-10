/*
Hear my thin voice
Hear my words fall down
See my ambitions fade out
Had so much better times

At night walking on the tracks
Change my perspective
Idle hands with wounds and cracks
Stale
Ineffective
But past the veil
The memories of things
Still so in love with you

So dense this strife
Kicked the life
I feel this weight upon my heart

Indecision
Sow the seed
Aspiration is never within reach
At night there is no other view
Sing a song for the ones who never made it

In the ward under yellow lights
Under linden trees I am transparent
And led to believe that things would change if I go away
The lowering sky under which we go

So dense this strife
Kicked the life
I feel this weight upon my heart

Hear my thin voice
Hear my words fall down
See my ambitions fade out
Had so much better times

Constant noise behind the overcoming
I had no choice but to rearrange
The scar is open
I am not allowed to understand
I take it as you're not coming back

Indecision
Sow the seed
Aspiration is never within reach
At night there is no other view
Sing a song for the ones who never made it

See my ambitions fade out
Had so much better times
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

const int bs = 1000000007;

const int N = 600031;

int tests;
int n,m,k;
int to_remove[N];
int b[N];
int to_left[N],to_right[N];

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>k>>m;
    	for (int i=1;i<=n;i++){
    		to_remove[i]=1;
    	}
    	for (int i=1;i<=m;i++){
    		cin>>b[i];
    		to_remove[b[i]]=0;
    	}
    	int total_remove=n-m;

    	if (total_remove%(k-1)){
    		cout<<"NO"<<endl;
    		continue;
    	}

    	int C=0;
    	for (int i=1;i<=n;i++){
    		to_left[i]=C;
    		if (to_remove[i])
    			++C;
    		to_right[i]=total_remove-C;
    	}

    	int ok=0;
    	for (int i=1;i<=n;i++){
    		if (to_remove[i])
    			continue;
    		if (to_left[i]<k/2||to_right[i]<k/2)
    			continue;
    		if (to_left[i]%2!=to_right[i]%2)
    			continue;
    		ok=1;
    	}
    	if (ok)
    		cout<<"YES"<<endl;
    	else
    		cout<<"NO"<<endl;
    }
    //cin.get(); cin.get();
    return 0;
}