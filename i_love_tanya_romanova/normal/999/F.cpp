/*
All the shades of gray that loom inside me
No one's ever home and there's no one around me
Such a perfect waste this soul behind me
No one really knows what truly drives me

I know what I've done wrong
I knew it all along
I can't let it go, let it go, let it go

Run away, run away
Look away, look away
I see it inside you
I'm stuck in my ways, stuck in my ways
Run away, run away
Get away, get away
Leave me behind you
I'm stuck in my ways, stuck in my ways

All the shades of red that have designed me
All the hell I've seen, it still confines me
All the pain I've felt, it's still inside me
All the rage I have, it still completes me

I know what I've done wrong
I knew it all along
I can't let it go, let it go, let it go
Let it go

Run away, run away
Look away, look away
I see it inside you
I'm stuck in my ways, stuck in my ways
Run away, run away
Get away, get away
Leave me behind you
I'm stuck in my ways, stuck in my ways
Stuck in my ways, stuck in my ways

Just run away, run away
Look away, look away
I see it inside you
I'm stuck in my ways, stuck in my ways
Run away, run away
Get away, get away
Leave me behind you
I'm stuck in my ways, stuck in my ways
Stuck in my ways, stuck in my ways
No!
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600031;

int n,k,cnt[N];
int cnt_want[N];
int f[N];
int h[N];
long long ans;

long long knap[515][5151];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>k;
	for (int i=1;i<=n*k;i++){
		int val;
		cin>>val;
		cnt[val]++;
	}

	for (int i=1;i<=n;i++){
		cin>>f[i];
		cnt_want[f[i]]++;
	}

	for (int i=1;i<=k;i++){
		cin>>h[i];
	}

	for (int i=0;i<=500;i++){
		for (int j=0;j<=5000;j++){
			knap[i][j]=-1e18;
		}
	}
	knap[0][0]=0;
	for (int i=0;i<500;i++){
		for (int j=0;j<=5000;j++){
			for (int take=0;take<=k;take++){
				knap[i+1][j+take]=max(knap[i+1][j+take],knap[i][j]+h[take]);
			}
		}
	}

//	run_knap();

	for (int val=1;val<=100000;val++){
		if (cnt[val]==0&&cnt_want[val]==0)
			continue;
		long long here=0;
		for (int i=0;i<=cnt[val];i++){
			here=max(here,knap[cnt_want[val]][i]);
		}
		here=max(here,0ll);
		ans+=here;
	}
	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}