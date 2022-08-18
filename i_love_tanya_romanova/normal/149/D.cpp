/*
Darlin' I know you're sleepin'
But there's something I've just got to say
Wonder if you'll hear me
While you're dreamin'
You make a lifetime
Out of every day
Thanks to you now I know
All my dreams can come true

Blind Faith in you
I got
Blind Faith in you oh yeah

Your eyes keep things well hidden
Just a hint of what
You're feelin' inside
And the first day that I met you
I consider that the first day of my life
Thanks to you now I know
All my dreams can come true

Blind Faith in you
I've got
Blind faith in you
And I'm not sure I deserve
A women so true, but I love
That you think I do

With You and Faith, beside me
I'm feelin' stronger every day

Blind faith in you
I got
Blind faith in you
It's true
Blind faith in you
I got
Blind faith in you
And I'm not sure I deserve
A woman so true but I love
That you think I do.
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

const int N = 1100;

using namespace std;

int n;
string st;
stack<int> s;
int paired[N];
int dp[N][N][2][2];

long long solve(int l, int r, int le, int ri)// left, right, clrd 2 left, clrd 2 right
{
	if (l > r)
		return 1;
	if (dp[l][r][le][ri] != -1)
		return dp[l][r][le][ri];
	long long ans = 0;
	int ps1, ps2;
	ps1 = l;
	ps2 = paired[l];
	ans += (2 - le)*solve(ps1 + 1, ps2 - 1, 1, 0)*solve(ps2 + 1, r, 0, ri);// left painted
	ans += (2 - (ps2 == r&&ri == 1))*solve(ps1 + 1, ps2 - 1, 0, 1)*solve(ps2 + 1, r, 1, ri);//right painted
	ans %= bs;
	dp[l][r][le][ri] = ans;
	return ans;
}
int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> st;
	n = st.size();
	for (int i = 0; i < n; i++)
	{
		if (st[i] == '(')
		{
			s.push(i);
		}
		else
		{
			int id = s.top();
			s.pop();
			paired[id] = i;
		}
	}
	/*
	for (int i = 0; i < n; i++)
	{
		cout << i << " " << paired[i] << endl;
	}*/

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j ++ )
		{
			for (int q = 0; q <= 1; q++)
			{
				for (int w = 0; w <= 1; w++)
				{
					dp[i][j][q][w] = -1;
				}
			}
		}
	}

	cout << solve(0, n - 1, 0, 0) << endl;

	cin.get(); cin.get();
	return 0;
}