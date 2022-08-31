/*
Sitting up late at night
A tiptoe through the darkness
Cold as hell black as spades
Aware of my immediate surrounding
In my place I escape
Up into my hideout
Hiding from everyone
My friends all say
Dave your mental anyway hey!
Drift into a deeper state
I stalk the cobwebbed stairways
Dirt grits beneath me feet
The stair creaks, I precariously sneak

Hypnosis guides my hand
I slipside through the walkways
Sit in granny's rockin' chair
Memories are whirling by yeah
Reminisce in the attic
Lucretia waits impatiently
Cobwebs make me squint
The cobra so eloquently glints
Moonbeams surge through the sky
The crystal ball's energized
Surely that like the cat waiting
Lucretia rocks away
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 300031;

int n,tests;
int ar[N];
int earliest[N][22];
int last_entry[22];

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>tests;
    for (int i=1;i<=n;i++){
    	scanf("%d",&ar[i]);
    }

    for (int i=1;i<=n+1;i++){
    	for(int j=0;j<=20;j++){
    		earliest[i][j]=n+1;
    	}
    }

    for (int i=0;i<20;i++){
    	last_entry[i]=n+1;

    }
    for (int i=n;i>=1;--i){
    	for (int j=0;j<20;j++){
    		earliest[i][j]=n+1;
    	}
    	for (int j=0;j<20;j++){
    		if (ar[i]&(1<<j)){
    			earliest[i][j]=i;
    			for (int q=0;q<20;q++){
    				earliest[i][q]=min(earliest[i][q],earliest[last_entry[j]][q]);
    			}
    			last_entry[j]=i;
    		}
    	}
    }

    for (int test=1;test<=tests;test++){
    	int l,r;
    	scanf("%d",&l);
    	scanf("%d",&r);
    	int can=0;
    	for (int i=0;i<20;i++){
    		if (ar[r]&(1<<i))
    			if (earliest[l][i]<=r)
    				can=1;
    	}
    	if (can)
    		puts("Shi");
    	else
    		puts("Fou");
    }

//    cin.get(); cin.get();
    return 0;
}