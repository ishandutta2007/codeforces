/*
It's the nature of time
That the old ways must give in
It's the nature of time
That the new ways comes in sin
When the new meets the old
It always ends the ancient ways
And as history told
The old ways go out in a blaze

Encircled by a vulture
The end of ancient culture
The dawn of destiny draws near

Imperial force defied
Facing 500 samurai
Surrounded and outnumbered
60 to 1 the sword face the gun
Bushido dignified
It's the last stand of the samurai
Surrounded and outnumbered

As a new age begins
The way of the warrior comes to an end
As a new age begins
The ways of the old must apprehend
It's the nature of time
That the old ways must give in
It's the nature of time
That the new ways comes in sin

An offer of surrender
Saigo ignore contender
The dawn of destiny is here

Imperial force defied
Facing 500 samurai
Surrounded and outnumbered
60 to 1 the sword face the gun
Bushido dignified
It's the last stand of the samurai
Surrounded and outnumbered

Until the dawn they hold on
Only 40 are left at the end
None alive, none survive
Shiroyama

Imperial force defied
Facing 500 samurai
Surrounded and outnumbered
60 to 1 the sword face the gun
Bushido dignified
It's the last stand of the samurai
Surrounded and outnumbered
60 to 1, facing the gun
60 to 1, culture undone
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
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007
const int N = 500031;

int n,k;

int s;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>k;

	int ans=-1;

	for (int i=1;i<=n;i++)
	{
		int val;
		cin>>val;
		s+=val;
		int give=min(s,8);
		k-=give;
		s-=give;
		if (k<=0)
		{
			ans=i;
			break;
		}
	}

	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}