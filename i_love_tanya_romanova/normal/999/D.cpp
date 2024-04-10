/*
I don't wanna die alone
I don't wanna live forsaken
I refuse to let this go
Because my soul is breaking

I don't wanna let you know
That my heart is just so jaded
I refuse to let it show
I refuse to let it go

Wake me up when this is over
I'm tired of living life like its a dream
Please wake me up when its all over
I'm tired of living right here in between
I refuse

I've always walked alone
I chose the path less taken
I refuse to let you win
Life's a bitch and I've been shaken

Its not a joke at all
Inside my spirit's fading
I refuse to take the fall
Cause no one cares at all

Wake me up when this is over
I'm tired of living life like its a dream
Please wake me up when its all over
I'm tired of living right here in between
I refuse

Cause at the end of the day I'm not you
I refuse

Wake me up when this is over
I'm tired of living life like its a dream
Please wake me up when its all over
I'm tired of living right here in between
Wake me up when this is over
I'm tired of living life like its a dream
Please wake me up when its all over
I'm tired of living right here in between

I refuse
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

int n,m,ar[N];
vector<int> entries[N];
int cnt_rem[N];
multiset<int> f;
multiset<int>::iterator it;
long long ans;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
		cnt_rem[ar[i]%m]++;
		entries[ar[i]%m].push_back(i);
	}

	int per_one=n/m;
	for (int i=0;i<m;i++){
		if (cnt_rem[i]<per_one){
			for (int j=cnt_rem[i]+1;j<=per_one;j++)
				f.insert(i);
		}
	}

	for (int i=1;i<=n;i++){
		if (cnt_rem[ar[i]%m]>per_one){
			--cnt_rem[ar[i]%m];
			int q=ar[i]%m;
			it=f.lower_bound(q);
			if (it==f.end())
				it=f.begin();
			int val=(*it);
			f.erase(it);
			int full=ar[i]/m;
			if (val<ar[i]%m){
				full++;
			}
			int here=val-ar[i]%m;
			if (here<0)
				here+=m;
			ans+=here;
			ar[i]=m*full+val;
		}
	}

	cout<<ans<<endl;

	for (int i=1;i<=n;i++){
		if (i>1)
			cout<<" ";
		cout<<ar[i];
	}
	cout<<endl;

//	cin.get(); cin.get();
	return 0;
}