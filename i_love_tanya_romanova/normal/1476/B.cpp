/*
Slowly crossing
As the river runs below
Never stopping
For what's waiting soon will show

And this last time looking back I'll see my home
For he awaits me reaching for my soul

He calls my name and waves me on
The fallen one he stands in flame

Well the life that he has given
Full of riches and success
Has a price that I made good in blood to pay
And the light he now is showing
To guide my every footstep
Is insurance if I falter on my way

And what God has now forsaken
And man has never seen
Are the riches of the underworld below
All my years of earthly pleasures
Gave support unto the bridge I now cross
It giving him my soul

Dark Lord, I summon thee
Demanding the sacred right to burn in hell
Ride up on hell's hot wind
Face one more evil than thou
Take my lustful soul
Drink my blood as I drink yours
Impale me on the horns of death
Cut off my head
Release all my evil
Lucifer is king
Praise Satan

I know the one who waits
Satan is his name
Across the bridge of death
There he stands in flame
I know the one who waits
Satan is his name
Across the bridge of death
There he stands in flame

He is my provider as I walk into the void
For eternity I'll give to him my soul
I shall do his bidding
Obey him without question
Even walk among the living if I'm told

Satan don't forsake me
I wait for you to take me
Grant me wings and
As your messenger I'll fly
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

const long long bs = 1000000007;

const long long N = 200031;

int tests,n,k;
long long p[N];

bool good(long long ad){
	long long S=p[0]+ad;
	for (int i=1;i<n;i++){
		if (p[i]*100>S*k)
			return false;
		S+=p[i];
	}
	return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>k;
    	for (int i=0;i<n;i++){
    		cin>>p[i];
    	}
    	long long l,r;
    	l=0;
    	r=1e14;
    	while (l<r){
    		long long mid=l+r;
    		mid/=2;
    		if (good(mid))
    			r=mid;
    		else
    			l=mid+1;
    	}
    	cout<<l<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}