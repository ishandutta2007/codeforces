/*
No blood no glory
All pain and fury
A demonstration
Of domination
Show of pure intimidation

Full contact why I live and breathe
Side stepping all the human debris
Head strong I know that I'll prevail
Face down in my arena you will fail
Head to head eye to eye
Human pile of proven pride
Ripping flesh spitting teeth
Sacrifice for victory
Base line Goal line
Overtime Killing time
Relentless brotherhood of discipline
Centuries of tradition is to win
Head first into battle feel the rush
Living on adrenaline your try is crushed

No blood No glory
All pain And fury
Head to head eye to eye
Human pile of proven pride
Ripping flesh spitting teeth
Sacrifice for victory
Base line Goal line
Overtime Killing time
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007

#define bsize 256

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 1200031;

int n;
double x[N],v[N];

double eval(double p)
{
	double res=0;
	for (int i=0;i<n;i++){
		double D=fabs(p-x[i]);
		D/=v[i];
		res=max(res,D);
	}
	return res;
}

int main(){
	//freopen("cinema.in","r",stdin);
	//freopen("cinema.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}

	double l,r;
	l=0;
	r=1e9;
	for (int iter=1;iter<=120;iter++)
	{
		double mid1=l*2+r;
		double mid2=l+r*2;
		mid1/=3;
		mid2/=3;
		double score1=eval(mid1);
		double score2=eval(mid2);
		if (score1<score2)
			r=mid2;
		else
			l=mid1;
	}

	cout.precision(10);
	cout<<fixed<<eval(l)<<endl;

	cin.get(); cin.get();
	return 0;
}