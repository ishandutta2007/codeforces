/*
Started off as a one night stand, lingered to a fling
The sirens and the sergeants didn't seem to mean a thing
Hide your fangs all you want, you still need the blood
Tell us that it's different now, you're up to no good

(Take my hand, show me the way, we are the children that fell from grace)
(Take my hand, show me the way, we are the children that can't be saved)

One more nail in the coffin, one more foot in the grave
One more time I'm on my knees as I try to walk away
How has it come to this?

I've said it once, I've said it twice, I've said it a thousand fucking times
That I'm OK, that I'm fine, that it's all just in my mind
But this has got the best of me, and I can't seem to sleep
It's not 'cause you're not with me, it's 'cause you never leave

I've said it once a thousand fucking times
You say this is suicide,
I say this is a war
And I'm losing the battle
Man down, man down, oh

Is this what you call love?
This is a war I can't win!

One more nail in the coffin, one more foot in the grave
One more time I'm on my knees as I try to walk away
Everything I've loved became everything I lost

I've said it once, I've said it twice, I've said it a thousand fucking times
That I'm OK, that I'm fine, that it's all just in my mind
But this has got the best of me, and I can't seem to sleep
It's not 'cause you're not with me, it's 'cause you never leave
It's not 'cause you're not here with me, it's 'cause you never leave

Every second, every minute, every hour, every day
It never ends, it never ends
Every second, every minute, every hour, every day
It never ends, it never ends
Every second, every minute, every hour, every day
It never ends, it never ends
Every second, every minute, every hour, every day
It never ends, it never ends
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 201000;

using namespace std;

int n, b, k, x;
vector<vector<long long> > v;
int cnt[N];

vector<vector<long long> > mult(vector<vector<long long> > a, vector<vector<long long> > b)
{
	vector<vector<long long> > res;
	res = a;
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res.size(); j++)
		{
			res[i][j] = 0;
		}
	}
	for (int i = 0; i < a.size(); i++)
	{
		for (int k = 0; k < res.size(); k++)
		{
			for (int j = 0; j < res.size(); j++)
			{
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % bs;
			}
		}
	}
	return res;
}

vector<vector<long long> > pw(vector<vector<long long> > a, long long b)
{
	if (b == 1)
		return a;
	if (b % 2)
		return mult(a, pw(a, b - 1));
	return pw(mult(a, a), b / 2);
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> b >> k >> x;
	for (int i = 1; i <= n; i++)
	{
		int val;
		cin >> val;
		cnt[val]++;
	}

	v.resize(x);
	for (int i = 0; i < v.size(); i++)
	{
		v[i].resize(x);
		for (int j = 0; j < v[i].size(); j++)
		{
			v[i][j] = 0;
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int ad = 0; ad < 10; ad++)
		{
			v[i][(i * 10 + ad) % x] += cnt[ad];
		}
	}

	v = pw(v, b);

	cout << v[0][k] << endl;

	cin.get(); cin.get();
	return 0;
}