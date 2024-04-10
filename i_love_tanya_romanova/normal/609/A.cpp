/*
The death corpse composed behind
In the dust of their self
To terminate another life
A further obligation to make

Wounds of memory for ever to stay
The hall of souls are the hall of pain

Reward through a successful life
Punish through a painful life
A waiting soul for each new life

The deliverance to penetrate into nirvana
How much life need for all to know
Or is to be a punishment about our mistakes
To life with it

To understand what is it

Is the source the life
Is the source the death

The hall of torment
To know more but they feasting
Is the waiting room for souls

Torment, unknown, pain for fear
Torture, yearning, waiting for deliverance

The question of existents
Reality or dream

I can see your pain in my dreams
I can smell your screams in my dreams
I feel your fear, your fear for my dreams
*/

//#pragma comment(linker, "/STACK:16777216")
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
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1234567891
#define bsize 512

const int N = 1100;

using namespace std;

int n, m, ar[N];
int s, q;

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	sort(ar, ar + n);
	reverse(ar, ar + n);

	int q = 0;
	while (s < m)
	{
		s += ar[q];
		++q;
	}
	cout << q << endl;

	cin.get();
	return 0;
}