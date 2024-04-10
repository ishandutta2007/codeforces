/*
Woke up depressed
I left for work
You have a good day
It's not your fault
I know it hurts

Remember, I love you, love you
Remember, I love you, love you
I love

Woke up depressed
I left for work
You have a good day
It's not my fault
I know it hurts
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

const int N = 200031;

int n,x,cnt[N];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>x;
	for (int i=1;i<=n;i++){
		int val;
		cin>>val;
		cnt[val]++;
	}

	int ans=0;
	if (cnt[x])
		++ans;
	for (int i=0;i<x;i++){
		if (cnt[i]==0)
			++ans;
	}
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}