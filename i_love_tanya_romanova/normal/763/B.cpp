/*
Low and high
Slow motion
We reason at the sound of a big band traveling
In time
Overwhelmed by all we've seen
Wealthy, healthy
Ready...
Above
As below
Surrounding a view
Above as below
The world is unreal...
Sweet
Violence
Rough tenderness
An ode to movement
Endless, uncontrolled

Caresses
Overwhelmed by all we've seen
Overwhelmed by all we've been

Wealthy, healthy
Ready...
Above as below
Surrounding a view
Above as
Below
The world is unreal...
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
const int N = 500031;

int n,x1[N],y1[N],x2[N],y2[N];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
	}

	cout<<"YES"<<endl;
	for (int i=0;i<n;i++)
	{
		int ans=0;
		if (x1[i]%2)
			ans+=1;
		if (y1[i]%2)
			ans+=2;
		cout<<ans+1<<"\n";
	}


	cin.get(); cin.get();
	return 0;
}