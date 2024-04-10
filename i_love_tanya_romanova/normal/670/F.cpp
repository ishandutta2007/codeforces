/*
One, a-one time, yeah

Am I too contagious
Full of sick desire
Am I that I promise
Burning corpsed pyre

Then some dude came down to touch the mother
Mother touched and dude ain't here no more
Suck your woman down

Am I your reflection
Melting mirror smile
Am I worth the value
Do my love defile

Then some dude came down to touch the mother
Mother touched and dude ain't here no more

Ain't no day the sun don't crack
Then to brand some name across my back so you care
Find someone to tell you

Sunshine
Sweet love my labor
Don't mind
I don't care no more

Memory, set me free, yeah
I don't care no more
Mother please, come for me, yeah

Can you face the question?
Is my soul entire?

Sunshine
Sweet love my labor
Don't mind
I don't care no more

Sunshine
Sweet love my labor
Don't mind
I don't care no more
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
const int N = 1110000;

string st;
string sub;
int cnt[20];

int get_len(int len)
{
	if (len < 10)
		return 1;
	return get_len(len / 10) + 1;
}

int cnt1[100];
string ans;
int cnt_sub[100];
int cnt2[100];
int actual[100];
int kind;
int TRIG;

void greedy(int len)
{
	string temp;
	if (sub[0] == '0'&&len > 1)
		return;
	for (int i = 0; i < 10; i++)
		actual[i] = cnt1[i];

	for (int i = 0; i < len; i++)
	{
		int dig = -1;
		for (int j = 0; j < 10; j++)
		{
			if (i < sub.size() && sub[i] != j + 48)
				continue;
			if (actual[j] == 0)
				continue;
			dig = j; break;
		}
		temp += char(dig + 48);
		actual[dig]--;
	}
	if (temp.size() < ans.size() || (temp.size() == ans.size() && temp < ans))
		ans = temp;
}

void try_build(int len)
{
	/*cout << ps_start << " " << len << endl;
	for (int i = 0; i < 10; i++)
	{
	cout << cnt1[i];
	}
	cout << endl;
	*/
	string temp;
	for (int i = 0; i < 10; i++)
	{
		actual[i] = cnt1[i];
	}
	int active = 0;
	int ps = 0;

	for (int i = 0; i < len; i++)
	{
		//cout << i << endl;
		int dig = -1;

		if (ps == sub.size())
			active = 2;

		if (active == 1)
		{
			temp += sub[ps];
			actual[sub[ps] - 48]--;
			ps++;
			if (ps == sub.size())
			{
				active = 2;
			}

			continue;
		}

		for (int j = 0; j < 10; j++)
		{
			if (i == 0 && j == 0)
				continue;
			if (actual[j] == 0)
				continue;
			if (active == 0 && actual[j] == cnt_sub[j] && j != sub[0] - 48)
				continue;
			dig = j;
			break;
		}
				//cout << i << "%" << dig << " "<<TRIG<<" "<<active<<" "<<kind<<" "<<cnt_sub[dig]<<" "<<actual[dig]<<endl;
		if (i != 0 && dig == sub[0] - 48 && active == 0 && (kind == 0 || cnt_sub[dig] == actual[dig]))
		{
			//cout << "!" << i << endl;
			active = 1;
			ps = 1;
			temp += sub[0];
			actual[sub[0] - 48]--;
			continue;
		}
		if (dig == -1) // some shit happened
			return;
		//cout << dig << endl;
		temp += char(dig + 48);
		actual[dig]--;
	}
//	cout << "%" << active << endl;
	for (int i = 0; i < 10; i++)
	{
		if (actual[i])
			return;
	}

	if (temp.size() < ans.size() || (temp.size() == ans.size() && temp < ans))
		ans = temp;
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> st;
	cin >> sub;

	ans = "1";
	for (int i = 1; i <= st.size() + 10; i++)
		ans += "1";


	if (st.size() == 2 && cnt[0] == 1 && cnt[1] == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i < sub.size(); i++)
	{
		if (sub[i] == sub[0])
			continue;
		if (sub[i]>sub[0])
			kind = 1;
		else
			kind = 0;
		break;
	}
	TRIG = kind + sub[0] - 48;

	for (int i = 0; i < st.size(); i++)
	{
		cnt[st[i] - '0']++;
	}
	for (int i = 0; i < sub.size(); i++)
	{
		cnt_sub[sub[i] - '0']++;
	}

	for (int len_len = 1; len_len <= 7; len_len++)
	{
		int rem_len = st.size();
		rem_len -= len_len;
		if (rem_len <= 0)
			continue;
		if (get_len(rem_len) != len_len)
			continue;
		for (int i = 0; i < 10; i++)
			cnt1[i] = cnt[i];
		int q = rem_len;
		while (q>0)
		{
			cnt1[q % 10]--;
			q /= 10;
		}
		int shit = 0;
		for (int i = 0; i < 10; i++)
		{
			if (cnt1[i] < 0)
				shit = 1;
		}
		if (shit)
			continue;
		for (int i = 0; i < 10; i++)
		{
			cnt2[i] = cnt1[i] - cnt_sub[i];
			if (cnt2[i] < 0)
				shit = 1;
		}
		if (shit)
			continue;
		try_build(rem_len);
		greedy(rem_len);

	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}