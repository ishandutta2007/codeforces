/*
Let me tell you about the loss of all
The failing of all that we hold dear
Wrapped up nicely in ourselves

Chaos resolves
Which order defiles
Worthless lives
Are ordered
Are ordered blind

I don't believe
I don't believe
Taste and you will see
That all belongs to me
I don't believe
I won't believe

Oh!

I raise my hand against it all
For those who don't recognize the call
Will the sense to overcome these nestled walls
Gonna break
Gonna break
Gonna break it down

I don't believe
I don't believe
Taste and you will see
That all belongs to me
I don't believe
I won't believe

Let me nail you to the treason wall
Stab the night and the day from your sight
And set the thought to flame

Feeble devout
Nothing resides
Break it to pieces
That obstinate mind

I raise my fist to hold the line
Against those who set themselves on high
Gonna break
Gonna break
Gonna break it down

I don't believe
I don't believe
Taste and you will see
That all belongs to me
I don't believe
I won't believe
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

const int N = 400031;

const int LOT = 1600031;

void solve_good(int n){
	for (int i=1;i<n;i++){
		cout<<i<<" "<<i+1<<endl;
	}
}

void solve_bad(int n){
	if (n<6)// ?
	{
		cout<<-1<<endl;
		return ;
	}
	cout<<1<<" "<<2<<endl;
	cout<<1<<" "<<3<<endl;
	cout<<1<<" "<<4<<endl;
	cout<<2<<" "<<5<<endl;
	cout<<2<<" "<<6<<endl;
	for (int i=7;i<=n;i++){
		cout<<1<<" "<<i<<endl;
	}
}

int n;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;
	solve_bad(n);
	solve_good(n);

//	cin.get(); cin.get();
	return 0;
}