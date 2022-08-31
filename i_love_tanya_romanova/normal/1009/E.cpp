/*
Make enemies of truth and reason
in that a rage is born
start out a promise and a venture
where direction was never the goal

How does it feel to run out of nothing?
Where do you go when you run out?

Never you mind the grand perspective
other forces kept at bay
as you narrow the field of vision
to retain a sense of control
Your focus will remain unfixed
in the haze of a world unhinged

Create a sense of purpose
around which you base your faith
the doubt that haunts your skin
an itch that will linger on forever

How does it feel to run out of nothing?
Where do you go when you run out?

You wave off critique as an offender
never question where your motives lie
as a part of the greatest fable
the beast all had forgotten
instincts in a dead end rampage
destruction as a saving grace

You run out of nothing
How does it feel?
to run out of nothing
Where do you go?
When you run out
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

#define bs 998244353

const int N = 1000031;

long long n,ar[N],p[N],ans;
long long ways;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
	}

	for (int i=n;i>1;--i){
		ar[i]-=ar[i-1];
	}

	p[0]=1;
	for (int i=1;i<=n;i++)
	{
		p[i]=p[i-1]*2;
		p[i]%=bs;
	}

	for (int i=1;i<=n;i++){
		ans%=bs;
		ways+=p[n-i]*ar[i];
		ways%=bs;
		ans+=ways;
		ans%=bs;
	}
	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}