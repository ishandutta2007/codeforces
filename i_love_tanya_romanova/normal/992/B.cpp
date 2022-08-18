/*
What a shame
Nothing seems to be going right
What a shame
Nothing seems to be going right
It seems easy to me that everything can be alright
What a shame
They always wanna start a fight
What a shame
They always wanna start a fight
Well it scares me so
I could sleep in the shelter all night
Well alright
What a shame
You all heard what I said
What a shame
Y'all heard what I said
You might wake up in the morning
And find your poor self dead
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

const int N = 1200031;

int l,r,x,y;
vector<int> divs;
int ans;

int gcd(int a,int b){
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}

long long lcm(long long a,long long b){
	long long g=gcd(a,b);
	return a/g*b;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>l>>r>>x>>y;
	for (int i=1;i*i<=y;i++){
		if (y%i)
			continue;
		divs.push_back(i);
		if (y/i!=i)
			divs.push_back(y/i);
	}

	for (int i=0;i<divs.size();i++){
		for (int j=0;j<divs.size();j++){
			int a=divs[i];
			int b=divs[j];
			if (a<l||a>r||b<l||b>r)
				continue;
			if (gcd(a,b)==x&&lcm(a,b)==y)
				++ans;
		}
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}