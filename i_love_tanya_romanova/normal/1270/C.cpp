/*
Sent from home overseas
And into the unknown
Barely landed in the jungle
Sent on first patrol

Sundown darkness falls
Dig in for the night
Ambushed in the dawn they came
The jungle's alive

I feel my fire starts to burn
The heat controlling my mind
Berserk a savage running wild
Within me the beast starts to roar

[Chorus:]
Now I'm ready to strike
A creature of the night
Into the fire
The flame of napalm strike

Sarge's down I'm in charge
Vc's everywhere
Overrun yet order airstrike
Condemned us all to burn

Napalm from above
Burning friend and foe
Chaos on the battlefield
The jungle's on fire

This place it's driving me insane
Napalm it's burning us all
This fight no man will live to tell
Within me my blood starts to boil

[Chorus]

From above the airstrike came
And it burned the world below
Napalm falling from the sky
And it leaves no man alive

I feel my fire starts to burn
The heat controlling my mind
Napalm it's burning us alive
Within me the beasts final roar

[Chorus]
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
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

int tests;
long long n;
vector<long long> ans;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	long long cur_sum=0;
    	long long cur_xor=0;
    	for (int i=1;i<=n;i++){
    		int val;
    		cin>>val;
    		cur_sum+=val;
    		cur_xor^=val;
    	}
    	ans.clear();
    	ans.push_back(cur_xor);
    	cur_sum+=cur_xor;
    	cur_xor=0;
    	ans.push_back(cur_sum);
    	cout<<2<<endl;
    	cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    //    cin.get(); cin.get();
    return 0;
}