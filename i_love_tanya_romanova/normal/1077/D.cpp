/*
Blank stares from broken men
So withered from the poisons they can't remember when
There were once honest reasons.
It's all a lie, it died 100,000 miles ago.
Pretending I'm still here.
Justify what I've become, sanctify what I've become.
Amazing disgrace... (how) sweet the sound that saved a wretch like me.
Better lost if this is found, best blinded never to see.
The race to save face, nothing now is what we meant it to be.
Pretending I'm still here.
It's a system now, intertwined.
Take your place in the line to be ground by the gears of the masterpiece.
Betrayal.
Suffered consequence
It's been so long since any piece of this made any kind of sense.
You anoint the king, I'll burn everything down to ashes.
You giveth, I taketh away.
It's a system now, intertwined.
Take your place in the line to be ground by the gears of the masterpiece.
Betrayal.
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

const int N = 300031;

int n,k,cnt[N],ar[N];
vector<int> ans;

bool can(int am){
	int C=0;
	for (int i=1;i<=200000;i++){
		C+=cnt[i]/am;
	}
	return (C>=k);
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>k;

	for (int i=1;i<=n;i++){
		cin>>ar[i];
		cnt[ar[i]]++;
	}

	int l,r;
	l=1;
	r=n;
	while (l<r){
		int mid=l+r+1;
		mid/=2;
		if (can(mid))
			l=mid;
		else
			r=mid-1;
	}

	for (int i=1;i<=200000;i++){
		for (int j=1;j<=cnt[i]/r;j++){
			if (ans.size()<k)
				ans.push_back(i);
		}
	}

	for (int i=0;i<ans.size();i++){
		if (i)
			cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;

//	cin.get(); cin.get();
	return 0;
}