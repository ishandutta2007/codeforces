/*
It begins with a dark, glowing ember
Something black, burning its way out of me
Searing the flesh, pain is the only thing I feel
Scars all I see

Oh no, the fire's burning my insides again
What can I do to silence my desire tonight?
Face consumer reason leaving all the ashes there
You won't catch me for granting my decision

I can't keep telling myself
What I wanna hear
I can't just close my eyes

I know that it's killing me
And it's poisoning the best of me
But I say I don't want to believe
So let me tell you, boy, tell you, boy
About the lies I lead

That is how it kills, I got some flames and gasoline
Broken teeth replace the blackout memories in my head
Wreckage from the blast, it often shakes me to the floor
I know it's over but I can't go home tonight

And after this I feel as empty as the night before
Feel the pain and yet I'm still begging for more
Masochistic, nihilistic, gorging, wrecked up thoughts
My life's a mess and I can't find a way to fix it

I can't keep telling myself
What I wanna hear
I can't just close my eyes

I know that it's killing me
And it's poisoning the best of me
But I say I don't want to believe
So let me tell you, boy, tell you, boy
About the lies I lead

Calling, calling out
The darkest reaches of my soul
I'm riddled with self-doubt

Crawling, crawling out
My will to fight will more than suffice
While others will lay down
It's only as dark as you make it

I know that it's killing me
And it's poisoning the best of me
But I say, I don't want to believe
So let me tell you, boy, tell you, boy
About the lies I lead
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
const int N = 1000031;

int n, k, ar[1051];
int dp[1045][1031];

vector<int> ans;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
//		ar[i] = rand() % 500 + 1;
	}

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = k; j >= 0; --j)
		{
			for (int q = k; q >= 0; --q)
			{
				if (dp[j][q])
				{
					dp[j + ar[i]][q] = 1;
					dp[j + ar[i]][q + ar[i]] = 1;
				}
			}
		}
	}

	for (int i = 0; i <= k; i++)
	{
		if (dp[k][i])
			ans.push_back(i);
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}