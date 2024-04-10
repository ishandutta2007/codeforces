/*
Why do they not believe
I have not lied, even for this,
Now no-one can conceive
The lie becomes the loving kiss,
But I would not,
Fall in love,
Like this.

The woman stiches the shrouds,
The children murder all the world,
If only you believe,
Then only you will die,
How can you not,
See the stars,
In your eyes.

Sacrifice, sacrifice, sacrifice, sacrifice,
Sacrifice, pay the price, blood like ice, sacrifice.

The pain is on you now,
Do not consider flight for gain,
In you the poison breeds,
Crawling with the mark of Cain,
And no-one shall,
Set you free,
Again.

Sacrifice, sacrifice, sacrifice, sacrifice,
Sacrifice, sacrifice, sacrifice, sacrifice.
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

const int bs = 1000000007;

const int N = 600031;

long long k,l,r,t,x,y;

set<long long> done;

bool simulate(long long k,long long t){
	if (k<l||k>r)
		return false;
	if (done.find(k)!=done.end())
		return true;
	done.insert(k);
	if (t<=0)
		return true;
	if (y<x){ // the number will go down by x-y per day
		if (k+y>r)
			return simulate(k-x,t-1);
		long long lowr_bound=l+x;
		if (k<lowr_bound)
			return simulate(k+y-x,t-1);
		long long skip_days=(k-lowr_bound)/(x-y)+1;
		return simulate(k-skip_days*(x-y),t-skip_days);
	}
	// we can increase it, we just need to be careful
	long long lowr_bound=l+x;
	if (k<lowr_bound){
		if (k+y>r)
			return false;
		return simulate(k+y-x,t-1);
	}
	else
	{
		long long skip_days=(k-lowr_bound)/x+1;
		return simulate(k-skip_days*x,t-skip_days);
	}
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>k>>l>>r>>t>>x>>y;

    int ok = simulate(k,t);

    if (ok){
    	cout<<"Yes"<<endl;
    }
    else
    {
    	cout<<"No"<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}