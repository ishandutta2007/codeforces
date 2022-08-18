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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600000;

int n,s;
int a[N],b[N];
int used[N][2];

void dfs(int v,int dir){
	if (used[v][dir])
		return ;

	used[v][dir]=1;
	if (a[v]){
		for (int i=v+1;i<=n;i++){
			if (a[i])
				dfs(i,1);
		}
	}
	if (b[v]){
		for (int i=1;i<v;i++){
			if (b[i])
				dfs(i,0);
		}
	}
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>s;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		cin>>b[i];
	}

	if (a[1])
		dfs(1,1);
	if (used[s][0]||used[s][1])
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

//	cin.get(); cin.get();
	return 0;
}