/*
In and out
Try to be
What you see
Anarchy
Everything, everyone, everyman
Rebellion
But you can't make a move

If you win then you lose
Look at me to approve
You're so hard, you're so real
You got nothing

Who laughs last?
A question, not a task
I ask,
What's your reason,
Do you believe in anything?

I don't wanna how you're so driven
I don't wanna know your influence
I don't need to prove myself
I just need to be myself
It doesn't show how I'm trying to be
It just shows who I am

Gone,
Take your packaged rebellion
Move on,
Revolution on your sleeve
If you say, mean it
If you mean it, do it
You can't live your life through me
Gone,
Take your packaged Rebellion
With the air you breathe

Look around
No one cares
Who you are
Why or where
You're so blind, you're so dumb, you're so deaf
Like a gun
That you can't even shoot
To the point that is moot
And you don't have a clue
You're so hard, you're so real
You got nothing

Who laughs last?
A question, not a task
I ask,
What's your reason,
Do you believe in anything?

I don't wanna hear how you're so driven
I don't wanna know your influence
I don't need to prove myself
I just need to be myself
It doesn't show who I am trying to be
It just shows who I am

Gone,
Take your packaged rebellion
Move on,
Revolution on your sleeve
If you say it, mean it
If you mean it, do it
You can't live your life through me
If you do it, live it
If you live it, say it
Action is the air you breathe

I saw your act, it came and went
As flaccid as an ex-president
Your ideas are out of place
It's anarchy with a friendly face
Rebel, rebel, don't regret
Screw 'em every chance you get
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

int n;
vector<int> v;

long long a,b,x,y;
long long gcd(long long a,long long b){
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>a>>b>>x>>y;
	long long Q=gcd(x,y);
	x/=Q;y/=Q;

	long long res=min(a/x,b/y);
	cout<<res<<endl;

//	cin.get(); cin.get();
	return 0;
}