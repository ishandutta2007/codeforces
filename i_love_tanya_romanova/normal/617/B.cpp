/*
A selfish man, a wretch I do stand, just as you we are the same
But how is it that justice follows in Your wake and grace remains?
And grace remains? Your grace remains! Still grace remains!

This is justice for my wickedness with your Son descending
Onto this world bearing our sin
We're helpless in need of Your grace
This freedom is not in our hands
Still Your grace remains

It was not nails that kept You there on that tree
It was not thorns that caused You your pain (fully)
For it was my sin, it was Your burden
It was my sin, it was Your love for me
It was not nails that kept You there on that tree
It was not thorns that caused You your pain (fully)
For it was my sin, it was Your burden
It was my sin, it was Your love for me

Then at the cross You bore my sin
And as You bled You thought of me
And still these bones will cry
Who am I that you would give Your life and die for me?

Not just a myth and not just a story
Becoming my sin and all for His glory
Not just a martyr, not just a saint
He's risen, alive
Death had no restraint!

Bride, arise! And lift up His holy name
Oh yea bride, arise! And life up His name
It was not nails that kept You there on that tree
It was not thorns that caused You your pain (fully)
For it was my sin, it was Your burden
It was my sin, it was Your love for me

Then at the cross You bore my sin
And as You bled You thought of me
And still these bones will cry
Who am I that you would give Your life and die for me?
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
#define bsize 256

const int N = 600000;

using namespace std;

int n;
long long dp[1000], ar[1000], s[1000];

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		s[i] = s[i - 1] + ar[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if (s[i] - s[j] == 1)
				dp[i] += dp[j];
		}
	}
	cout << dp[n] << endl;

	cin.get(); cin.get();
	return 0;
}