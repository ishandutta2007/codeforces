/*
You'll take my life but I'll take yours too
You'll fire your musket but I'll run you through
So when you're waiting for the next attack
You'd better stand, there's no turning back

The Bugle sounds and the charge begins
But on this battlefield no one wins
The smell of acrid smoke and horses breath
As I plunge on into certain death

The horse he sweats with fear, we break to run
The mighty roar of the Russian guns
And as we race towards the human wall
The screams of pain as my comrades fall

We hurdle bodies that lay on the ground
And the Russians fire another round
We get so near yet so far away
We won't live to fight another day

We get so close near enough to fight
When a Russian gets me in his sights
He pulls the trigger and I feel the blow
A burst of rounds take my horse below

And as I lay there gazing at the sky
My body's numb and my throat is dry
And as I lay forgotten and alone
Without a tear I draw my parting groan
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

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;

	if (n<3){
		cout<<"No"<<endl;
		return 0;
	}

	long long S=0;
	for (int i=1;i<=n;i++){
		S+=i;
	}

	int Q=2;
	while (S%Q)
		++Q;

	cout<<"Yes"<<endl;
	cout<<1<<" " <<Q<<endl;
	cout<<n-1;
	for (int i=1;i<=n;i++){
		if (i!=Q)
			cout<<" "<<i;
	}
	cout<<endl;


//	cin.get(); cin.get();
	return 0;
}