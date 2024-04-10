/*
All the games you play
I won't take the blame
I gave you trust, you spit it out
And call my name
I'm taking back what's left from all these

Selfish things you say
And I won't waste another day
With all the games you play
All the games you play

And I'm so scared of all the ways
You take my confidence away
With all the games you play
All the selfish games you play

I'm alone again
Sure feels good to be home
As I walk away
I know you'll feel my pain
I'm taking back what's left from all these

Selfish things you say
And I won't waste another day
With all the games you play
All the games you play

And I'm so scared of all the ways
You take my confidence away
With all the games you play
All the selfish games you play

I don't know why and I don't know how
I let you control my inner self
As cold as you are, I'm counting the scars
They're proving to me just who you are

And now I know why
And now I know how
I'm better off without the

Selfish things you say
And I won't waste another day
With all the games you play
All the games you play

And I'm so scared of all the ways
You take my confidence away
With all the games you play
All the selfish games you play
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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 100031;

int n;
long long l;
int score[250];
string w[250];

vector<string> words;
set<string> wordset;
long long ar[250][250];
map<string, int> wordmap;

void add_word(string st)
{
	/*for (int i = 0; i < words.size(); i++)
	{
		if (words[i] == st)
			return;
	}*/
	words.push_back(st);
	wordset.insert(st);
	wordmap[st] = words.size() - 1;
}

vector<vector<long long> >mult(vector<vector<long long> > a,
	vector<vector<long long> > b)
{
	vector<vector<long long> > res;
	res = a;
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res.size(); j++)
		{
			res[i][j] = -4e18;
		}
	}
	for (int k = 0; k < res.size(); k++)
	{
		for (int i = 0; i < res.size(); i++)
		{
			for (int j = 0; j < res.size(); j++)
			{
				res[i][j] = max(res[i][j], a[i][k] + b[k][j]);
			}
		}
	}
	return res;
}

vector<vector<long long> > pw(vector<vector<long long> >a, long long b)
{
	if (b == 1)
		return a;
	if (b % 2)
		return mult(a, pw(a, b - 1));
	return pw(mult(a, a), b / 2);
}

long long total_cost[500];


bool good(string a, string b) //a contains b rev as suf
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (b.size() > a.size())
		return 0;
	for (int i = 0; i < b.size(); i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}

int get_move(string s)
{
	while (wordset.find(s) == wordset.end())
	{
		s.erase(s.begin());
	}
	return wordmap[s];
}

void show(vector<vector<long long> > v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> l;
	for (int i = 1; i <= n; i++)
	{
		cin >> score[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	
	vector<string> trash;
	trash.push_back("");

	for (int i = 1; i <= n; i++)
	{
		string here = "";
		for (int j = 0; j < w[i].size(); j++)
		{
			here += w[i][j];
			trash.push_back(here);
		}
	}

	sort(trash.begin(), trash.end());
	for (int i = 0; i < trash.size(); i++)
	{
		if (i == 0 || trash[i] != trash[i - 1])
			add_word(trash[i]);
	}

	for (int i = 0; i < words.size(); i++)
	{
		for (int j = 0; j < words.size(); j++)
		{
			ar[i][j] = -4e18;
		}
	}

	for (int i = 0; i < words.size(); i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (good(words[i], w[j]))
				total_cost[i] += score[j];
		}
	}

	for (int i = 0; i < words.size(); i++)
	{
		for (int ad = 0; ad < 26; ad++)
		{
			string temp = words[i];
			temp += char(ad + 'a');
			int new_id = get_move(temp);
			ar[i][new_id] = total_cost[new_id];
			//if (new_id>0)
			//	cout << i << "%" << new_id << " " << total_cost[new_id]<< endl;
		}
	}

	vector<vector<long long> > V;
	V.resize(words.size());
	for (int i = 0; i < V.size(); i++)
	{
		V[i].resize(words.size());
		for (int j = 0; j < V[i].size(); j++)
		{
			V[i][j] = ar[i][j];
		}
	}

	//show(V);

	V = pw(V, l);

	long long res = 0;
	for (int i = 0; i < V.size(); i++)
	{
		res = max(res, V[0][i]);
	}
	cout << res << endl;

	cin.get(); cin.get();
	return 0;
}