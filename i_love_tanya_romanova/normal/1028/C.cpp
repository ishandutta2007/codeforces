/*
Momma loves her baby
And Daddy loves you too
And the sea may look warm to you, babe
And the sky may look blue

Ooh, babe
Ooh, baby blue
Ooh, babe

If you should go skating
On the thin ice of modern life
Dragging behind you the silent reproach
Of a million tear-stained eyes

Don't be surprised,
When a crack in the ice
Appears under your feet
You slip out of your depth and out of your mind
With your fear flowing out behind you
As you claw the thin ice
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

int n,x1[N],y1[N],x2[N],y2[N],prefx1[N],prefx2[N],prefy1[N],prefy2[N],
sufx1[N],sufx2[N],sufy1[N],sufy2[N];

int ansx,ansy;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
	}

	prefx1[1]=x1[1];
	prefx2[1]=x2[1];
	prefy1[1]=y1[1];
	prefy2[1]=y2[1];

	sufx1[n]=x1[n];
	sufx2[n]=x2[n];
	sufy1[n]=y1[n];
	sufy2[n]=y2[n];

	for (int i=2;i<=n;i++){
		prefx1[i]=max(prefx1[i-1],x1[i]);
		prefx2[i]=min(prefx2[i-1],x2[i]);
		prefy1[i]=max(prefy1[i-1],y1[i]);
		prefy2[i]=min(prefy2[i-1],y2[i]);
	}

	for (int i=n-1;i>=1;--i){
		sufx1[i]=max(sufx1[i+1],x1[i]);
		sufx2[i]=min(sufx2[i+1],x2[i]);
		sufy1[i]=max(sufy1[i+1],y1[i]);
		sufy2[i]=min(sufy2[i+1],y2[i]);
	}

	for (int i=1;i<=n;i++){
		int x1here=-1e9;
		if (i>1)
			x1here=max(x1here,prefx1[i-1]);
		if (i<n)
			x1here=max(x1here,sufx1[i+1]);

		int x2here=1e9;
		if (i>1)
			x2here=min(x2here,prefx2[i-1]);
		if (i<n)
			x2here=min(x2here,sufx2[i+1]);

		int y1here=-1e9;
		if (i>1)
			y1here=max(y1here,prefy1[i-1]);
		if (i<n)
			y1here=max(y1here,sufy1[i+1]);

		int y2here=1e9;
		if (i>1)
			y2here=min(y2here,prefy2[i-1]);
		if (i<n)
			y2here=min(y2here,sufy2[i+1]);

		//cout<<x1here<<" "<<x2here<<" "<<y1here<<" "<<y2here<<endl;

		if (x1here<=x2here&&y1here<=y2here){
			ansx=x1here;
			ansy=y1here;
		}
	}

	cout<<ansx<<" "<<ansy<<endl;

//	cin.get(); cin.get();
	return 0;
}