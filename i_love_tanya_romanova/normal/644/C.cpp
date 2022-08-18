/*
Whiskey woman don't you know that you are drivin' me insane
The liquor you give stems your will to live and gets right to my brain
Don't you know you're driving me insane
You're tryin' to find your way through life
You're tryin' to get some new direction
Another woman's got her man
But she won't find no new connection

Takes another drink or two
Things look better when she's through

Take another look around, you're not goin' anywhere
Realized you're gettin' old and no one seems to care
You're tryin' to find your way again
You're tryin' to find some new
Another woman's got her man
But she won't find a new

Takes another drink or two
Things look better when she's through

You 'bin foolin' with some hot guy
I want to know why is it why
Get up get out you know you really blew it
I've had enough, I've had enough, good God pluck me

Once she was wonderful
Once she was fine
Once she was beautiful
Once she was mine (She was mine)

Now change has come over her body
She doesn't see me anymore
Now change has come over her body
She doesn't see me anymore

Changes, changes, changes, changes
Victim of changes

No, no, no, no
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

int n;
string st;
string pref;
int hashes;
vector<string> calls[N];
vector<int> ans;

string get_pref(string st)
{
	string temp = "";
	int cnt = 0;
	for (int i = 0; i < st.size(); i++)
	{
		if (st[i] == '/')
		{
			++cnt;
			if (cnt == 3)
				break;
		}
		temp += st[i];
	}
	return temp;
}

set<string> names_set;
map<string, int> names_map;
int servers;
string server_name[N];
int names;

void add_server(string st)
{
	++names;
	names_set.insert(st);
	names_map[st] = names;
	server_name[names] = st;
}
int get_id(string st)
{
	if (names_set.find(st) == names_set.end())
		add_server(st);
	return names_map[st];
}

set<long long> hash_set;
map<long long, int> hash_map;
vector<long long> hash_vec[N];

void add_new_hash(long long val)
{
	hash_set.insert(val);
	hash_map[val] = hash_set.size();
	++hashes;
}

void add_hash(long long val, int id)
{
	if (hash_set.find(val) == hash_set.end())
		add_new_hash(val);
	int num = hash_map[val];
	hash_vec[num].push_back(id);
}

long long get_hash(string st)
{
	long long val = 0; 
	for (int i = 0; i < st.size(); i++)
	{
		val = val * 173 + st[i];
		val %= bs;
	}
	for (int i = 0; i < st.size(); i++)
	{
		val = val * 137 + st[i];
	}
	return val;
}

long long get_hash(vector<string> v)
{
	long long res = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (i>0 && v[i] == v[i - 1])
			continue;
		res = (res * 137 + get_hash(v[i])) * 129 + 17;
	}
	return res;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> st;
		pref = get_pref(st);
		string temp = "";
		for (int j = pref.size(); j < st.size(); j++)
		{
			temp += st[j];
		}
		int id = get_id(pref);
///		cout << pref << " " << temp << endl;
		//cout << id << " " << temp << endl;
		calls[id].push_back(temp);
	}

	for (int i = 1; i <= names; i++)
	{
		sort(calls[i].begin(), calls[i].end());
	}

	for (int i = 1; i <= names; i++)
	{
		//if (calls[i].size() == 1)
		//	continue;
		/*for (int j = 0; j < calls[i].size(); j++)
		{
			cout << calls[i][j] <<" ";
		}
		cout << endl;
		*/
		long long P = get_hash(calls[i]);
	//	cout << "@" << P << "!" << i << endl;
		add_hash(P, i);
	}

//	cout << hashes << endl;

	for (int i = 1; i <= hashes; i++)
	{
		//cout << i << " " << hash_vec[i].size() << endl;
		if (hash_vec[i].size() == 1)
			continue;
		ans.push_back(i);
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		int id = ans[i];
		for (int j = 0; j < hash_vec[id].size(); j++)
		{
			if (j)
				cout << " ";
			int id2 = hash_vec[id][j];
			cout << server_name[id2];
		}
		cout << endl;
	}

	cin.get(); cin.get();
	return 0;
}