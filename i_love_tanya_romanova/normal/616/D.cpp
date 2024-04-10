/*
A broken castaway from where the shadows lie
Soon comes the shadow there where the sanes abide
Soon comes the castaway, he's so full of dancing
A move to move the trance in

Riding on my own I speed, riding on a road of fire
Staring at the autumn leaves, left is for the neon isles
Waiting on the road a torment, waiting on the road the doormen
Riding on my own I speed, right is for the shadowshires

Some tragic magic spoken from the neon place
So many years away and still that moment stays
So many years to go and he's full of laghter
A move to move there after

Riding on my own I speed, riding on a road of fire
Staring at the autumn leaves, left is for the neon isles
Waiting on the road a torment, waiting on the road the doormen
Riding on my own I speed, right is for the shadowshires

See how the neon lights are faltering
The sea on the left is carved in stone
See all the million lights are flickering
The right of the road becomes my own

Riding on my own I speed, riding on a road of fire
Staring at the autumn leaves, left is for the neon isles
Waiting on the road a torment, waiting on the road the doormen
Riding on my own I speed, right is for the shadowshires
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 1000100;

using namespace std;

int n, k, ar[N];
int cnt_dif;
int cnt[N];
int ans;
int al, aR;

void add_element(int x)
{
	if (cnt[x] == 0)
		++cnt_dif;
	++cnt[x];
}

void remove_element(int x)
{
	if (cnt[x] == 1)
		--cnt_dif;
	--cnt[x];
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	ans = -100;

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
	}

	int ptr = 0;

	for (int i = 1; i <= n; i++)
	{
		while (ptr <= n&&cnt_dif <= k)
		{
			add_element(ar[ptr + 1]);
			++ptr;
		}
		if (ptr - i > ans)
		{
			ans = ptr - i;
			al = i;
			aR = ptr - 1;
		}
		remove_element(ar[i]);
	}

	cout << al << " " << aR << endl;

	cin.get(); cin.get();
	return 0;
}