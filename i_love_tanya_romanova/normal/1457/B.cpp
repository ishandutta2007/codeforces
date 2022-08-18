/*
Behind the little boy's eyes name is written in blood
There is not a clue in sight, not a moment of clarity
Grew up to be a man behind the white fence he rules and he stands
Frowning at the happy world outside
But inside his head it's dark

Just remember this
Everyone is a mother's son

Different colour different skin
Scarred for life there is no turning back
He lifts the blade over his head
Watch him intoxicated by his victims fear
He is about to deliver his attack
But inside his head it's dark

Just remember this
Everyone is a mother's son

Monster, the monster inside
Monster, we all live in fear
For the monster, the monster inside
Monster, the monster is near

Ready to kill, ready to strike
The screams so loud makes him high so high
He walks away in a perfect time
But he will return to the scene of the crime
But inside his head it's dark
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

const int bs = 1000000007;

const long long N = 200031;

int tests,n,k;
int ans;
int ar[N];

int solve(int cl){
	int covered=0;
	int ret=0;
	while (covered<n){
		if (ar[covered+1]==cl)
			covered++;
		else
		{
			covered+=k;
			ret++;
		}
	}
	return ret;
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>k;
    	ans=n;
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    	}
    	for (int i=1;i<=100;i++){
    		ans=min(ans,solve(i));
    	}
    	cout<<ans<<endl;
    }
    //cin.get(); cin.get();
    return 0;
}