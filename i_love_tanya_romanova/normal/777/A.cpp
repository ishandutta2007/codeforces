/*
One day the shadows will surround me
Someday the days will come to end
Sometime I'll have to face the real me
Somehow I'll have to learn to bend
And now I see clearly

All these times I simply stepped aside
I watched but never really listened
As the whole world passed me by
All this time I watched from the outside
Never understood what was wrong or what was right
I apologize, whoah
I apologize, whoah

One day I'll face the Hell inside me
Someday I'll accept what I have done
Sometime I'll leave the past behind me
For now I accept who I've become
And now I see clearly

All these times I simply stepped aside
I watched but never really listened
As the whole world passed me by
All this time I watched from the outside
Never understood what was wrong or what was right
I apologize
I apologize

One day the shadows will surround me

All these times I simply stepped aside
I watched but never really listened
As the whole world passed me by
All this time I watched from the outside
Never understood what was wrong or what was right
I apologize
I apologize

Whoah, I apologize
Whoah, I apologize
Whoah, I apologize
Whoah, I apologize
I apologize
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

vector<int> v;

int main(){
//	freopen("explosion.in","r",stdin);
//	freopen("explosion.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	/*for (int i=0;i<3;i++)
	{
		v.push_back(i);
	}
	for (int iter=0;iter<20;iter++)
	{
		cout<<iter<<": ";
		if (iter%2==0)
			swap(v[0],v[1]);
		else
			swap(v[2],v[1]);
		for (int j=0;j<3;j++)
		{
			cout<<v[j]<<" ";
		}
		cout<<endl;
	}
*/

	int n,x;

	cin>>n>>x;
	v.resize(3);
	for (int i=0;i<3;i++){
		if (i==x)
			v[i]=1;
		else
			v[i]=0;
	}
	if (n>100)
		n=60+n%6;

	while (n>0)
	{
		if (n%2==1)
			swap(v[0],v[1]);
		else
			swap(v[1],v[2]);
		--n;
	}

	int ans=0;
	for (int i=0;i<v.size();i++)
	{
		if (v[i]==1)
			ans=i;
	}
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}