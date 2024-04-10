/*
The darkest side of your life
Can't understand the secret, how you survive
A crystal ball, by your side
A frightful future, now you describe

Higher above
A ball of fire about to fall

Can't escape, from tomorrow
A hopeless time rising
Can't escape, from tomorrow
Will we arrive

The finest days of our lives
There'll be no longer days for us to be alive
The final chapter has been read
The time has come to realize
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
#define have adsgagshdshfhds

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 200031;

int n, ar[N];
long long S[N], w[N];
int order[N];
long long ans[N];
long long cur_best;
int dead[N];

int get(int x)
{
	if (x == w[x])
		return x;
	return w[x] = get(w[x]);
}

void merge(int a, int b)
{
	a = get(a);
	b = get(b);
	if (a == b)
		return;
	w[a] = b;
	S[b] += S[a];
	cur_best = max(cur_best, S[b]);
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
	}

	dead[0] = dead[n + 1] = 1;

	for (int i = 1; i <= n; i++)
	{
		cin >> order[i];
		dead[i] = 1;
	}

	
	for (int i = n; i; --i)
	{
		int id = order[i];
		ans[i] = cur_best;
		dead[id] = 0;
		w[id] = id;
		S[id] = ar[id];
		cur_best = max(cur_best, S[id]);
		if (dead[id - 1] == 0)
		{
			merge(id, id - 1);
		}
		if (dead[id + 1] == 0)
		{
			merge(id, id + 1);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << "\n";
	}

	cin.get(); cin.get();
	return 0;
}