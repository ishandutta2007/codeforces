/*
Painter
Come colour up my life
Oh painter
Come colour up my life
Take away the misery
Take away the strife

Writer
Make me up a play
Writer
Make the meaning gay
(For I don't know who I am)
Just give me words to say

Singer
Let me sing a song
Singer
Let me sing a song
You don't have to worry
Cause singer you can sing along
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600031;

int n,C[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		int cnt;
		cin>>cnt;
		for (;cnt;--cnt){
			int val;
			cin>>val;
			C[val]++;
		}
	}

	for (int i=1;i<=100;i++){
		if (C[i]==n)
			cout<<i<<" ";
	}
	cout<<endl;

//	cin.get(); cin.get();
	return 0;
}