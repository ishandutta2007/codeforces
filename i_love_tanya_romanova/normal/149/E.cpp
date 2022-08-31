/*
I rest my eyes
On the open field
A silver line
To heavens gate
My mind is blank
It's a state I know
A sacred place
Where all I see is hate

I raise my head
To retain my wrath
The savage force
That lives inside of me
Foe to foe
One will die and one will be

And I pray she holds my soul
Can you hear me calling?

Silent goddess won't you
Conduct my fear away
Silent goddess won't you be
Closer when I hate

The battle cries
And the sound of steel
Another quest
For holy land
Some true belief
In each open wound
In Luna's light the lonely victor stands
And I pray she holds my soul
Can you hear me calling?

Silent goddess won't you
Conduct my fear away
Silent goddess won't you be
Closer when I hate
Silent goddess will you
Forever be the same
Silent goddess can you
Feel this heart pulsate

You know that I die for belief
I swear by the sword in my hand
The sum of the pain and the grief
Is nothing compared to the
Wealth I obtain
And the spirit of god can expand
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

const int N = 110000;

using namespace std;

string st;
string st2;
int tests;
int ans;

int z[N];
int pref[N];
int suf[N];

int solve(string st1, string st2)
{
	for (int i = 0; i <= st2.size(); i++)
		pref[i] = suf[i] = 1e9;

	for (int i = 0; i <= st1.size() + st2.size() + 5; i++)
		z[i] = 0;

	string S = st2 + "#" + st1;
	int n = S.size();
	for (int i = 1, l = 0, r = 0; i < n; i++)
	{
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n&&S[z[i]] == S[i + z[i]])
			++z[i];
		if (i + z[i] - 1>r)
			l = i, r = i + z[i] - 1;
	}
	int MX = 0;
	for (int i = st2.size(); i < n; i++)
	{
		if (z[i]>MX)
		{
			for (int j = MX + 1; j <= z[i]; j++)
			{
				pref[j] = i + j - st2.size()-1 ;
			}
			MX = z[i];
		}
	}
	/*
	cout << "@" << S << endl;
	for (int i = 0; i < S.size(); i++)
		cout << z[i] << " ";
	cout << endl;
	*/
	for (int i = 0; i <= st1.size() + st2.size() + 5; i++)
		z[i] = 0;

	reverse(st1.begin(), st1.end());
	reverse(st2.begin(), st2.end());
	S = st2 + "#" + st1;
	// cp
	for (int i = 1, l = 0, r = 0; i < n; i++)
	{
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n&&S[z[i]] == S[i + z[i]])
			++z[i];
		if (i + z[i] - 1>r)
			l = i, r = i + z[i] - 1;
	}
	/*
	cout << "@" << S << endl;
	for (int i = 0; i < S.size(); i++)
	cout << z[i] << " ";
	cout << endl;
	*/
	MX = 0;
	for (int i = st2.size(); i<n; i++)
	{
		if (z[i]>MX)
		{
			for (int j = MX + 1; j <= z[i]; j++)
			{
				suf[j] = i + j - st2.size() - 1;
			}
			MX = z[i];
		}
	}
	/*
	for (int i = 0; i < 10; i++)
	{
		cout << pref[i] << " " << suf[i] << endl;
	}
	*/

	for (int i = 1; i < st2.size(); i++)
	{
		if (pref[i] + suf[st2.size() - i] <= st1.size())
			return 1;
	}

	

	return 0;
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> st;
	
	cin >> tests;
	for (; tests; --tests)
	{
		string st2;
		cin >> st2;
		if (solve(st, st2))
			++ans;
	//	cout << ans << endl;
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}