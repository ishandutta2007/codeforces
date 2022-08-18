/*
There's a black hill
We had a climb
Everything I need but nothing's mine
Satan's world, I've had a kill
Why didn't Rosemary ever take the pill?
Lying there waiting, waiting for the kill
Oh man won't do it, but the devil will

I'm losing time and my mind
Why can't I ever have what's naturally mine?
I got life and the things that go with it
If there's something else, where can i get it?
Lying there waiting, waiting for the kill
Oh man won't do it, but the devil will

Well here's my views, I always lose
Things I want to do are yesterday's news
Say life's a ball, I've had it all
Out there in another dance hall
Lying there waiting, waiting for the kill
Oh man won't do it, but the devil will

Take me as I am, an excuse for a man
Wherever I push someone stops my hand
As a matter of interest, tell me if you will
Why didn't Rosemary ever take the pill?
Lying there waiting, waiting for the kill
Oh man won't do it, but the devil will

Oh, why won't Rosemary ever take the pill?
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

int n,t[N];
vector<pair<int,int> > events;
int ans;
int T;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>T;
	for (int i=1;i<=n;i++){
		cin>>t[i];
		if (t[i]>=T)
			continue;

		int min_delay=t[i]-i;
		if (min_delay<0)
			min_delay=0;
		int max_delay=T-i;

		if (max_delay<min_delay)
			continue;

		events.push_back(make_pair(min_delay,1));
		events.push_back(make_pair(max_delay,-1));
	}

	sort(events.begin(),events.end());

	int cur=0;
	for (int i=0;i<events.size();i++)
	{
		cur+=events[i].second;
		ans=max(ans,cur);
	}
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}