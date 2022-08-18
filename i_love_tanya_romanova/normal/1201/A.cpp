/*
Down in the bayou where the alligators roam
Live some people, you leave them alone
Getting lost may be your last mistake
Unfriendly strangers, unkindly they take
Living off the fat of the land
They hold their justice in the palm of their hand
Lay down your gun and surrender quiet
Or there's gonna be a Cajun riot

Danger in the swamp, that waits for you
There's nothing left that you can do
Better watch your back, for the vicious attack
'Cause they'll be looking for you
Playing with your life, for your life is too short
Pain is too good for you
Your last breath, is all you have left
Take it before you're doomed
Cajun hell
Before you're doomed

Raising hell, and they're ready for fighting
Huntin' gators and drinking white lightning
Brewin' moonshine at a still in the swamp
Playing Creole from dusk until dawn
Protect their own is the law of the land
Mess with their law it will get out of hand
Keep it in mind if you're ever down there
It might be fatal, you better beware
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

int n,m;
string st;
int cnt[1031][1031];
int val;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n>>m;
    for (int i=1;i<=n;i++){
    	cin>>st;
    	for (int j=1;j<=m;j++){
    		cnt[j][st[j-1]-'A']++;
    	}
    }

    int ans=0;

    for (int i=1;i<=m;i++){
    	cin>> val;
    	int mx=0;
    	for (int j=0;j<5;j++){
    		mx=max(mx,cnt[i][j]);
    	}
    	ans+=val*mx;
    }
    cout<<ans<<endl;

//    cin.get(); cin.get();
    return 0;
}