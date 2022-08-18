/*
Blacked out
Pop queen, amphetamine
The screams crashed into silence

Tapped out
Doused in the gasoline
The high times going timeless

Decadence
Death of the innocence
The pathway starts to spiral

Infamy
All for publicity
Destruction going viral

Light it up
Ah, light it up
Another hit erases all the pain
Bulletproof
Ah, kill the truth
You're falling, but you think you're flying high
High again

Sold your soul
Built a higher wall
Yesterday
Now you're thrown away

Same rise and fall
Who cares at all?
Seduced by fame
A moth into the flame

Twisted
Backstabbing wicked
The delusion absolution

Perjurer
Fame is the murderer
Seduce you into ruin

Light it up
Ah, light it up
Another hit erases all the pain
Bulletproof
Ah, tell the truth
You're falling, but you think you're flying high
High again

Sold your soul
Built the higher wall
Yesterday
Now you're thrown away

Same rise and fall
Who cares at all?
Seduced by fame
A moth into the flame
Burn

Guarantee your name, you go and kill yourself
The vultures feast around you still
Overdose on shame and insecurity
If one won't do that fistful will

Death scene
Black hearse the limousine
A grave filled with seduction

Vaccine
Fame does the murdering
She builds up for destruction

So light it up
Ah, light it up
Another hit erases all the pain
Bulletproof
Ah, no excuse
You're falling, but you think you're flying high
High again

Sold your soul
Built the higher wall
Yesterday
Now you're thrown away

Same rise and fall
Who cares at all?
Seduced by fame
A moth into the flame

Addicted to the
Fame
*/

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
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n,cnt[N];
int ans;

int solve(int x)
{
	int res=0;
	for (int i=x;i<N;i+=x)
		res+=cnt[i];
	return res;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int val;
		cin>>val;
		cnt[val]++;
	}

	ans=1;

	for (int i=2;i<N;i++)
	{
		ans=max(ans,solve(i));
	}
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}