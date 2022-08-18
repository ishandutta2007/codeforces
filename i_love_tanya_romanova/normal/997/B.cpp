/*
Night has fallen
And the darkness hides an evil one
Feel his presence
Ever lurking in the shadows there
You can't see him but he's near

Prowling danger
Gazing unseen through his blackened cloak
Features masked
He's poised to take your life
Cutting deep your flesh
His steely knife
Coldly steals your life

The kiss of death

Daylight dawning
A fallen victim waiting to be found
Badly bleeding
Screaming sirens, people gather round
It's too late to run in fear

The kiss of death
Death is near
The kiss of death
Shed a tear
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

int n;
int dp[N];
queue<int> qu;

long long ans;

void update(int a,int b){
	b%=49;
	if (dp[b]<=dp[a]+1)
		return ;
	dp[b]=dp[a]+1;
	qu.push(b);
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;

	for (int i=0;i<=50;i++){
		dp[i]=1e9;
	}
	dp[0]=0;
	qu.push(0);
	while (qu.size()){
		int v=qu.front();
		qu.pop();
		update(v,v+4);
		update(v,v+9);
		update(v,v+49);
	}

	for (int rem=0;rem<49;rem++){
		int here=dp[rem];
		if(here>n)
			continue;
		ans+=n-here+1;
	}
	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}