/*
Eternal the kiss I breath
Siphon your blood to me
Feel my wounds of your god
Forever rape mortality
I smell of death
I reek of hate
I will live forever
Lost child pay the dead
Bleeding screams of silence
In my veins your eternity

I'll kill you and your dreams tonight
Begin new life
Bleed your death upon me
Let your bloodline feed my youth

First breath born come alive learn to kill
Blood-fest awaits to feed your hunger
Dark side has no rival test your faith in blood
Night hides the hunting packs a feeding frenzy

I'll kill you and your dreams tonight
Begin new life
Bleed your death upon me
Let your bloodline feed my youth

I am the first not the last
Condemned by a single kiss
Betrayed eternally I'll rip inside your soul
Contaminating the world
Defying god and son
Black heart that brings your death
Living in infamy

Drink the flesh of life itself
Prepare to reign a thousand years

I'll kill you and your dreams tonight
Begin new life
Bleed your death upon me
Let your bloodline feed my youth
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
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n,k;
int ar[N];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>k;
	for (int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	sort(ar,ar+n);

	long long res=0;
	for (int i=1;i<n;i++)
	{
		long long here=ar[i]-ar[0];
		if (here%k)
			res=1e18;
		res+=here/k;
	}

	if (res>1e16)
		res=-1;

	cout<<res<<endl;

	cin.get(); cin.get();
	return 0;
}