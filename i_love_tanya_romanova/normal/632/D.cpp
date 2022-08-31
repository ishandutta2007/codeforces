/*
We're born helpless
But guided by humanity
What was compassion?
Soon controls the way we think

Familiarity has left me desitized
And inanity keeps deception disguised

We are lost but keep moving forward
To find the truth we must turn around

History reveals an inviting
Sense of compromise
Our customs destroyed
What was once unique

Traditions started with useful intention
Now Subjugate those too numb to question

We are lost but keep moving forward
To find the truth we must turn around
We are lost!
To find the truth we must turn around

I desire to wake from Sedation
And begin to seperate
The truth from tradition

We are lost but keep moving forward
To find the truth we must turn around
We are lost but keep moving forward
To find the truth we must turn around
We are lost but keep moving forward
To find the truth we must turn around
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
#define bsize 512

const int N = 1000010;

using namespace std;

int n, m, ar[N];
vector<int> ent[N];
int ans[N];
int answ, aval;
vector<int> avec;

int gcd(int a, int b)
{
	while (a&&b)a > b ? a %= b : b %= a;
	return a + b;
}

int lcm(int a, int b)
{
	return a / gcd(a, b)*b;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		if (ar[i] > 1e6)
			continue;
		ent[ar[i]].push_back(i);
	}

	for (int i = 1; i <= 1e6; i++)
	{
		if (ent[i].size() == 0)
			continue;
		for (int j = i; j <= 1e6; j += i)
		{
			ans[j] += ent[i].size();
		}
	}

	answ = 0;
	aval = 1;
	for (int i = 1; i <= m; i++)
	{
		if (ans[i] > answ)
		{
			answ = ans[i];
			aval = i;
		}
	}
	
	int res = 1;
	for (int i = 1; i <= aval; i++)
	{
		if (aval%i)
			continue;
		if (ent[i].size() == 0)
			continue;
		res = lcm(res, i);
		for (int j = 0; j < ent[i].size(); j++)
		{
			avec.push_back(ent[i][j]);
		}
	}

	cout << res << " " << avec.size() << endl;
	sort(avec.begin(), avec.end());

	for (int i = 0; i < avec.size(); i++)
	{
		if (i)
			cout << " ";
		cout << avec[i];
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}