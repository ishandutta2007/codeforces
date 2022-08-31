/*
Bringing Satan's wine high on divine weed
A little bit religion is what everybody needs
Go away sad soul your lack of energy can be infectous
Hiding in the dark crawling on the knees
Is no life for a proud man and for sure no life for me

Try to have a laugh until the world goes down
Isn't it pathetic that the world is round
And nobody can push you off it easily
Not even your most wicked enemy
We could burn with never ending energy
Just cheer up a little if you will burn with me
And go away goddamn cellar soul
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
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 1100;

string st;
int dp[100000][5];

bool shit(int ps, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (st[ps - len + i] != st[ps + i])
			return false;
	}
	return true;
}

set<string> ans;
set<string>::iterator it;
vector<string> v;

void trace(int len, int lst)
{
	if (dp[len][lst] == 0)
		return;
	dp[len][lst] = 0;

	string temp = "";
	for (int i = len - lst; i < len; i++)
		temp += st[i];
	ans.insert(temp);
	for (int i = 2; i <= 3; i++)
	{
		if (i != lst || (!(shit(len - lst, lst))))
		{
			trace(len - lst, i);
		}
	}

}
int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> st;
	for (int i = 5; i <= st.size(); i++)
	{
		dp[i][0] = 1;
	}
	for (int i = 0; i < st.size(); i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (dp[i][j] == 0)
				continue;
			for (int ad = 2; ad <= 3 && ad + i <= st.size(); ad++)
			{
				bool ok = 1;
				if (ad == j)
				{
					if (shit(i, ad))
						ok = 0;
				}
				if (ok == 0)
					continue;
				dp[i + ad][ad] = 1;
			}
		}
	}

	for (int i = 2; i <= 3; i++)
	{
		if (dp[st.size()][i])
		{
			trace(st.size(), i);
		}
	}

	for (it = ans.begin(); it != ans.end(); it++)
	{
		v.push_back(*it);
	}
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	cin.get(); cin.get();
	return 0;
}