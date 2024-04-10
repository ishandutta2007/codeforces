/*
Just a castaway
An island lost at sea
Another lonely day
There's no one here but me
More loneliness
Than any man could bear
Rescue me before I fall into despair

I'll send an SOS to the world
I'll send an SOS to the world
I hope that someone gets my
I hope that someone gets my
I hope that someone gets my
Message in a bottle

A year has passed since I wrote my notes
But I should have known this right from the start
Only hope can keep us together
Love can mend your life
But love can break your heart

I'll send an SOS to the world
I'll send an SOS to the world
I hope that someone gets my
I hope that someone gets my
I hope that someone gets my
Message in a bottle
*/

//#pragma GCC optimize("O3")
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
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1100031;

int done[N],f[N];
int S[N][11];

int solve(int x){
	if (done[x])
		return f[x];
	done[x]=1;
	if (x<10){
		f[x]=x;
		return f[x];
	}

	int cur_prod=1;
	int temp=x;
	while (temp){
		if (temp%10!=0)
			cur_prod*=temp%10;
		temp/=10;
	}
	f[x]=solve(cur_prod);
	return f[x];
}

int tests;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	done[0]=0;
	f[0]=0;
	for (int i=1;i<=1000000;i++){
		if (done[i]==0){
			f[i]=solve(i);
		}
	}

	for (int i=1;i<=1000000;i++){
		for (int j=0;j<=9;j++){
			S[i][j]=S[i-1][j];
		}
		S[i][f[i]]++;
	}

	cin>>tests;
	for (;tests;--tests){
		int l,r,val;
		cin>>l>>r>>val;
		cout<<S[r][val]-S[l-1][val]<<"\n";
	}

//	cin.get(); cin.get();
	return 0;
}