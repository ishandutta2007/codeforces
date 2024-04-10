/*
Feel so good I feel so fine
Love that little lady always on my mind
Gives me lovin' every night and day
Never gonna leave her, never goin' away

Someone to love me
You know she makes me feel alright
Someone who needs me
Love me every single night

Feel so happy since I met that girl
When we're making love it's something out of this world

Feels so good to know that she's all mine
Going to love that woman 'til the end of time

Someone to live for
Love me 'til the end of time
Makes me feel happy
Good to know that she's all mine

Lovely lady make love all night long
Lovely lady never do me wrong
I don't wanna leave ya
I never wanna leave ya,
anymore no more
Lovely lady, mystifying eyes
Lovely lady, she don't tell me no lies
I know I'll never leave ya
I'm never gonna leave ya anymore no more
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

int n,C,ar[N],pref[N],suf[N];
int last_entry[N],best_pref[N];
int ans;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>C;

	for (int i=1;i<=n;i++){
		cin>>ar[i];
		pref[i]=pref[i-1];
		if (ar[i]==C)
			pref[i]++;
	}

	for (int i=n;i>=1;--i){
		suf[i]=suf[i+1];
		if (ar[i]==C)
			suf[i]++;
	}

	for (int i=1;i<=n;i++){
		best_pref[i]=pref[i-1]+1;
		int le=last_entry[ar[i]];
		if (le>0)
			best_pref[i]=max(best_pref[i],best_pref[le]+1);
		last_entry[ar[i]]=i;
	}

	for (int i=1;i<=n;i++){
		ans=max(ans,best_pref[i]+suf[i+1]);
	}
	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}