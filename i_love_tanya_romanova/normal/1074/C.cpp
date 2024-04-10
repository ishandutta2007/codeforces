/*
Easy to be taken with everything youre saying
Make us perfect and say it all again
But if every single seconds killing
Tell me Im dreaming
Ill sleep it all away

Tear out this love
Tear up the root
Tear out this love
Tear me from you

You know you can tell me anything you want to
Tell me something that Id never know
Could be cautious as the words roll over your tongue
Im stung with sick discovery

Tear me from these complicated questions
Taking all the empty spaces inside me
(I don't want to hear these simple answers)
But complicated answers never did you any justice anyway
(But I don't want to hear you lie to me)
Complicated as we are were going have to burn it all away

Tell me now if every single seconds killing
Tell me i'm dreaming
Complicated answers take up all the empty spaces inside me
But complicated answers never did you any justice anyway
Complicated as we are were going to tear out this love
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

int n,x[N],y[N];
int c_minx,c_maxx,c_miny,c_maxy;
int ans[N];

long long dp[5][20][5];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		scanf("%d",&y[i]);
	}

	c_minx=1;
	c_maxx=1;
	c_miny=1;
	c_maxy=1;

	for (int i=1;i<=n;i++){
		if (x[i]<x[c_minx])
			c_minx=i;
		if (x[i]>x[c_maxx])
			c_maxx=i;
		if (y[i]<y[c_miny])
			c_miny=i;
		if (y[i]>y[c_maxy])
			c_maxy=i;
	}

	for (int i=4;i<=n;i++){
		ans[i]=x[c_maxx]-x[c_minx]+y[c_maxy]-y[c_miny];
	}

	for (int mask=0;mask<16;mask++){
		for (int taken=0;taken<=3;taken++){
			dp[0][mask][taken]=-1e18;
		}
	}

	dp[0][0][0]=0;

	for (int i=1;i<=n;i++){

		for (int j=0;j<=16;j++){
			for (int q=0;q<=3;q++){
				dp[i%2][j][q]=dp[1-i%2][j][q];
			}
		}

		for (int already_have=0;already_have<16;already_have++)
		for (int count_taken=0;count_taken<=3;count_taken++){
			for (int take_here=0;take_here<16;take_here++){
				if (already_have&take_here)
					continue;
				if (count_taken==3)
					continue;
				long long new_val=dp[(1-i%2)][already_have][count_taken];
				if (take_here&1)
					new_val+=x[i];
				if (take_here&2)
					new_val-=x[i];
				if (take_here&4)
					new_val+=y[i];
				if (take_here&8)
					new_val-=y[i];
				dp[i%2][already_have|take_here][count_taken+1]=
						max(dp[i%2][already_have|take_here][count_taken+1],new_val);
			}
		}
	}

	ans[3]=dp[n%2][15][3];

	for (int i=3;i<=n;i++){
		if (i>3)
			printf(" ");
		printf("%d",ans[i]*2);
	}
	puts("");

//	cin.get(); cin.get();
	return 0;
}