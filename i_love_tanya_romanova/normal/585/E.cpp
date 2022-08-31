/*
Something has to change.
Un-deniable dilemma.
Boredom's not a burden
Anyone should bear.

Constant over stimu-lation numbs me
but I would not want you
any other way.

It's not enough.
I need more.
Nothing seems to satisfy.
I said
I don't want it.
I just need it.
To breathe, To feel, to know I'm alive.

Finger deep within the borderline.
Show me that you love me and that we belong together.
Relax, turn around and take my hand.

I can help you change
Tired moments into pleasure.
Say the word and we'll be
Well upon our way.

Blend and balance
Pain and comfort
Deep within you
Till you will not want me any other way.

It's not enough.
I need more.
Nothing seems to satisfy.
I said
I don't want it.
I just need it.
To breathe, To feel, to know I'm alive.

Knuckle deep inside the borderline.
This may hurt a little but it's something you'll get used to.
Relax. Slip away.

Something kinda sad about
the way that things have come to be.
Desensitized to everything.
What became of subtlety?

How can it mean anything to me
If I really don't feel anything at all?

I'll keep digging
Till I feel something.

Elbow deep inside the borderline.
Show me that you love me and that we belong together.
Shoulder deep within the borderline.
Relax. Turn around and take my hand.
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
#define bs 1000000007
#define bsize 512

const int N = 110000;
const int M = 10000000;

using namespace std;

int mu[M + 10], pw[M + 31], cnt[M + 10];
int ans;

int mult(int a, int b)
{
	return 1ll * a*b%bs;
}

int add(int a, int b)
{
	a += b;
	if (a >= bs)
		a -= bs;
	return a;
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	pw[0] = 1;
	for (int i = 1; i <= M; i++)
		pw[i] = pw[i - 1] * 2 % bs;

	mu[1] = 0;
	for (int i = 2; i <= M; i++)
	{
		if (mu[i] == 0)
		{
			for (int j = i; j <= M; j += i)
				mu[j]++;
		}
	}

	for (int i = 2; i <= M; i++)
	{
		if (mu[i] %2==1)
		{
			mu[i] = 1;
		}
		else
		{
			mu[i] = -1;
		}
	}

	for (int i = 2; i*i <= M; i++)
	{
		for (int j = i*i; j <= M; j += i*i)
		{
			mu[j] = 0;
		}
	}

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int val;
		cin >> val;
		cnt[val]++;
	}

	// (A, B) counted S(A)-S(B) times, gives 1 for B==1 and 0 otherwise; S(X)=(X!=1);

	for (int G = 2; G <= M; G++)
	{
		if (mu[G] == 0)
			continue;
		int s = 0;
		for (int i = G; i <= M; i += G)
		{
			s += cnt[i];
		}
		if (s == 0)
			continue;
		int rem = n - s;
		if (mu[G] == 1)
		{
			ans = add(ans, mult(rem, pw[s] - 1));
		}
		else
		{
			ans = add(ans, bs - mult(rem, pw[s] - 1));
		}
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}