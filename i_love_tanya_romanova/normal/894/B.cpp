/*
I want to break free
I want to break free
I want to break free from your lies
You're so self satisfied I don't need you
I've got to break free
God knows, God knows I want to break free.

I've fallen in love
I've fallen in love for the first time

And this time I know it's for real
I've fallen in love, yeah
God knows, God knows I've fallen in love.

It's strange but it's true
I can't get over the way you love me like you do
But I have to be sure
When I walk out that door
Oh how I want to be free, baby
Oh how I want to be free,
Oh how I want to break free.

But life still goes on
I can't get used to, living without, living without,
Living without you by my side
I don't want to live alone, hey
God knows, got to make it on my own
So baby can't you see
I've got to break free.

I've got to break free
I want to break free, yeah
I want, I want, I want, I want to break free.
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 300031;

long long n,m,k;

long long pw(long long a,long long b){
	if (b==0)
		return 1;
	if (b%2)
		return a*pw(a,b-1)%bs;
	return pw(a*a%bs,b/2);
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m>>k;

	if (k==-1)
		k=1;
	else
		k=0;

	long long p1=n*k%2;
	long long p2=m*k%2;

	if (p1!=p2){
		cout<<0<<endl;
		return 0;
	}

	long long F=(n-1)%(bs-1)*((m-1)%(bs-1));

	long long res=pw(2,F);
	cout<<res<<endl;

//	cin.get(); cin.get();
	return 0;
}