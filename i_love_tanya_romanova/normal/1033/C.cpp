/*
Why don't you get a life and grow up
Why don't you realize that you're fucked up
Why criticize what you don't understand
Why change my words, you're so afraid

You think you have the right to put me down
Propaganda hides your scum
Face to face you don't have a word to say
You got in my way, now you'll have to pay

Don't, don't believe what you see
Don't, don't believe what you read
No!!!

I know my ways, I'm here to stay
I didn't start all this yesterday
I'll prove you wrong all the way
Life teaches me you're always alone

Don't, don't believe what you see
Don't, don't believe what read
No!!!
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

int n,ar[N],win[N],ps[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
		ps[ar[i]]=i;
	}

	for (int i=n;i>=1;--i){
		int whr=ps[i];
		int rem=whr%i;
		for (int j=rem;j<=n;j+=i){
			if (j<1||j>n||j==whr)
				continue;
			if (ar[j]<i)
				continue;
			if (win[j]==0)
				win[whr]=1;
		}
	}

	for (int i=1;i<=n;i++){
		if (win[i])
			cout<<"A";
		else
			cout<<"B";
	}
	cout<<endl;

//	cin.get(); cin.get();
	return 0;
}