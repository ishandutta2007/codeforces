/*
He had enough, he couldn't take anymore
He'd found a place in his mind and slammed the door
No matter how they tried, they couldn't understand
They washed and dressed him, fed him by hand

Yea, I've left the world behind, I'm safe here in my mind
I am free to speak with my own kind
This is my life, this is my life, I'll decide not you

Withdrawn he'd sit there, stare blank into space
No sign of life would flicker on his face
Until one day he smiled, it seemed as though with pride
The wind kissed him, goodbye, and he died

Yea, I've left the world behind, I'm safe here in my mind
Free to speak with my own kind
This is my life, this is my life, I'll decide not you

Keep the world with all its sin, it's not fit for livin' in
Yea, I will start again it can take forever, forever, forever and ever
And ever, but I'll still win

How many like him are there still
Who to us all seem to have lost the will
They lie in thousands, lank and lost
Is knowledge worth this bitter cost?

Yea, I've left the world behind, I'm safe here in my mind
Free to speak with my own kind
This is my life, this is my life I'll decide not you
Keep the world with all its sin, it's not fit for livin' in

Beyond the realms of death
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

const int N = 300000;

using namespace std;

set<vector<string> > reach;

vector<string> get_board()
{
	vector<string> res;
	for (int i = 0; i < 2; i++)
	{
		string st;
		cin >> st;
		res.push_back(st);
	}
	return res;
}

void dfs(vector<string> v)
{
	if (reach.find(v) != reach.end())
		return;
	reach.insert(v);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int q = 0; q < 2; q++)
			{
				for (int w = 0; w < 2; w++)
				{
					if (v[q][w] != 'X')
						continue;
					if (abs(i - q) + abs(j - w) == 1)
					{
						vector<string> v2;
						v2 = v;
						swap(v2[i][j], v2[q][w]);
						dfs(v2);
					}
				}
			}
		}
	}
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	vector<string> v1 = get_board();
	vector<string> v2 = get_board();
	
	dfs(v1);

	if (reach.find(v2) != reach.end())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	cin.get(); cin.get();
	return 0;
}