/*
Seek me, call me
I'll be waiting

This distance, this dissolution
I cling to memories while falling
Sleep brings release, and the hope of a new day
Waking the misery of being without you

Surrender, I give in
Another moment is another eternity

(Seek me) For comfort, (Call me) For solace
(I'll be waiting) For the end of my broken heart
(Seek me) Completion, (Call me) I'll be waiting
(I'll be waiting) For the end of my broken heart

You know me, you know me all too well
My only desire - to bridge our division

In sorrow I speak your name
And my voice mirrors my torment

(Seek me) For comfort, (Call me) For solace
(I'll be waiting) For the end of my broken heart
(Seek me) Completion, (Call me) I'll be waiting
(I'll be waiting) For the end of my broken heart

Am I breathing?
My strength fails me
Your picture, a bitter memory

For comfort, for solace
(Seek me) For comfort, (Call me) For solace
(I'll be waiting) For the end of my broken heart
(Seek me) Completion, (Call me) I'll be waiting
(I'll be waiting) For the end of my broken heart
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 998244353

const int N = 1200031;

int n,k,ar[N],ans;

vector<pair<int,int> > v;

vector<pair<int,int> > compress(){
	sort(ar,ar+n);
	int cnt=0;
	vector<pair<int,int> > ret;
	for (int i=0;i<n;i++){
		if (i>0&&ar[i]!=ar[i-1]){
			ret.push_back(make_pair(ar[i-1],cnt));
			cnt=0;
		}
		cnt++;
	}
	ret.push_back(make_pair(ar[n-1],cnt));
	return ret;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>ar[i];
	}

	v=compress();
	n=v.size();

	for (int i=1;i<n;i++){
		if (v[i].first>v[i-1].first+k)
			ans+=v[i-1].second;
	}
	cout<<ans+v[n-1].second<<endl;

//	cin.get(); cin.get();
	return 0;
}