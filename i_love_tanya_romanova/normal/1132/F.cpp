/*
In this life I'm me
Just sitting here alone
By the way I tried to say I'd be there
For you
Walk the silent emptiness
That leads me by my hands
And throw away
What I don't understand, as a man

Love-Hate-Sex-Pain
It's complicating me sometimes
This love-Hate-Sex-Pain
It's underestimated lies

And I wonder as I tear away my skin
It's taken me so long to stitch
These wounds from where I've been
And mother please don't bury me
I'm begging for my life
It's hard to say that I will be complete
Before I die

Love-Hate-Sex-Pain
It's complicating me sometimes
This love-Hate-Sex-Pain
It's underestimated lies

Don't you worry please
Don't you leave me
Because I surely slip away
Through love, hate, sex, and pain
I fall away into
Love, hate sex, and pain

Love-Hate-Sex-Pain
It's complicating me sometimes
This love-Hate-Sex-Pain
It's underestimated lies

Love-Hate-Sex-Pain
It's complicating me sometimes
This love-Hate-Sex-Pain
It's underestimated lies
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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 410031;

string st;
int done[507][506][27];
int memo[506][506][27];

int solve(int l,int r,int fi){
	if (l>r)
	{
		if (fi==0)
			return 0;
		return 1;
	}

	if (done[l][r][fi])
		return memo[l][r][fi];
	done[l][r][fi]=1;
	int ret=1e9;
	if (fi==0){
		memo[l][r][fi]=solve(l+1,r,st[l]-'a'+1);
		return memo[l][r][fi];
	}
	for (int i=l;i<=r;i++){
		if (st[i]-'a'+1==fi){
			int here=solve(l,i-1,0)+solve(i+1,r,fi);
			ret=min(ret,here);
		}
	}

	if (fi!=0){
		ret=min(ret,solve(l,r,0)+1);
	}
	memo[l][r][fi]=ret;
	return ret;
}

int n;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    cin>>st;

    cout<<solve(0,n-1,0)<<endl;

//    cin.get(); cin.get();
    return 0;
}