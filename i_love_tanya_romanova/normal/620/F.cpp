/*
At midnight by the fireplace
I fell in love with her portrait
Her eyes revealed
She knew I'd take the bait

It's said she rests for many years
Moonlight will make her appear
In the lake that she had filled with her own tears

I gathered all of the stories we have been told
I never questioned she was really out there...
Obsessed by the secret that she may hold
I will find her anywhere...

And there she lies with open eyes
Starring into the night

In the light of the midnight sky
I have found one good reason to die
Take me down to the quiet place
In the lake where she sleeps in grace

It's said she rests for many years
I can see her shade appear
In the lake that she had filled with strays and peers

Sinking deeper
Oh, how the cold fills me out
As the starlight blurs over me
Going deeper
Emerging into the black
For the first time I feel free

And there she lies with open eyes
Starring into the night

In the light of the midnight sky
I have found one good reason to die
Take me down to the quiet place
In the lake where she sleeps in grace

In the light of the midnight sky
I have found one good reason to die
Take me down to the quiet place
In the lake where she sleeps in grace

In the lake where she sleeps in grace
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
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 128

const int N = 50531;

using namespace std;

int ar[N];
int n, tests;
int MM[N];

int Xf(int x)
{
	if (x % 4 == 3)
		return 0;
	if (x % 4 == 0)
		return x;
	if (x % 4 == 1)
		return 1;
	if (x % 4 == 2)
		return x + 1;
}

int memo_xor[1000031];

inline int f(int u, int v)
{
	return memo_xor[min(u, v) - 1] ^ memo_xor[max(u, v)];
}

int L[N], R[N], res[N];
vector<int> queries[N];
int ans[N];

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	for (int i = 1; i <= 1000000; i++)
	{
		memo_xor[i] = (memo_xor[i - 1] ^ i);
	}

	cin >> n >> tests;
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}

	for (int i = 1; i <= tests; i++)
	{
		cin >> L[i] >> R[i];
		--L[i];
		--R[i];
		queries[R[i]].push_back(i);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j >= 0; --j)
		{
			res[j] = max(res[j], f(ar[i], ar[j]));
		}
		for (int j = 0; j < queries[i].size(); j++)
		{
			int id = queries[i][j];
			for (int q = L[id]; q <= R[id]; q++)
			{
				ans[id] = max(ans[id], res[q]);
			}
		}
	}

	for (int i = 1; i <= tests; i++)
	{
		cout << ans[i] << endl;
	}

	cin.get(); cin.get();
	return 0;
}