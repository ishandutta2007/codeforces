/*
In the beginning there was silence and darkness
All across the earth
Then came the wind and a hole in the sky
Thunder and lightning came crashing down
Hit the earth and split the ground
Fire burned high in the sky

From down below fire melted the stone
The ground shook and started to pound

The gods made heavy metal and they saw that is was good
They said to play it louder than Hell
We promised that we would
When losers say it's over with you know that it's a lie
The gods made heavy metal and it's never gonna die

We are the true believers
It's our turn to show the world
In the fire of heavy metal we were burned
It's more than our religion it's the only way to live
But the enemies of metal we can't forgive

Cause we believe in the power and the might
And the gods who made metal are with us tonight

The gods made heavy metal and they saw that is was good
They said to play it louder than Hell
We promised that we would
When losers say it's over with you know that it's a lie
The gods made heavy metal and it's never gonna die

We believe in the power and the might
And the gods who made metal are with us tonight

We're here tonight for heavy metal are you ready in the hall
They have chosen us and we have heard the call
Gonna tear the roof off with our sound

Crack the walls and shake the ground
Fight tonight for metal one and all

Cause we believe in the power and the might
And the gods who made metal are with us tonight

The gods made heavy metal and they saw that is was good
They said to play it louder than Hell
We promised that we would
When losers say it's over with you know that it's a lie
The gods made heavy metal and it's never gonna die
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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 610031;

int n,h,ar[N];

long long f(vector<int> v){
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	long long ans=0;
	for (int i=0;i<v.size();i+=2){
		ans+=v[i];
	}
	return ans;
}
bool solve(int cnt){
	vector<int> v;
	for (int i=1;i<=cnt;i++){
		v.push_back(ar[i]);
	}
	if (f(v)>h)
		return false;
	return true;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>h;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    }

    int l,r;
    l=0;
    r=n;
    while (l<r)
    {
    	int mid=l+r+1;
    	mid/=2;
    	if (solve(mid))
    		l=mid;
    	else
    		r=mid-1;
    }

    cout<<l<<endl;
//    cin.get(); cin.get();
    return 0;
}