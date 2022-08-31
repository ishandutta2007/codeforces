/*
You, who brought the sunshine to my eyes
You, who wondered through my sad disguise
And I have a love that can not die... for you

High Priestess of my heart
Tell me that we won't part

Then let's get together in the sky
To leave the lonely world to wonder why
For we have a love that cannot die... so true

High priestess of my heart
Tell me that we won't part
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

long long n,L,R;

map<long long, long long> memo;

void calc_len(long long val)
{
	if (val==0||val==1)
	{
		memo[val]=1;
		return ;
	}
	long long p=val/2;
	calc_len(p);
	memo[val]=memo[p]*2+1;
}

long long ans;

bool intersect(long long l1,long long r1,long long l2,long long r2)
{
	return max(l1,l2)<=min(r1,r2);
}

void solve(long long val,long long l,long long r)
{
	if (!intersect(l,r,L,R))
		return;
	if (val==1)
	{
		++ans;
	}
	if (val<2)
		return;
	long long p=val/2;
	long long Q=memo[p];
	solve(p,l,l+Q-1);
	solve(val%2,l+Q,l+Q);
	solve(p,l+Q+1,r);
}

int main(){
//	freopen("japanese.in","r",stdin);
//	freopen("japanese.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>L>>R;

	calc_len(n);

	solve(n,1,memo[n]);

	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}