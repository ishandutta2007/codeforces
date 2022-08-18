/*
Happy Jack wasn't old, but he was a man
He lived in the sand at the Isle of Man
The kids would all sing, he would take the wrong key
So they rode on his head on their furry donkey

The kids couldn't hurt Jack
They tried and tried and tried
They dropped things on his back
And lied and lied and lied and lied and lied

But they couldn't stop Jack, or the waters lapping
And they couldn't prevent Jack from feeling happy

But they couldn't stop Jack, or the waters lapping
And they couldn't prevent Jack from feeling happy

The kids couldn't hurt Jack
They tried and tried and tried
They dropped things on his back
And lied and lied and lied and lied and lied

But they couldn't stop Jack, or the waters lapping
And they couldn't prevent Jack from feeling happy

(I saw ya!)
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
#define bs 100000007
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 100031;

int n;
long long ar[N];
map<long long, int> cnt;
int ans;
long long s[N];

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
	
	for (int i = 1; i < n; i++)
		s[i] = s[i - 1] + ar[i];

	for (int i = 0; i < n; i++)
	{
		ans = max(ans, cnt[s[i]]);
		cnt[s[i]]++;
	}

	cout << n - ans - 1 << endl;

	cin.get(); cin.get();
	return 0;
}