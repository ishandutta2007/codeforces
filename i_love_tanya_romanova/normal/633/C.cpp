/*
I work for a livin' 
So mr. don't call me sir 
I spend my whole life giving 
For nothing much in return but scars and burns 

Steel town 
Living in a steel town 
Free and proud 
Steel town 
Working in a steel town 
My hometown 

I got my high school sweet heart 
And my hometown team 
Yeah with my friends all drinking at the corner bar 
It's all that I need coz I'm living free 

Steel town 
Living in a steel town 
Free and proud 
Steel town 
Working in a steel town 
My hometown 
Keep on burning keep on turning 

I'm branded by the fire 
My bloods running hot 
And I'll be damned if I don't stand and fight 
Cause this steel town is all that we got 

Steel town 
Living in a steel town 
Free and proud 
Steel town 
Working in a steel town 
My hometown 
Steel town 
Living in a steel town 
Free and proud 
Steel town 
Working in a steel town 
My hometown
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

const int N = 15000;

using namespace std;

int n;
string st;
int w;
int dp[N];
pair<int, int> par[N];
vector<int> ans;
int cur;
string word[200000];
int have[1200000][28];
int cnt;
int endpoint[1200000];

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	cin >> st;
	cin >> w;

	cnt = 1;

	for (int i = 1; i <= w; i++)
	{
		cin >> word[i];
		cur = 0;
		string temp = word[i];
		reverse(temp.begin(), temp.end());
		for (int j = 0; j < temp.size(); j++)
		{
			if (temp[j] >= 'A'&&temp[j] <= 'Z')
				temp[j] = temp[j] - 'A' + 'a';
		}
		for (int j = 0; j < temp.size(); j++)
		{
			int here = temp[j];
			here -= 'a';
			if (have[cur][here] == 0)
			{
				have[cur][here] = cnt;
				++cnt;
			}
			cur = have[cur][here];
		}
		endpoint[cur] = i;
	}

	dp[0] = 1;

	for (int i = 0; i < n; i++)
	{
		cur = 0;
		if (dp[i] == 0)
			continue;

		for (int j = i; j < n; j++)
		{
			int here = st[j] - 'a';
			if (have[cur][here] == 0)
				break;
			cur = have[cur][here];
			if (endpoint[cur])
			{
				dp[j + 1] = 1;
				par[j + 1] = make_pair(i, endpoint[cur]);
			}
		}
	}

	while (n > 0)
	{
		ans.push_back(par[n].second);
		n = par[n].first;
	}

	reverse(ans.begin(), ans.end());

	for (int i = 0; i< ans.size(); i++)
	{
		if (i)
			cout << " ";
		cout << word[ans[i]];
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}