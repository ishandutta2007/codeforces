/*
Engines are running our blood burns like oil. Head one by
One down the highway
Tires are screaming leave trails on the road, the sirens of
Death coming our way

Well always be one step ahead, well not fall back

Pedal to metal rock hard and ride free, the philosophy of a
Rider
Dont use the brakes ride on faster instead, adrenaline
Taking you higher

Fall back in line or stand away, we like it fast

Into hell we ride fast as lightning, enter the darkness
The weak ones will pay
Ride through fire cause revolution, this is a hellriders way

Crushing the traitors to no man we kneel, the power is at
Our command
Nothing can stop us its head over heel, united together
We stand

If its to hard then youre too weak, youre in our way

Engines are running our blood burns like oil. Head one by
One down the highway
Tires are screaming leave trails on the road, the sirens of
Death heading our way

If you aint tough enough to play, get out our way
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
const int N = 200031;

long long tests,x,y,p,q;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>tests;
	for (;tests;--tests)
	{
		cin>>x>>y>>p>>q;
		// 1, have not 1
		if (p==1&&q==1&&x<y)
		{
			cout<<-1<<endl;
			continue;
		}
		// 0, have not 0
		if (p==0&&q==1&&x>0)
		{
			cout<<-1<<endl;
			continue;
		}

		if (p==0&&q==1)
		{
			cout<<0<<endl;
			continue;
		}
		if (p==1&&q==1)
		{
			cout<<0<<endl;
			continue;
		}

		// now none of two is 0.0 or 1.0

		long long min_times_to_have_enough_AC=x/p+(x%p>0);
		long long min_times_to_have_enough_WA=(y-x)/(q-p)+((y-x)%(q-p)>0);
		long long min_times_total=max(min_times_to_have_enough_AC,min_times_to_have_enough_WA);
		long long res=q*min_times_total-y;
		cout<<res<<endl;

	}

	cin.get(); cin.get();
	return 0;
}