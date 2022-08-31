/*
I can see what the world has done to you
I can feel the weight
feel the weight

I can see what this life has handed you
I can feel the weight
feel the weight

This time, this time
Things'll work out just fine
We won't let you slip away
this time, this time
things'll work out just fine
we won't let you leave this way
If you want you can will it
you can have it
I can put it right there in your hands

I can hear what the spirits are telling you
I can clear the weight
clear the weight

I can see all the wolves as they circle you
I can crush the weight
crush the weight

This time, this time
Things'll work out just fine
We won't let you slip away
this time, this time
things'll work out just fine
we won't let you leave this way
If you want you can will it
you can have it
I can put it right there in your hands
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
#define norm asdfasdgasdgsd

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 200040;

int n, h, k, ptr, cur_h;
int ar[N];
long long ans;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> h >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
	}

	ptr = 1;

	while (true)
	{
		if (ptr > n)
			break;
		//cout << cur_h << " " << ptr << endl;
		if (cur_h == 0 && ptr > n)
			break;
		int need = h - ar[ptr];

		//cout << need << endl;

		//cout << ptr << " " << cur_h << " " << need << " " << ans << endl;

		if (cur_h > need)
		{
			int ohead = (cur_h - need) / k;
			ans += ohead;
			cur_h -= ohead*k;
		}

		while (cur_h > need)
		{
			ans++;
			cur_h -= k;
			if (cur_h < 0)
				cur_h = 0;
		}

		//cout << ans << endl;
		while (ptr <= n&&ar[ptr] + cur_h <= h)
		{
			cur_h += ar[ptr];
			ptr++;
		}
		if (cur_h > k)
			cur_h -= k;
		else
			cur_h = 0;
		ans++;
	}

	ans += cur_h / k + (cur_h%k > 0);
	cout << ans << endl;


	cin.get(); cin.get();
	return 0;
}