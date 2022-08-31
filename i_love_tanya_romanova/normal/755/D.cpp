/*
First generation born
A plague was created
The cure is in my mind
Solitude is all I see

Powerful nations repress feeling
Buried beneath the fear
Making you a coward
Buying your safety

Grey shadows fill your head
Stealing your last breath
Scared of the future
Prophecies of chaos

Subtraction of personality
Within the human race
You'll always be

Green castles from the past
Bleed in sands of war
No man is immortal
History is no more

Confused leaders behind our backs
Stifling our ideas
Misunderstand signs of progress
Minds of time regress

Searching for an answer
To understand myself
Trying to save our world
While they kill the Universe

Green castles from the past
Bleed in sands of war
No man is immortal
History is no more

Subtraction of personality
The Earth will never
Be born again
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
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 2100031;

int n,k;
long long ans;

long long t[N];

int sum(int r)
{
	int res=0;
	for (;r>=0;r=(r&(r+1))-1)
		res+=t[r];
	return res;
}

void inc(int i,int delta)
{
	for (;i<N;i=(i|(i+1)))
		t[i]+=delta;
}

int sum(int l,int r)
{
	return sum(r)-sum(l-1);
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>k;
	ans=1;

	k=min(k,n-k);

	for (long long iter=1;iter<=n;iter++)
	{
		long long l,r;
		l=(iter-1)*k;
		r=iter*k;
		l%=n;
		r%=n;
		inc(l,1);
		inc(r,1);
		ans++;
		if (l>r)
		{
			if (l+1<n)
				ans+=sum(l+1,n);
			if (r>0)
				ans+=sum(0,r-1);
		}
		else
		{
			ans+=sum(l+1,r-1);
		}
		if (iter>1)
			cout<<" ";
		cout<<ans;
	}

	cout<<endl;

	cin.get(); cin.get();
	return 0;
}