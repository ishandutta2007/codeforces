/*
Now that you're gone, I can see what
Was going on and how you lied
When you'd said you'd never love again

Friends telephone and they say
You weren't out alone last night
Can't you see that this broken heart
Is killing me

Another night is falling
And now my heart is calling you back to me

[Chorus:]
Come back cause I need your love
Come back got to have your love
Come back bring your loving back to me
Come back cause it's been so long
Come back, and my love's still strong
Come back bring your loving back to me

You play with words play with love
It's just your silly way
I'm a fool cause I need you by my side again

Now it's too late you walk by
With another man
And I stand alone
Cause I know that you're not coming home

Another night is falling
And now my heart is calling you back to me

[Chorus]

Another night is falling
And now my heart is calling you back to me

[Chorus]
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
#define have adsgagshdshfhds

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 200031;

int n;
string st;
bool letter(char c)
{
	if (c >= 'a'&&c <= 'z')
		return true;
	if (c >= 'A'&&c <= 'Z')
		return true;
	return false;
}
int bal, cnt;
int ans, res;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	cin >> st;
	st = "_" + st + "_";

	for (int i = 0; i < st.size(); i++)
	{
		if (letter(st[i]))
		{
			++cnt;
		}
		else
		{
			if (bal == 0)
			{
				res = max(res, cnt);
			}
			else
			{
				if (cnt)
					++ans;
			}
			cnt = 0;

			if (st[i] == '(')
				++bal;
			if (st[i] == ')')
				--bal;
		}
	}
	cout << res << " " << ans << endl;

	cin.get(); cin.get();
	return 0;
}