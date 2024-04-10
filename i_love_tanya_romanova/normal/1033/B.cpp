/*
Walking these dirty streets
With hate in my mind
Feeling the scorn of the world
I won't follow your rules
Blame and lies, Contradictions arise
Blame and lies, Contradictions arise
Nonconformity in my inner self
I won't change my way
It has to be this way
I live my life for myself
Forget your filthy ways
Blame and lies, Contradictions arise
Blame and lies, Contradictions arise
Nobody will change my way
Life betrays, but I keep going
There's no light, but there's hope
Crushing oppression, I win
Betraying and playing dirty, you think
You'll win
But someday you'll fall, and I'll be waiting
Laughs of an insane man, you'll hear
Personality is my weapon against your envy
Walking these dirty streets
With hate in my mind
Feeling the scorn of the world
I won't follow your rules
Nonconformity in my inner self
Only I guide my inner self
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

long long tests;

bool is_prime(long long x){
	for (long long i=2;i*i<=x;i++){
		if (x%i==0)
			return false;
	}
	return true;
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
		long long a,b;
		cin>>a>>b;
		// a^2-b^2=(a-b)*(a+b);

		if (a-b==1&&is_prime(a+b))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}

//	cin.get(); cin.get();
	return 0;
}