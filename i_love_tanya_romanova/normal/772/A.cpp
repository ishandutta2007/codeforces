/*
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

#define eps 1e-15
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n;
double p;
int a[N],b[N];

bool check(long double val)
{
	double need_charge=0;

	for (int i=1;i<=n;i++)
	{
		double total_used=a[i]*val;
		if (total_used>b[i])
			need_charge+=total_used-b[i];
	}

	long double can_charge=val*p;

	return (can_charge>=need_charge-eps);
}


int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>p;

	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}

	long double l,r;
	l=0;
	r=1e15;

	for (int iter=1;iter<=100;iter++)
	{
		double mid=l+r;
		mid/=2;
		if (check(mid))
			l=mid;
		else
			r=mid;
	}

	if (l>1e14)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout.precision(15);
		cout<<fixed<<l<<endl;
	}

	cin.get(); cin.get();
	return 0;
}