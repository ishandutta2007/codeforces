/*
I never cared about the money, never really needed fame
You'd think it would have changed me but I've always been the same
My label tried to sue me, TMZ tried to screw me
Blabbermouth can fuckin' suck it 'cause they never fuckin' knew me

Everybody seems like they're waiting for me to die
Talk shit behind my back, can't look me in the eye
They say I'm overrated, that I should've already faded
Gave a shit about it all because I love to be so hated

All in all it's a good life
I got what I want
I can't complain (I can't complain)
I'm living the good life
A toast to you now
It's all sham pain (it's all sham pain)

I barely get to eat and when I finally get to sleep
I get drug out of bed for another meet and greet
I shake the hand of every fan, put on a happy face
Spread so fuckin' thin I'm all over the place
I hate riding on the bus, I hate flying on the planes
Sedate myself just to kill the pain
I have no life, forgot the hope
The whole thing's turned into one big joke

All in all it's a good life
I got what I want
I can't complain (I can't complain)
I'm living the good life
A toast to you now
It's all sham pain (it's all sham pain)

I mean no disrespect but I ain't picking up the check
Taking selfies on your phone while you're breathing down my neck
It's getting pretty fuckin' old, and I'm almost nearly done
I'm glad that you were happy as you talk to number one

I'm living the good life, a toast to you now, it's all sham pain

All in all it's a good life
I got what I want
I can't complain (I can't complain)
I'm living the good life
A toast to you now
It's all sham pain (it's all sham pain)
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 2031;

int n,k,ar[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
	}

	int ptr_l=1;
	int ptr_r=n;
	while (ptr_l<=n&&ar[ptr_l]<=k)
		++ptr_l;

	while (ptr_r>=ptr_l&&ar[ptr_r]<=k)
		--ptr_r;

	int span=ptr_r-ptr_l+1;
	cout<<n-span<<endl;

//	cin.get(); cin.get();
	return 0;
}