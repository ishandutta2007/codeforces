/*
The world today is such a wicked place
Fighting going on between the human race
People got to work just to earn their bread
While people just across the sea are counting their dead

A politician's job, they say, is very high
For he has to choose who's got to go and die
They can put a man on the moon quite easy
While people here on earth are dying of old diseases

A woman goes to work every day after day
She just goes to work just to earn her pay
Child sitting crying by a life that's harder
He doesn't even know who is his father
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

const int N = 200031;

long long tests,n,x,y,d,ans;

long long solver(long long a,long long b){
	if (abs(a-b)%d)
		return 4e9;
	return abs(a-b)/d;
}

long long solver2(long long a,long long b){
	return abs(a-b)/d+(abs(a-b)%d>0);
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>tests;
	for (;tests;--tests){
		cin>>n>>x>>y>>d;
		ans=3e9;
		ans=min(ans,solver(x,y));
		ans=min(ans,solver2(x,1)+solver(1,y));
		ans=min(ans,solver2(x,n)+solver(n,y));
		if (ans>2e9)
			ans=-1;
		cout<<ans<<endl;
	}
//	cin.get(); cin.get();
	return 0;
}