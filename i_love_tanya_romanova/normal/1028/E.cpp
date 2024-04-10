/*
They disembarked in '45
And no one spoke and no one smiled
There were too many spaces in the line

And gathered at the cenotaph
All agreed with hand on heart
To sheath the sacrificial knives

But now
She stands upon
Southampton Dock
With her handkerchief
And her summer frock
Clings to her wet body in the rain

In quiet desperation
Knuckles white upon the slippery reins
She bravely waves the boys goodbye again

And still the dark stain spreads between
Their shoulder blades
A mute reminder
Of the poppy fields and graves
And when the fight was over
We spent what they had made
But in the bottom of our hearts
We felt the final cut
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

const int N = 600031;

int n;
long long ar[N],ans[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;

	for (int i=0;i<n;i++){
		cin>>ar[i];
	}

	int ps=-1;
	for (int i=0;i<n;i++){
		if (ar[i]>ar[(i+n-1)%n]) // i > i-1
			ps=i;
	}

	int all_zeros=1;
	for (int i=0;i<n;i++){
		if (ar[i]>0)
			all_zeros=0;
	}

	if (all_zeros){
		cout<<"YES"<<endl;
		for (int i=0;i<n;i++){
			if (i)
				cout<<" ";
			cout<<1;
		}
		cout<<endl;
		return 0;
	}

	if (ps==-1){
		cout<<"NO"<<endl;
		return 0;
	}

	cout<<"YES"<<endl;

	ans[ps]=ar[ps];
	for (int i=ps-1;i>ps-n;i--){
		int cur_ps=(i+n)%n;
		int nxt_ps=(cur_ps+1)%n;

		long long times;

		if (ans[nxt_ps]<1e9)
			times=1e9/ans[nxt_ps]+2;
		else
			times=1;

		ans[cur_ps]=ans[nxt_ps]*times+ar[cur_ps];
	}

	for (int i=0;i<n;i++){
		if (i)
			cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;

//	cin.get(); cin.get();
	return 0;
}