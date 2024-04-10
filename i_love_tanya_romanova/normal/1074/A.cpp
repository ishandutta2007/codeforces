/*
Spotlights are roaming
The show will begin
I had never thought
But don't give my circus away
I hope it ends before you know me
I've lost it completely
My faith is lost again I'd say
I'm tired of this place and I want to go
Riding my carousel
They can never tell
I'm spinning and turning
Always revolving
You should have seen it
Where were you?
I needed a stage
To walk all over you
That's better
I'm throwing my three ring away
And I can hear you say
I'm tired of this place
I'm tired of this place and then I think of
Riding my carousel
They can never tell
Close all of the doors
Lock me away
I'm happy I'm here
So let me stay
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

int n,m;
vector<int> vert,bad;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m;

	for (int i=1;i<=n;i++){
		int val;
		cin>>val;
		vert.push_back(val);
	}

	for (int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if (a!=1)
			continue;
		bad.push_back(b);
	}

	sort(vert.begin(),vert.end());

	vert.push_back(1000000000);

	sort(bad.begin(),bad.end());

	//reverse(bad.begin(),bad.end());

	int ans=vert.size()+bad.size();

	int ptr=0;

	for (int i=0;i<vert.size();i++){
		while (ptr<bad.size()&&bad[ptr]<vert[i])
			++ptr;
		ans=min(ans,i+((int)bad.size()-ptr));
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}