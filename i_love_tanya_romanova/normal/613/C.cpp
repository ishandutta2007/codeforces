/*
Do you think there's a chance
For this world to live in unity as one?
I can try to believe
But I feel it's like a view into the sun

Blinded by the light everything will look so fine
But still I feel the rays are burning my soul

So you say you believe
We can change the world together if we try
I know we won't change
When it comes to the point
Do you think we reach an aim that is too high?
I know we don't arrange

But I know we're all the same
When the final curtain falls
And the Sighs on the way
Are leading us home

When I'm one with the world
I am one with my mind
Forget all the fury there's no need to cry
There's a place we all go, salvation to find
There's freedom to come
When I'm one with the world and my mind

Do you feel, do you know?
There's an answer to the question when you're gone
You're not alone
You will see, we will see
Is there nothing or a better place to go?
We can't go wrong

There are echoes in the wind
And they say don't be afraid
'Cos the Sighs on the way
Are leading us home

When I'm one with the world
I am one with my mind
Forget all the fury there's no need to cry
There's a place we all go, salvation to find
There's freedom to come
When I'm one with the world and my mind

One with the world
One with the world
One with the world
I am one
One with the world
One with my mind
One with my heart
*/

//#pragma comment(linker, "/STACK:16777216")
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
#define bsize 256

const int N = 231231;

using namespace std;

int n, ar[N], odd;
int parts;

bool can_make(int times)
{
	for (int i = 1; i <= n; i++)
	{
		if (ar[i] % times)
			return false;
	}
	int odd = 0;
	for (int i = 1; i <= n; i++)
	{
		int here = ar[i] / times;
		if (here % 2)
			++odd;
	}
	if (odd > 1)
		return false;
	return true;
}

string solve()
{
	string res = "";
	for (int i = 1; i <= n; i++)
	{
		if (ar[i] % 2 == 0)
		{
			for (int j = 1; j <= ar[i] / 2; j++)
			{
				res += char(i + 'a' - 1);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (ar[i] % 2 == 1)
		{
			for (int j = 1; j <= ar[i]; j++)
			{
				res += char(i + 'a' - 1);
//				cout << char(i + 'a' - 1);
			}
		}
	}
	for (int i = n; i >= 1; --i)
	{
		if (ar[i] % 2 == 0)
		{
			for (int j = 1; j <= ar[i] / 2; j++)
			{
//				cout << char(i + 'a' - 1);
				res += char(i + 'a' - 1);
			}
		}
	}
	return res;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("C:/input.txt","r",stdin);
	//freopen("C:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		assert(ar[i] > 0);
		if (ar[i] % 2 == 1)
			++odd;
	}

	if (n == 1)
	{
		cout << ar[1] << endl;
		for (int i = 1; i <= ar[1]; i++)
			cout << "a";
		cout << endl;
		return 0;
	}

	// n >1

	if (odd > 1)// shit
	{
		cout << 0 << endl;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= ar[i]; j++)
			{
				cout << char(i + 'a' - 1);
			}
		}
		cout << endl;
		return 0;
	}

	// odd<=1

	// actually don't need case above
	// I SAID I DON'T NEED THAT ONE

	for (int pals = (1 << 18); pals >= 1; pals--)
	{
		if (can_make(pals))
		{
			parts = pals;
			break;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		ar[i] /= parts;
	}

	int bad = 0;
	for (int i = 1; i <= n; i++)
	{
		if (ar[i] % 2)
			bad = 1;
	}
	string S = solve();

	if (bad)
		cout << parts << endl;
	else
		cout << parts * 2 << endl;

	for (int i = 1; i <= parts; i++)
	{
		cout << S;
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}