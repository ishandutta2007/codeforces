/*
Oh dear mother
I love you
I'm sorry
I wasn't good enough
Dear father
Forgive me
'Cause in your eyes
I just never added up
In my heart I know I failed you
But you left me here alone

If I could hold back the rain
Would you numb the pain?
'Cause I remember
Everything
If I could help you forget
Would you take my regrets?
'Cause I remember
Everything

Oh dear brother
Just don't hate me
For never standing by you
Or being by your side
Dear sister
Please don't blame me
I only did what I thought was truly right

It's a long and lonely road
When you know you'll walk alone

If I could hold back the rain
Would you numb the pain?
'Cause I remember
Everything
If I could help you forget
Would you take my regrets?
'Cause I remember
Everything

I feel like running away
I'm still so far from home
You say that I'll never change
But what the fuck do you know?
I'll burn it all to the ground
Before I let you in
Please forgive me
I can't forgive you now

I remember
Everything

If I could hold back the rain
Would you numb the pain?
'Cause I remember
Everything
If I could help you forget
Would you take my regrets?
'Cause I remember
Everything

It all went by so fast
I still can't change the past
I always will remember
Everything
If we could start again
Would that have changed the end?
We remember
Everything

Oh everything
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

#define bs 1000000007

const int N = 100031;

int tests,n,k;
int ar[N];
int ans;

bool check0(){
	for (int i=1;i<=n;i++){
		if(ar[i]!=k)
			return false;
	}
	return true;
}

bool check1(){
	int delta=0;
	for (int i=1;i<=n;i++){
		delta+=ar[i]-k;
	}
	if (delta==0)
		return true;
	int cnt=0;
	for (int i=1;i<=n;i++){
		if (ar[i]==k)
			cnt=1;
	}
	if (cnt)
		return true;
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	// cin.tie(0);

	cin>>tests;
	for (;tests;--tests){
		cin>>n>>k;
		for (int i=1;i<=n;i++){
			cin>>ar[i];
		}
		ans=2;
		if (check1())
			ans=1;
		if (check0())
			ans=0;
		cout<<ans<<endl;
	}
	//cin.get(); cin.get();
	return 0;
}