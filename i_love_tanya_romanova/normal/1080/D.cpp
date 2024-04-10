/*
I know this is my chosen path
To believe in no one but me
I know this is my chosen path
You've always kept the promise
You've always kept the faith
Well I never will and never had to
I've sinned and sinned
I've sinned and I will again
According to your higher standards
For this I'll go to hell
You hypocrite, you never did
Your truths are lies
Your lies are so pathetic
I'll never give up my soul for you
I've sinned and sinned
I've sinned and I will again
To you I am darkness
To you I have no soul
The smoke from the flames
Will rise up forever
Put my hand in the fire
Put my head in the flames
I can believe
I know it hurts
My skin is melting
I know its real
My skin is melting
And it feels so right
To you I am darkness
To you I have no soul
the smoke from these flames
Will rise up forever
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

const int N = 600031;

long long tests,n,k,ttl,side,rems;

long long safe_mult(long long a,long long b){
	if (a==0||b==0)
		return 0;
	if (2e18/b<=a)
		return 2e18;
	return a*b;
}

long long get_area(long long side){
	if (side>=32)
		return 7e18;
	long long res=(1ll<<(2*side));
	return res;
}

long long moves_from_one(long long side){
	long long area=get_area(side);
	return area/3;
}

long long get_bonus_moves(long long how_many,long long side){
	long long ret=moves_from_one(side);
	ret=safe_mult(ret,how_many);
	return ret;
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
		cin>>n>>k;
		ttl=1;side=n;
		rems=0;
		long long total_moves=0;
		int found=-1;
		while (true){
		//	cout<<side<<" "<<total_moves<<" "<<rems<<" "<<endl;
			if (side==0)
				break;
			long long moves_here=ttl;
			if (moves_here+total_moves>k)
				break;
			total_moves+=moves_here;
			rems+=get_bonus_moves(4*ttl-(2*ttl+1),side-1);
			side--;
			ttl=ttl*2+1;
			if(total_moves+rems>=k){
				found=side;
				break;
			}
		}
		if (found==-1)
			cout<<"NO"<<endl;
		else
			cout<<"YES "<<found<<endl;
	}

//	cin.get(); cin.get();
	return 0;
}