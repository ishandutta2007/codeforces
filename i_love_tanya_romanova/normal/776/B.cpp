/*
In a land where no love can be born
Self destruction everywhere
A restless soul on it's search for an answer
Sees through this masquerade of dispair
In a time where no love can be born
Desperation frozen eyes
A restless soul so alone no direction
Suffering as they follow the blind

This is a new dawn rising
Over this Shadowland
Tearing you from the world that you used to know

In a land where no love can be born
Isolation is the price
And the horror of this cold souless place here
Put everlasting stains on your life
In a time where no love can be born
Another crisis yet to come
A senseless life breeds a senseless death
Wondering what kind of pain will come next

Tired of being alive losing every time
Suffering side by side shadows of mankind
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 111031;

int pr[N],n;

int main(){
//	freopen("explosion.in","r",stdin);
//	freopen("explosion.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	pr[1]=1;
	for (int i=2;i<N;i++)
	{
		if (pr[i]==0)
		{
			for (int j=i*2;j<N;j+=i)
				pr[j]=1;
		}
	}
	cin>>n;

	if (n<3)
	{
		cout<<1<<endl;
		for (int i=1;i<=n;i++)
		{
			if (i>1)
				cout<<" ";
			cout<<1;
		}
		cout<<endl;
	}
	else
	{
		cout<<2<<endl;
		for (int i=1;i<=n;i++)
		{
			if (i>1)
				cout<<" ";
			if (pr[i+1])
				cout<<2;
			else
				cout<<1;
		}
		cout<<endl;
	}

	cin.get(); cin.get();
	return 0;
}