/*
When the missiles are falling, and the reaper comes calling
You had better kiss your ass goodbye
Atomic detonation, mass immolation
Without a warning, all your memories will die
So try to relax, face up to the facts
You'll either die or the fallout will rot you in your tracks
There'll be no tomorrow, only pain and sorrow
'Cause our futures in the hands of a raving madman

They spend all their time building missiles so people die
What kind of life do you expect for us to live?
We're angered by fear, because the time is near
When some lunatic will finally pull the plug
And forever after, you can hear the laughter
World's being plastered by an evil bastard
Exterminating faster, devastating plaster
Fabulous disaster
Now you can see, what this all means to me
When the bomb
Comes falling
Down

Now the reaper has called, but do you have the balls
To sit there or stand up and fight?
Try to make a note, it's your right to vote
To keep these fucking assholes in line
It will always be the same 'cause they lie in their campaigns
Promise through their teeth for total world peace
So we know it's not the truth, they should call Dr.Ruth
On how to give the people the real big screw

They spend all their time building missiles so people die
What kind of life do you expect for us to live?
We're angered by fear, because the time is near
When some lunatic will finally pull the plug
And forever after, you can hear the laughter
World's being plastered by an evil bastard
Exterminating faster, devastating plaster
Fabulous disaster
Now you can see, what this all means to me
When the bomb
Comes falling
Fall Down
*/

//#pragma GCC optimize("O3")
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 300031;

int n,R;
int F[N],S[N],P[N];

double dp[66][11555];

double solve(double ans){
	for (int id=n+1;id>=1;--id){
		for (int j=0;j<=10000;j++){
			if (id==n+1){
				if (j<=R)
					dp[id][j]=0;
				else
					dp[id][j]=ans;
				continue;
			}
			double val_fast=min(ans,dp[id+1][j+F[id]])+F[id];;
			double val_slow=min(ans,dp[id+1][j+S[id]])+S[id];
			double ev_here=val_fast*(1.0*P[id]/100)+val_slow*(1.0-1.0*P[id]/100);
			dp[id][j]=ev_here;
		}
	}
	return dp[1][0];
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>R;
	for (int i=1;i<=n;i++){
		cin>>F[i]>>S[i]>>P[i];
	}

	/*for (double t=300;t<=320;t+=0.1){
		cout<<t<<" "<<solve(t)<<endl;
	}*/

	double l,r;
	l=0;
	r=1e9;
	for (int iter=1;iter<=74;iter++)
	{
		double mid=l+r;
		mid/=2;
		double here=solve(mid);
		if (here<mid)
			r=mid;
		else
			l=mid;
	}

	cout.precision(12);
	cout<<fixed<<l<<endl;

	cin.get(); cin.get();
	return 0;
}