/*
The lowest form of life that's crawling in our streets
From seedy dope pushers to the politicians we meet
The sorry religious vomit that infests in our TVs
The weapons that we sell to the trash in the middle east
Murderous drug smugglers pay their way to pass
They look the other way when they take the kickback
We've got to put a stop to this senseless bullshit
Take all these people and throw them in the pit

Let us know - where our tax dollars are spent
Tell us how - how much it costs to repent
Time has come - for us to take a stand
Let us know - when you meet our demands

You can take this all to hell
Shove it up your ass where the sun ain't shining
We know now what it takes to defend
If disaster strikes then they'll be hiding
You can take this all to hell
Shove it up your ass where the sun ain't shining
We know now what it takes to defend
If disaster strikes, then they'll be hiding
Corruption

From laundering money to hookers on the make
There's always a scandal, someone's on the take
They payoff for secrets, sell plans to a spy
They cover their asses and say it's a lie
Society cries when the vermin go free
When they're done, what's left for me?
This social disorder that's causing us pain
Indecent disease, it's they who are to blame
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

const int N = 600000;

long long l1,l2,r1,r2,t1,t2;

long long gcd(long long a,long long b){
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}

long long ans;

long long inter(long long l1,long long r1,long long l2,long long r2){
	l1=max(l1,l2);
	r1=min(r1,r2);
	if (l1>r1)
		return 0;
	return r1-l1+1;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>l1>>r1>>t1;
	cin>>l2>>r2>>t2;

	if ((r1-l1)<(r2-l2)){
		swap(l1,l2);
		swap(r1,r2);
		swap(t1,t2);
	}

	long long Q=gcd(t1,t2);

	long long fi=((l2-l1)%Q+Q)%Q;

	//cout<<fi<<endl;
	ans=inter(0,r1-l1,fi,fi+r2-l2);

	for (int C=-2;C<=2;C++){
		ans=max(ans,inter(0,r1-l1,fi-Q*C,fi+r2-l2-Q*C));
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}