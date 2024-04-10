/*
Pacing aimlessly,
With my mind in unrest
Unsure of what may come.
What have I done to bring this down on me?
Helpless to make this undone

All in due time, see the world through different eyes.
All in due time, shadows will give way to light.

How much more can I give of myself
as these walls close in on me?
As I slip down in to this despair (into this despair),
There is nothing to attain

What victory (what victory)
When my soul is weak (is weak)
where does my help come from?

All in due time, see the world through different eyes.
I see the world through different eyes.
All in due time, shadows will give way, give way to light.

All that we suffer through leads to determination.
The trials we all go through gives us the strength to carry on.
Something within us burns, desire feeds the will to live.
A reason to believe I will see redemption.

All in due time, see the world through different eyes.
I see the world through different eyes.
All in due time, shadows will give way to light.
All in due time.
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

const int N = 1200031;

int n,m,k;
int used[N];
int prev[N];

long long solve(int step){
	int cur=0;
	int res=1;
	while (true){
		if (cur+step>=n)
			break;
		int ptr=cur+step;
		int next_ps=ptr;
		if (used[next_ps])
			next_ps=prev[next_ps];
		if (next_ps==cur)
			return 1e15;
		++res;
		cur=next_ps;
	}
	return res;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>m>>k;

	for (int i=1;i<=m;i++){
		int val;
		cin>>val;
		used[val]=1;
	}

	if (used[0]){
		cout<<-1<<endl;
		return 0;
	}

	for (int i=1;i<=n;i++){
		if (used[i-1]==0)
			prev[i]=i-1;
		else
			prev[i]=prev[i-1];
	}

	long long ans=1e18;

	for (int step=1;step<=k;step++){
		int am;
		cin>>am;
		long long here=solve(step);
		if (here<1e9)
			ans=min(ans,here*am);
	}

	if (ans>1e15)
		ans=-1;
	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}