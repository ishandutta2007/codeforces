/*
There's no time for us.
There's no place for us.
What is this thing that builds our dreams, yet slips away from us?

Who wants to live forever?
Who wants to live forever?
There's no chance for us.
It's all decided for us.
This world has only one sweet moment set aside for us.

Who wants to live forever?
Who wants to live forever?

Who dares to love forever
When love must die?

But touch my tears with your lips,
Touch my world with your fingertips,

And we can have forever,
And we can love forever.
Forever is our today.

Who wants to live forever?
Who wants to live forever?
Forever is our today.

Who waits forever anyway?
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

set<int> S;
int ar[N];
int n;

int gcd(int a,int b){
	while(a&&b)a>b?a%=b:b%=a;
	return a+b;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=0;i<n;i++){
		cin>>ar[i];
	}

	for (int i=1;i<n;i++){
		if (ar[i]%ar[0]){
			cout<<-1<<endl;
			return 0;
		}
	}

	cout<<n*2<<endl;
	for (int i=0;i<n;i++){
		cout<<ar[0]<<" "<<ar[i]<<" ";
	}
	cout<<endl;

//	cin.get(); cin.get();
	return 0;
}