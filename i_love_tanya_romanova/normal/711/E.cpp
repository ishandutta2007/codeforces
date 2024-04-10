/*
War drags them to the very end
The blushing sun has turned to red

Death slumbers
In dawn's blue light
Reflecting
In the sea of blood
For evil to be made
Hell is burning
From the dungeons
Of emotions
Apprehension death
Scars of misery

God bless you, the nations heart
A bond closer than brothers
With a rifle in your gracious hand
You ll leave the shadows of the dead

One by one
One by one

They took their souls and cut their wings
Considering all their energy

War hungry
Bullets eating flesh
Can't kill the
Spirit of a man
That's hidden from their eyes
Heaven's caving
Intimidate deforming
Ever lastingly caught
The sin to the holy sky

God bless you, the nations heart
A bond closer than brothers
With a rifle in your gracious hand
You ll leave the shadows of the dead

God bless you
One by one
God bless you
One by one

God bless you, the nations heart
With a rifle in your gracious hand
God bless you, the nations heart
A bond closer than brothers
With a rifle in your gracious hand
You ll leave the shadows of the dead

God bless you
One by one
God bless you
One by one

They've gone to sleep lain down the fight
Carry the weight of the land to the sky
The holy ground sacred by their blood
Helmets resting on the guns butt

We'll always be one step ahead
Discovering our relentless pride
Decadence, your state of being
There s more than evil in their minds

God bless you
One by one
God bless you
One by one
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
#define bs 1000003
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 200131;

long long pw(long long a, long long b)
{
	if (b == 0)
		return 1;
	if (b % 2)
		return a*pw(a, b - 1) % bs;
	return pw(a*a%bs, b / 2);
}

long long inv(long long x)
{
	return pw(x, bs - 2);
}

long long n, k;

long long res = 1;

long long get_highest(long long x)
{
	if (x == 0)
		return 0;
	if (x % 2 == 1)
		return 0;
	return get_highest(x / 2) + 1;
}

long long get_pw(long long x)
{
	long long res = 0;
	while (x)
	{
		res += x / 2;
		x /= 2;
	}
	return res;
}

long long IP[100000];

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> k;

	if (n <= 60 && k > (1ll << n))
	{
		cout << 1 << " " << 1 << endl;
		return 0;
	}

	for (int i = 0; i <= 100; i++)
	{
		IP[i] = inv(pw(2, i));
	}
	long long U = 1;
	if (k < 1e7)
	{
		long long val = pw(2, n);
		for (int i = 1; i < k; i++)
		{
			long long T = get_highest(i);
			long long rem = ((val - i + bs) % bs)*IP[T] % bs;// inv(pw(2, T)) % bs;
			if (rem < 0)
				rem += bs;
			rem %= bs;
			U = U*rem%bs;
		}
//		cout << val << " " << U << endl;
	}
	else
		U = 0;

//	cout << U << endl;

		long long res = pw(2, n);
		res = pw(res, k-1);
		long long res2 = get_pw(k-1);
		res2 = pw(2, res2);
		res2 = inv(res2);
		res = res*res2;
		res %= bs;
//		cout << res2 << endl;
		long long mres = res - U + bs;
		mres %= bs;

		cout << mres <<" "<<res<< endl;

	cin.get(); cin.get();
	return 0;
}